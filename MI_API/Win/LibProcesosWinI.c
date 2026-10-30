// LibProcesosWinI.c
#include <windows.h>
#include "LibProcesosWin.h"

Byte_t CrearProceso(
    PARAMETROS_DEL_PROCESO*  _PARAMETROS_ENTRADA_,
    INFORMACION_DEL_PROCESO* _INFORMACION_SALIDA_
) {
    #define dParams         (*_PARAMETROS_ENTRADA_)
    #define dInformacion    (*_INFORMACION_SALIDA_)
    if (_PARAMETROS_ENTRADA_ == NULL)
        return CrearProceso_Error_Estructura_Parametros_NULL;
    if (_INFORMACION_SALIDA_ == NULL)
        return CrearProceso_Error_Estructura_Informacion_NULL;

    char* dir_ejecutable    = NULL;
    char* linea_de_comandos = NULL;
    char* nombre_de_ventana = NULL;
    DWORD pos_y, pos_x, tam_y, tam_x;
        pos_y = 0;
        pos_x = 0;
        tam_y = 0;
        tam_x = 0;
    Bool_t pos_tam_predeterminado = No;
    Bool_t herencia_de_consola = No;
    Bool_t crear_ventana = No;

    if (dParams._DIRECCION_DEL_EJECUTABLE_ == NULL)
        return CrearProceso_Error_Direccion_NULL;
    else
        dir_ejecutable = dParams._DIRECCION_DEL_EJECUTABLE_;
    
    if (dParams._LINEA_DE_COMANDOS_ != NULL)
        linea_de_comandos = dParams._LINEA_DE_COMANDOS_;
    
    if (dParams.ACTIVAR_CONFIGURACION == Si) {
        
        if (dParams.Campo_configuracion.CREAR_VENTANA == Si) {
            crear_ventana = Si;
            if (dParams.Campo_configuracion.Campo_dimenciones_de_ventana.PREDETERMINADOS == Si) {
                pos_tam_predeterminado = Si;
            } else {
                pos_x = (DWORD)(dParams.Campo_configuracion.Campo_dimenciones_de_ventana._POS_EJE_X_);
                pos_y = (DWORD)(dParams.Campo_configuracion.Campo_dimenciones_de_ventana._POS_EJE_Y_);
                tam_x = (DWORD)(dParams.Campo_configuracion.Campo_dimenciones_de_ventana._TAM_EJE_X_);
                tam_y = (DWORD)(dParams.Campo_configuracion.Campo_dimenciones_de_ventana._TAM_EJE_Y_);
            }

            if (dParams.Campo_configuracion._NOMBRE_DE_LA_VENTANA_ != NULL)
                nombre_de_ventana = dParams.Campo_configuracion._NOMBRE_DE_LA_VENTANA_;
            else
                nombre_de_ventana = NULL;
        } else {
            if (dParams.Campo_configuracion.PERMITIR_HERENCIA_DE_CONSOLA == Si) {
                herencia_de_consola = Si;
            }
        }
    }

    WINBOOL Heredar = FALSE;
    STARTUPINFOA informacion_1 = {0};
    PROCESS_INFORMATION info_proceso = {0};
    informacion_1.cb = sizeof(STARTUPINFOA);


    SECURITY_ATTRIBUTES atributos = {0};
    atributos.nLength = sizeof(SECURITY_ATTRIBUTES);
    atributos.bInheritHandle = TRUE;
    HANDLE NoHeredar = CreateFileA(
        "NUL",
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        &atributos,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (NoHeredar == NULL || NoHeredar == INVALID_HANDLE_VALUE)
        return CrearProceso_Error_CreateFileA_MANEJADOR_Invalido;

    if (crear_ventana) {
        informacion_1.lpTitle = nombre_de_ventana;
        if (pos_tam_predeterminado == No) {
            informacion_1.dwFlags |= STARTF_USEPOSITION | STARTF_USESIZE;
            informacion_1.dwX = pos_x;
            informacion_1.dwY = pos_y;
            informacion_1.dwXSize = tam_x;
            informacion_1.dwYSize = tam_y;
        }
        Heredar = FALSE;
    } else if (
        herencia_de_consola 
        &&
        (
            dParams.Campo_configuracion.Campo_herencias.HEREDAR_CONSOLA_ERROR  == Si ||
            dParams.Campo_configuracion.Campo_herencias.HEREDAR_CONSOLA_INPUT  == Si ||
            dParams.Campo_configuracion.Campo_herencias.HEREDAR_CONSOLA_OUTPUT == Si
        )
    ) {
        informacion_1.dwFlags |= STARTF_USESTDHANDLES;
        
        if (dParams.Campo_configuracion.Campo_herencias.HEREDAR_CONSOLA_ERROR == Si) {
            HANDLE hError = GetStdHandle(STD_ERROR_HANDLE);
            if (hError == NULL || hError == INVALID_HANDLE_VALUE) {
                CloseHandle(NoHeredar);
                return CrearProceso_Error_GetStdHandle_Configurar_Herencia_stdErr;
            }
            
            informacion_1.hStdError = hError;
        } else {
            informacion_1.hStdError = NoHeredar;
        }

        if (dParams.Campo_configuracion.Campo_herencias.HEREDAR_CONSOLA_INPUT == Si) {
            HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
            if (hInput == NULL || hInput == INVALID_HANDLE_VALUE) {
                CloseHandle(NoHeredar);
                return CrearProceso_Error_GetStdHandle_Configurar_Herencia_stdIn;
            }
            
            informacion_1.hStdInput = hInput;
        } else {
            informacion_1.hStdInput = NoHeredar;
        }

        if (dParams.Campo_configuracion.Campo_herencias.HEREDAR_CONSOLA_OUTPUT == Si) {
            HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOutput == NULL || hOutput == INVALID_HANDLE_VALUE) {
                CloseHandle(NoHeredar);
                return CrearProceso_Error_GetStdHandle_Configurar_Herencia_stdOut;
            }
            
            informacion_1.hStdOutput = hOutput;
        } else {
            informacion_1.hStdOutput = NoHeredar;
        }
        Heredar = TRUE;
    } else {
        informacion_1.dwFlags |= STARTF_USESTDHANDLES;
        informacion_1.hStdError = NoHeredar;
        informacion_1.hStdInput = NoHeredar;
        informacion_1.hStdOutput = NoHeredar;
        Heredar = TRUE;
    }


    WINBOOL exito = CreateProcessA(
        dir_ejecutable,
        linea_de_comandos,
        NULL,
        NULL,
        Heredar,
        0,
        NULL,
        NULL,
        &informacion_1,
        &info_proceso
    );
    
    // TODO: terminar lo último que falta en esta sección y los servicios a Windows.

    CloseHandle(NoHeredar);

    if (exito == FALSE) {
        dInformacion.PROCESO_ID = 0;
        dInformacion.HILO_ID = 0;
        dInformacion.Campo_manejadores.MANEJADOR_DEL_PROCESO = NULL;
        dInformacion.Campo_manejadores.MANEJADOR_DEL_HILO = NULL;
        return CrearProceso_Error_CreateProcessA;
    } else {
        dInformacion.PROCESO_ID = info_proceso.dwProcessId; 
        dInformacion.HILO_ID    = info_proceso.dwThreadId;
        dInformacion.Campo_manejadores.MANEJADOR_DEL_PROCESO = info_proceso.hProcess;
        dInformacion.Campo_manejadores.MANEJADOR_DEL_HILO    = info_proceso.hThread;
        return 0;
    }

    #undef dParams
    #undef dInformacion
}
