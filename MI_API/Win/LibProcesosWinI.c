// LibProcesosWinI.c
#include <windows.h>
#include "LibProcesosWin.h"

Byte_t CrearProceso(
    PARAMETROS_DEL_PROCESO*  PARAMETROS_ENTRADA,
    INFORMACION_DEL_PROCESO* INFORMACION_SALIDA
) {
    #define dParams         (*PARAMETROS_ENTRADA)
    #define dInformacion    (*INFORMACION_SALIDA)
    if (PARAMETROS_ENTRADA == NULL)
        return CrearProceso_Error_Estructura_Parametros_NULL;
    if (INFORMACION_SALIDA == NULL)
        return CrearProceso_Error_Estructura_Informacion_NULL;

    char* dir_ejecutable    = NULL;
    char* linea_de_comandos = NULL;
    char* nombre_de_ventana = NULL;
    Uint_t pos_y, pos_x, tam_y, tam_x;
        pos_y = 0;
        pos_x = 0;
        tam_y = 0;
        tam_x = 0;
    Bool_t pos_tam_predeterminado = No;


    if (dParams.DIRECCION_DEL_EJECUTABLE == NULL)
        return CrearProceso_Error_Direccion_NULL;
    else
        dir_ejecutable = dParams.DIRECCION_DEL_EJECUTABLE;
    
    if (dParams.LINEA_DE_COMANDOS != NULL)
        linea_de_comandos = dParams.LINEA_DE_COMANDOS;
    
    if (dParams.ACTIVAR_CONFIGURACION == Si) {
        Bool_t crear_ventana = No;
        if (dParams.Campo_configuracion.CREAR_VENTANA == Si) {
            crear_ventana = Si;
            if (dParams.Campo_configuracion.Campo_dimenciones_de_ventana.PREDETERMINADOS == Si) {
                pos_tam_predeterminado = Si;
            } else {
                pos_x = dParams.Campo_configuracion.Campo_dimenciones_de_ventana.POS_EJE_X;
                pos_y = dParams.Campo_configuracion.Campo_dimenciones_de_ventana.POS_EJE_Y;
                tam_x = dParams.Campo_configuracion.Campo_dimenciones_de_ventana.TAM_EJE_X;
                tam_y = dParams.Campo_configuracion.Campo_dimenciones_de_ventana.TAM_EJE_Y;
            }
        }

        if (crear_ventana != No) {
            if (dParams.Campo_configuracion.NOMBRAR_VENTANA == Si) {
                if (dParams.Campo_configuracion.NOMBRE_DE_LA_VENTANA != NULL)
                    nombre_de_ventana = dParams.Campo_configuracion.NOMBRE_DE_LA_VENTANA;
            }
        }
    }

    

    return 0;
    #undef dParams
    #undef dInformacion
}
