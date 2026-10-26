// LibpWinImplem.c

//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
// incluciones

#include "LibpWin.h"
#include <windows.h>

/*
CP_ACP	        0	    Página de códigos ANSI predeterminada de Windows.
CP_OEMCP	    1	    Página de códigos OEM predeterminada.
CP_MACCP	    2	    Página de códigos de Macintosh, para compatibilidad heredada.
CP_THREAD_ACP	3	    Página ANSI predeterminada asociada al subproceso actual.
CP_SYMBOL	    42	    Página de códigos de símbolos.
CP_UTF7	        65000	Codificación UTF-7, heredada y desaconsejada para usos nuevos.
CP_UTF8
*/

//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//
//
//
//
//
//
//
//
//
//
//
//
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
// código compatible tanto para Windows como Linux:

Byte_t SacarDirectorioActual(
    char*  __UBICACION_ACTUAL_DE_ESTE_ARCHIVO__entrada,
    char*  __UBICACION_MODIFICADA__resultado,
    size_t __LONGITUD_DEL_BUFFER_DE_RESULTADO__,
    Bool_t __DEJAR_BARRA_INVERTIDA__
) {
    if (
        __UBICACION_ACTUAL_DE_ESTE_ARCHIVO__entrada   == NULL ||
        __UBICACION_MODIFICADA__resultado             == NULL
    )
        return SacarDirectorioActual_Error_Punteros_NULLs;

    if (__DEJAR_BARRA_INVERTIDA__ == 0)
        __DEJAR_BARRA_INVERTIDA__ = No;
    size_t i_r = 0;

    {
        size_t i_e = 0;

        while (__UBICACION_ACTUAL_DE_ESTE_ARCHIVO__entrada[i_e] != 0x00)
            i_e++;

        if (i_e >= __LONGITUD_DEL_BUFFER_DE_RESULTADO__)
            return SacarDirectorioActual_Error_Longitud_Corta;

        while (__UBICACION_ACTUAL_DE_ESTE_ARCHIVO__entrada[i_r] != 0x00) {
            __UBICACION_MODIFICADA__resultado[i_r] = __UBICACION_ACTUAL_DE_ESTE_ARCHIVO__entrada[i_r];
            i_r++;
        }
        __UBICACION_MODIFICADA__resultado[i_r] = 0x00;
    }

    while (i_r != 0) {
        if (__UBICACION_MODIFICADA__resultado[i_r] == '\\') {
            if (__DEJAR_BARRA_INVERTIDA__ == No)
                __UBICACION_MODIFICADA__resultado[i_r] = 0x00;

            break;
        } else {
            __UBICACION_MODIFICADA__resultado[i_r] = 0x00;
        }
        i_r--;
    }

    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t LimpiarBuffer(
    Byte_t*     _ESTRUCTURA_,
    size_t      _CANTIDAD_DE_BYTES_
) {
    if (_ESTRUCTURA_ == NULL)
        return GENERAL_Error_Puntero_NULL;

    size_t i = 0;
    while (i < _CANTIDAD_DE_BYTES_) {
        _ESTRUCTURA_[i] = 0x00;
        i++;
    }

    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t TipoReprDeSignos() {
    signed char _referencia_ = -5;
    Byte_t* interno = (Byte_t*)&_referencia_;

    if ((Byte_t)(*interno) == 0b10000101)
        return _SIGNO_Y_MAGNITUD_;
    else if ((Byte_t)(*interno) == 0b11111010)
        return _COMPLEMENTO_UNO_;
    else
        return _COMPLEMENTO_DOS_;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t CopiarBuffer(
    void* BUFFER_ORIGEN,
    void* BUFFER_DESTINO,
    size_t LONGITUD_DEL_BUFFER_ORIGEN,
    size_t LONGITUD_DEL_BUFFER_DESTINO
) {
    if (
        BUFFER_DESTINO == NULL ||
        BUFFER_ORIGEN  == NULL
    ) return CopiarBuffer_Error_Punteros_Buffers_NULLs;

    if (
        LONGITUD_DEL_BUFFER_DESTINO == 0 ||
        LONGITUD_DEL_BUFFER_ORIGEN  == 0
    ) return CopiarBuffer_Error_Longitudes_Buffers_Cero;

    if (BUFFER_DESTINO != BUFFER_ORIGEN) {
        uintptr_t Origen  = (uintptr_t)BUFFER_ORIGEN;
        uintptr_t Destino = (uintptr_t)BUFFER_DESTINO;
        //==========================================================\ 
        if (Origen > Destino) 
            if ((Destino + LONGITUD_DEL_BUFFER_DESTINO) > Origen)
                return CopiarBuffer_Error_Solapamiento_Buffers_Destino_Origen;
        else
            if ((Origen + LONGITUD_DEL_BUFFER_ORIGEN) > Destino)
                return CopiarBuffer_Error_Solapamiento_Buffers_Origen_Destino;
        //==========================================================/
    } else return CopiarBuffer_Error_Mismos_Punteros_Origen_Destino;

    size_t i = 0;
    while (
        i < LONGITUD_DEL_BUFFER_DESTINO &&
        i < LONGITUD_DEL_BUFFER_ORIGEN
    ) {
        *(((Byte_t*)BUFFER_DESTINO) + i) = *(((Byte_t*)BUFFER_ORIGEN) + i);
        i++;
    }

    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t ComprobarListaDeTexto(
    COMPROBACION_PARAMs* PARAMETROS
) {
    #define dParams (*PARAMETROS)
    if (PARAMETROS == NULL)
        return ComprobarListaDeTexto_Error_Estructura_NULL;
    if (dParams.Campo_datos_de_entrada._LISTA_DE_TEXTO_C_ == NULL)
        return ComprobarListaDeTexto_Error_Puntero_De_Lista_De_Texto_C_NULL;
    if (dParams.Campo_datos_de_entrada._LONGITUD_DE_LA_LISTA_ == 0)
        return ComprobarListaDeTexto_Error_Longitud_Cero;

    Bool_t Guardar_cantidad = Si;
    if (dParams.Campo_datos_de_salida._LISTA_DE_SIZEs__GUARDADO_DE_INDICES_ == NULL)
        Guardar_cantidad = No;

    if (Guardar_cantidad) {
        if (dParams.Campo_datos_de_salida._CANTIDAD_DE_SIZEs_ == 0)
            return ComprobarListaDeTexto_Error_Cantidad_De_Sizes_Cero;
    }

    const char* lista_de_texto_c    = dParams.Campo_datos_de_entrada._LISTA_DE_TEXTO_C_;
    size_t  longitud_de_datos_ent   = dParams.Campo_datos_de_entrada._LONGITUD_DE_LA_LISTA_;
    size_t* lista_de_sizes          = NULL;
    size_t  cantidad_de_sizes       = 0;
    if (Guardar_cantidad) {
        lista_de_sizes     = dParams.Campo_datos_de_salida._LISTA_DE_SIZEs__GUARDADO_DE_INDICES_;
        cantidad_de_sizes  = dParams.Campo_datos_de_salida._CANTIDAD_DE_SIZEs_;
    }
    enum PASOS {
        NADA,
        TEXTO_C,
        CARACTER_CERO,
        TERMINO
    };

    Byte_t ETAPAS = NADA;
    Byte_t CARACTER = 0;
    size_t i = 0;
    size_t sizes_i = 0;

    while (i < longitud_de_datos_ent) {
        CARACTER = (Byte_t)(lista_de_texto_c[i]);

        if (ETAPAS == NADA) {
            if (CARACTER == '\0')
                return ComprobarListaDeTexto_Error_Inicio_Con_Cero;
            ETAPAS = TEXTO_C;
            if (Guardar_cantidad) {
                if (sizes_i >= cantidad_de_sizes)
                    return ComprobarListaDeTexto_Error_Lista_Sizes_Insuficientes;
                lista_de_sizes[sizes_i] = i;
                sizes_i += 1;
            }
            continue;
        } else if (ETAPAS == TEXTO_C) {
            if (CARACTER == '\0')
                ETAPAS = CARACTER_CERO;

        } else if (ETAPAS == CARACTER_CERO) {
            if (CARACTER == '\0') {
                ETAPAS = TERMINO;
                break;
            }
            ETAPAS = TEXTO_C;
            if (Guardar_cantidad) {
                if (sizes_i >= cantidad_de_sizes)
                    return ComprobarListaDeTexto_Error_Lista_Sizes_Insuficientes;
                lista_de_sizes[sizes_i] = i;
                sizes_i += 1;
            }
            continue;
        }

        i++;
    }
    if (ETAPAS == CARACTER_CERO)
        return ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP1;
    else if (ETAPAS == TEXTO_C)
        return ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP2;
    else if (ETAPAS == CARACTER_CERO)
        return ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP3;

    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


void ImprimirTipoTecla(
    Byte_t TECLA_ESPECIAL_A_IMPRIMIR
) {
    switch (TECLA_ESPECIAL_A_IMPRIMIR)
    {
        case TECLA_CARACTER     :       Imprimir("CARACTER", NULL);       break; 
        case TECLA_CONTROL_DE   :       Imprimir("CONTROL_DE", NULL);     break;
        case TECLA_CONTROL_IZ   :       Imprimir("CONTROL_IZ", NULL);     break;
        case TECLA_CONTROL      :       Imprimir("CONTROL", NULL);        break;
        case TECLA_ALT_DE       :       Imprimir("ALT_DE", NULL);         break;
        case TECLA_ALT_IZ       :       Imprimir("ALT_IZ", NULL);         break;
        case TECLA_ALT          :       Imprimir("ALT", NULL);            break;
        case TECLA_OS_DE        :       Imprimir("OS_DE", NULL);          break;
        case TECLA_OS_IZ        :       Imprimir("OS_IZ", NULL);          break;
        case TECLA_OS           :       Imprimir("OS", NULL);             break;
        case TECLA_SHIFT_DE     :       Imprimir("SHIFT_DE", NULL);       break;
        case TECLA_SHIFT_IZ     :       Imprimir("SHIFT_IZ", NULL);       break;
        case TECLA_SHIFT        :       Imprimir("SHIFT", NULL);          break;
        case TECLA_ESCAPE       :       Imprimir("ESCAPE", NULL);         break;
        case TECLA_TAB          :       Imprimir("TAB", NULL);            break;
        case TECLA_BACKSPACE    :       Imprimir("BACKSPACE", NULL);      break;
        case TECLA_ENTER        :       Imprimir("ENTER", NULL);          break;
        case TECLA_SUPRIMIR     :       Imprimir("SUPRIMIR", NULL);       break;
        case TECLA_INSERTAR     :       Imprimir("INSERTAR", NULL);       break;
        case TECLA_FLECHA_ARRIBA:       Imprimir("FLECHA_ARRIBA", NULL);  break;
        case TECLA_FLECHA_ABAJO :       Imprimir("FLECHA_ABAJO", NULL);   break;
        case TECLA_FLECHA_IZ    :       Imprimir("FLECHA_IZ", NULL);      break;
        case TECLA_FLECHA_DE    :       Imprimir("FLECHA_DE", NULL);      break;
        case TECLA_INICIO       :       Imprimir("INICIO", NULL);         break;
        case TECLA_FIN          :       Imprimir("FIN", NULL);            break;
        case TECLA_PAG_ARRIBA   :       Imprimir("PAG_ARRIBA", NULL);     break;
        case TECLA_PAG_ABAJO    :       Imprimir("PAG_ABAJO", NULL);      break;
        case TECLA_F1       :   Imprimir("F1", NULL);     break;
        case TECLA_F2       :   Imprimir("F2", NULL);     break;
        case TECLA_F3       :   Imprimir("F3", NULL);     break;
        case TECLA_F4       :   Imprimir("F4", NULL);     break;
        case TECLA_F5       :   Imprimir("F5", NULL);     break;
        case TECLA_F6       :   Imprimir("F6", NULL);     break;
        case TECLA_F7       :   Imprimir("F7", NULL);     break;
        case TECLA_F8       :   Imprimir("F8", NULL);     break;
        case TECLA_F9       :   Imprimir("F9", NULL);     break;
        case TECLA_F10      :   Imprimir("F10", NULL);    break;
        case TECLA_F11      :   Imprimir("F11", NULL);    break;
        case TECLA_F12      :   Imprimir("F12", NULL);    break;
        case TECLA_F13      :   Imprimir("F13", NULL);    break;
        case TECLA_F14      :   Imprimir("F14", NULL);    break;
        case TECLA_F15      :   Imprimir("F15", NULL);    break;
        case TECLA_F16      :   Imprimir("F16", NULL);    break;
        case TECLA_F17      :   Imprimir("F17", NULL);    break;
        case TECLA_F18      :   Imprimir("F18", NULL);    break;
        case TECLA_F19      :   Imprimir("F19", NULL);    break;
        case TECLA_F20      :   Imprimir("F20", NULL);    break;
        case TECLA_F21      :   Imprimir("F21", NULL);    break;
        case TECLA_F22      :   Imprimir("F22", NULL);    break;
        case TECLA_F23      :   Imprimir("F23", NULL);    break;
        case TECLA_F24      :   Imprimir("F24", NULL);    break;
        default:
            Imprimir("TECLA_INDETERMINADA", NULL); break; 
    }
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


void ImprimirMensajeDeError(
    void*  _PUNTERO_DE_RETORNO_O_DE_CODIGO_DE_ERROR_,
    Byte_t _FUNCION_ESPECIFICA_DEL_ERROR_
) {
    #define ptrRet  (_PUNTERO_DE_RETORNO_O_DE_CODIGO_DE_ERROR_)
    #define ptrRetDes(TIPO_DESREFERENCIA)   (*((TIPO_DESREFERENCIA*)(_PUNTERO_DE_RETORNO_O_DE_CODIGO_DE_ERROR_)))
    #define Especif_Funcion (_FUNCION_ESPECIFICA_DEL_ERROR_)

    Escribir("Error : ", 8, NULL, CONSOLA_ERROR);

    if (_FUNCION_ESPECIFICA_DEL_ERROR_ == 0) {
        Imprimir(
            "NO_ESPECIFICO : NO_DATOS : %uint",
            _PUNTERO_DE_RETORNO_O_DE_CODIGO_DE_ERROR_
        );
    } else {
        switch (Especif_Funcion) {

            //==============================================================
            // SacarDirectorioActual
            //==============================================================
            case Especif_SacarDirectorioActual:
                switch (ptrRetDes(Byte_t)) {

                    case SacarDirectorioActual_Error_Punteros_NULLs:
                        Escribir(
                            "SacarDirectorioActual :\n\t"
                            "Uno o ambos parametros punteros buffer a char es NULL",
                            78, NULL, CONSOLA_ERROR
                        );
                    break;

                    case SacarDirectorioActual_Error_Longitud_Corta:
                        Escribir(
                            "SacarDirectorioActual :\n\t"
                            "Longitud corta del buffer de resultado",
                            63, NULL, CONSOLA_ERROR
                        );
                    break;
                }
            break;

            //==============================================================
            // LimpiarBuffer
            //==============================================================
            case Especif_LimpiarBuffer:
                switch (ptrRetDes(Byte_t)) {

                    case LimpiarBuffer_Error_Puntero_NULL:
                        Escribir(
                            "LimpiarBuffer :\n\t"
                            "El parametro de puntero buffer Byte_t es NULL",
                            62, NULL, CONSOLA_ERROR
                        );
                    break;
                }
            break;

            //==============================================================
            // CopiarBuffer
            //==============================================================
            case Especif_CopiarBuffer:
                switch (ptrRetDes(Byte_t)) {

                    case CopiarBuffer_Error_Punteros_Buffers_NULLs:
                        Escribir(
                            "CopiarBuffer :\n\t"
                            "Uno o ambos parametros de punteros buffer void es NULL",
                            70, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CopiarBuffer_Error_Longitudes_Buffers_Cero:
                        Escribir(
                            "CopiarBuffer :\n\t"
                            "Uno o ambos parametros de longitudes de buffers es cero",
                            71, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CopiarBuffer_Error_Solapamiento_Buffers_Destino_Origen:
                        Escribir(
                            "CopiarBuffer :\n\t"
                            "Hay solapamiento de memoria de los buffers Destino sobre Origen",
                            79, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CopiarBuffer_Error_Solapamiento_Buffers_Origen_Destino:
                        Escribir(
                            "CopiarBuffer :\n\t"
                            "Hay solapamiento de memoria de los buffers Origen sobre Destino",
                            79, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CopiarBuffer_Error_Mismos_Punteros_Origen_Destino:
                        Escribir(
                            "CopiarBuffer :\n\t"
                            "Ambos parametros de punteros buffer void son iguales",
                            68, NULL, CONSOLA_ERROR
                        );
                    break;
                }
            break;

            //==============================================================
            // ComprobarListaDeTexto
            //==============================================================
            case Especif_ComprobarListaDeTexto:
                switch (ptrRetDes(Byte_t)) {

                    case ComprobarListaDeTexto_Error_Estructura_NULL:
                        Escribir(
                            "ComprobarListaDeTexto :\n\t"
                            "El parametro de puntero a COMPROBACION_PARAMs es NULL",
                            79, NULL, CONSOLA_ERROR
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Longitud_Cero:
                        Escribir(
                            "ComprobarListaDeTexto :\n\t"
                            "En el Campo_datos_de_entrada :\n\t\t"
                            "La longitud del buffer es cero",
                            88, NULL, CONSOLA_ERROR
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Inicio_Con_Cero:
                        Escribir(
                            "ComprobarListaDeTexto :\n\t"
                            "La lista de texto compienza con cero: \\000",
                            67, NULL, CONSOLA_ERROR
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP1:
                        Escribir(
                            "ComprobarListaDeTexto :\n\t"
                            "No se pudo analizar toda la estructura: Etapa en enum:NADA",
                            83, NULL, CONSOLA_ERROR
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP2:
                        Escribir(
                            "ComprobarListaDeTexto :\n\t"
                            "No se pudo analizar toda la estructura: Etapa en enum:TEXTO_C",
                            86, NULL, CONSOLA_ERROR
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP3:
                        Escribir(
                            "ComprobarListaDeTexto :\n\t"
                            "No se pudo analizar toda la estructura: Etapa en enum:CARACTER_CERO",
                            92, NULL, CONSOLA_ERROR
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Puntero_De_Lista_De_Texto_C_NULL:
                        Escribir(
                            "ComprobarListaDeTexto :\n\t"
                            "En el Campo_datos_de_entrada :\n\t\t"
                            "El puntero buffer char es NULL",
                            88, NULL, CONSOLA_ERROR
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Cantidad_De_Sizes_Cero:
                        Escribir(
                            "ComprobarListaDeTexto :\n\t"
                            "En el Campo_salida :\n\t\t"
                            "La cantidad de Sizes proporcionada es cero",
                            90, NULL, CONSOLA_ERROR
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Lista_Sizes_Insuficientes:
                        Escribir(
                            "ComprobarListaDeTexto :\n\t"
                            "En el Campo_datos_de_salida :\n\t\t"
                            "Hay menos Sizes que cantidad de elememtos en la lista",
                            111, NULL, CONSOLA_ERROR
                        );
                    break;
                }
            break;

            //==============================================================
            // CapturarTeclaUTF8
            //==============================================================
            case Especif_CapturarTeclaUTF8:
                switch (ptrRetDes(Byte_t)) {

                    case CapturarTeclaUTF8_Error_Puntero_NULL:
                        Escribir(
                            "CapturarTeclaUTF8 :\n\t"
                            "El parametros de puntero de EVENTO_TECLA es NULL",
                            69, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CapturarTeclaUTF8_Error_ReadConsoleInputW:
                        Escribir(
                            "CapturarTeclaUTF8 :\n\t"
                            "Error API windows.h\n\t|       ReadConsoleInputW",
                            67, NULL, CONSOLA_ERROR
                        );    
                    break;

                    case CapturarTeclaUTF8_Error_Escritos_Cero:
                        Escribir(
                            "CapturarTeclaUTF8 :\n\t"
                            "La cantidad escrita de byte a _Caracter_UNICODE_ es cero",
                            77, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__Sin_KeyEvent:
                        Escribir(
                            "CapturarTeclaUTF8 :\n\t"
                            "Lectura de par suplente :\n\t\tSin KeyEvent",
                            60, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__KeyDown_Falso:
                        Escribir(
                            "CapturarTeclaUTF8 :\n\t"
                            "Lectura de par suplente :\n\t\tKeyDown Falso",
                            61, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__Suplente_No_Correspondiente:
                        Escribir(
                            "CapturarTeclaUTF8 :\n\t"
                            "Lectura de par suplente :\n\t\tSuplente no correspondiente",
                            75, NULL, CONSOLA_ERROR
                        );
                    break;
                }
            break;
            //==============================================================
            // CambiarCodigoDePagina
            //==============================================================
            case Especif_CambiarCodigoDePagina:
                Escribir(
                    "CambiarCodigoDePagina :\n\t",
                    25, NULL, CONSOLA_ERROR
                );
                switch (ptrRetDes(Byte_t)) {
                    case CambiarCodigoDePagina_Error_Parametro_CodPag_Invalido:
                        Escribir(
                            "El codigo de pagina seleccionado no es reconocido",
                            49, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CambiarCodigoDePagina_Error_Parametro_Consola_Invalido:
                        Escribir(
                            "La consola seleccionada no es reconocida",
                            40, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_SetConsoleOutputCP:
                        Escribir(
                            "En Consola Output :\n\t\t"
                            "Error API windows.h\n\t\t"
                            "|       SetConsoleOutputCP",
                            70, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CambiarCodigoDePagina_Error_CONSOLA_INPUT_SetConsoleCP:
                        Escribir(
                            "En Consola Input :\n\t\t"
                            "Error API windows.h\n\t\t"
                            "|       SetConsoleCP",
                            63, NULL, CONSOLA_ERROR
                        );
                    break;

                    case CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleOutputCP:
                    case CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleCP:
                        Escribir(
                            "En Consola Output y Input :\n\t\t"
                            "Error API windows.h\n\t\t",
                            52, NULL, CONSOLA_ERROR
                        );
                        Escribir ("|       SetConsoleOutputCP: ", 28, NULL, CONSOLA_ERROR);
                        if (ptrRetDes(Byte_t) == CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleOutputCP) {
                            Escribir("ERR", 3, NULL, CONSOLA_ERROR);
                            break;
                        } else Escribir("OK\n\t\t", 5, NULL, CONSOLA_ERROR);

                        Escribir(
                            "|       SetConsoleCP: ERR\n\t\t"
                            "Estado de consola incompleto.\n\t\t"
                            "Falta configurar CONSOLA_INPUT.", 
                            91, NULL, CONSOLA_ERROR
                        );
                    
                    break;
                }
            break;
            //==============================================================
            // LimpiarConsola
            //==============================================================
            case Especif_LimpiarConsola:
                switch (ptrRetDes(Byte_t)) {

                    case LimpiarConsola_Error_Parametro_Invalido:
                        Escribir(
                            "LimpiarConsola :\n\t"
                            "El parametro de especificacion de consola es invalido o incorrecto",
                            84, NULL, CONSOLA_ERROR
                        );
                    break;

                    case LimpiarConsola_Error_stdOut_Sin_Consola:
                        Escribir(
                            "LimpiarConsola :\n\t"
                            "stdOut sin consola para limpiar",
                            49, NULL, CONSOLA_ERROR
                        );
                    break;

                    case LimpiarConsola_Error_stdErr_Sin_Consola:
                        Escribir(
                            "LimpiarConsola :\n\t"
                            "stdErr sin consola para limpiar",
                            49, NULL, CONSOLA_ERROR
                        );
                    break;

                    case LimpiarConsola_Error_GetStdHandle_stdIn:
                        Escribir(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetStdHandle en stdIn",
                            68, NULL, CONSOLA_ERROR
                        );
                    break;

                    case LimpiarConsola_Error_stdIn_Sin_Consola:
                        Escribir(
                            "LimpiarConsola :\n\t"
                            "stdIn sin consola para limpiar",
                            48, NULL, CONSOLA_ERROR
                        );
                    break;

                    case LimpiarConsola_Error_FlushConsoleInputBuffer_stdIn:
                        Escribir(
                            "Error API windows.h\n\t"
                            "|       FlushConsoleInputBuffer en stdIn",
                            52, NULL, CONSOLA_ERROR
                        );
                    break;

                    case LimpiarConsola_Error_GetStdHandle_stdOut:
                    case LimpiarConsola_Error_GetStdHandle_stdErr:
                        Escribir(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetStdHandle",
                            59, NULL, CONSOLA_ERROR
                        );
                    break;

                    case LimpiarConsola_Error_GetConsoleScreemBufferInfo_stdOut:
                    case LimpiarConsola_Error_GetConsoleScreemBufferInfo_stdErr:
                        Escribir(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetConsoleScreemBufferInfo",
                            73, NULL, CONSOLA_ERROR
                        );
                    break;

                    case LimpiarConsola_Error_FillConsoleCharacterA_stdOut:
                    case LimpiarConsola_Error_FillConsoleCharacterA_stdErr:
                        Escribir(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       FillConsoleOutputCharacterA",
                            74, NULL, CONSOLA_ERROR
                        );
                    break;

                    case LimpiarConsola_Error_FillConsoleAttribute_stdOut:
                    case LimpiarConsola_Error_FillConsoleAttribute_stdErr:
                        Escribir(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       FillConsoleOutputAttribute",
                            73, NULL, CONSOLA_ERROR
                        );
                    break;

                    case LimpiarConsola_Error_SetCursor_stdOut:
                    case LimpiarConsola_Error_SetCursor_stdErr:
                        Escribir(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       SetConsoleCursorPosition",
                            71, NULL, CONSOLA_ERROR
                        );
                    break;

                }
                if (
                    (ptrRetDes(Byte_t) != LimpiarConsola_Error_Parametro_Invalido)  &&
                    (ptrRetDes(Byte_t) != LimpiarConsola_Error_stdOut_Sin_Consola)  &&
                    (ptrRetDes(Byte_t) != LimpiarConsola_Error_stdErr_Sin_Consola)  &&
                    (ptrRetDes(Byte_t) != LimpiarConsola_Error_GetStdHandle_stdIn)  &&
                    (ptrRetDes(Byte_t) != LimpiarConsola_Error_stdIn_Sin_Consola)   &&
                    (ptrRetDes(Byte_t) != LimpiarConsola_Error_FlushConsoleInputBuffer_stdIn)
                ) {
                    if (!!(ptrRetDes(Byte_t)&0x0f)) {
                        /*STDOUT*/
                        Escribir(
                            " en stdOut",
                            10, NULL, CONSOLA_ERROR
                        );
                    } else {
                        /*STDERR*/
                        Escribir(
                            " en stdErr",
                            10, NULL, CONSOLA_ERROR
                        );
                    }
                }
            break;

            //==============================================================
            // Entrada
            //==============================================================
            case Especif_Entrada:
                switch (ptrRetDes(Byte_t)) {

                    case Entrada_Error_Puntero_Estructura_NULL:
                        Escribir(
                            "Entrada :\n\t"
                            "El parametro de puntero ENTRADA_PARAMs es NULL",
                            57, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Entrada_Error_Puntero_BufferEntrada_NULL:
                        Escribir(
                            "Entrada :\n\t"
                            "En ENTRADA_PARAMs :\n\t\t"
                            "El puntero al buffer de entrada es NULL",
                            72, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Entrada_Error_LongitudBuffer_Menor_A_Dos:
                        Escribir(
                            "Entrada :\n\t"
                            "En ENTRADA_PARAMs :\n\t\t"
                            "La longitud del buffer proporcionada es menor a 2 bytes",
                            88, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Entrada_Error_Lista_De_Mensajes:
                        Escribir(
                            "Entrada :\n\t"
                            "La lista de mensajes proporcionada es invalida o incorrecta (ComprobarListaDeTexto)",
                            94, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Entrada_Error_CapturarTeclaUTF8:
                        Escribir(
                            "Entrada :\n\t"
                            "Error en CapturarTeclaUTF8",
                            37, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Entrada_ErrorNOFATAL_Salida_Por_Tecla_Especial:
                        Escribir(
                            "NOFATAL : Entrada :\n\t"
                            "Interrupcion por tecla especial",
                            53, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Entrada_Error_LimpiarConsola:
                        Escribir(
                            "Entrada :\n\t"
                            "Error en LimpiarConsola",
                            34, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Entrada_Error_GetConsoleCP:
                        Escribir(
                            "Entrada :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetConsoleCP",
                            52, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Entrada_Error_GetConsoleOutputCP:
                        Escribir(
                            "Entrada :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetConsoleOutPutCP",
                            58, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Entrada_Error_SetConsoleCP:
                        Escribir(
                            "Entrada :\n\t"
                            "Error API windows.h\n\t"
                            "|       SetConsoleCP",
                            52, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Entrada_Error_SetConsoleOutputCP:
                        Escribir(
                            "Entrada :\n\t"
                            "Error API windows.h\n\t"
                            "|       SetConsoleOutputCP", 
                            58, NULL, CONSOLA_ERROR
                        );
                    break;
                }
            break;

            //==============================================================
            // Escribir
            //==============================================================
            case Especif_Escribir:
                switch (ptrRetDes(Byte_t)) {

                    case Escribir_Error_Param_Invalido:
                        Escribir(
                            "Escribir :\n\t"
                            "El parametro de especificacion de consola es invalido",
                            65, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Escribir_Error_Puntero_NULL:
                        Escribir(
                            "Escribir :\n\t"
                            "El parametro de puntero buffer const char es NULL",
                            61, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Escribir_ErrorNOFATAL_Escritos_No_Iguales:
                        Escribir(
                            "NOFATAL : Escribir :\n\t"
                            "La cantidad escritura realizada no es igual al proporcionado",
                            82, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Escribir_Error_GetStdHandle:
                        Escribir(
                            "Escribir :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetStdHandle",
                            53, NULL, CONSOLA_ERROR
                        );
                    break;

                    case Escribir_Error_WriteFile:
                        Escribir(
                            "Escribir :\n\t"
                            "Error API windows.h\n\t"
                            "|       WriteFile",
                            50, NULL, CONSOLA_ERROR
                        );
                    break;
                }
            break;

            default:
                Imprimir(
                    "NO_ESPECIFICO : NO_DATOS : %uint",
                    _PUNTERO_DE_RETORNO_O_DE_CODIGO_DE_ERROR_
                );
            break;
        }
    }

    #undef ptrRet
    #undef ptrRetDes
    #undef Especif
}



//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//
//
//
//
//
//
//
//
//
//
//
//
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
// funciones de contrato Win/Linux



Byte_t CapturarTeclaUTF8(
    EVENTO_TECLA* INFORMACION_DE_LA_TECLA
) {
    #define dtecla (*tecla)
    #define dinfo   (*INFORMACION_DE_LA_TECLA)

    if (INFORMACION_DE_LA_TECLA == NULL)
        return GENERAL_Error_Puntero_NULL;

    LimpiarBuffer(
        (Byte_t*)(dinfo._CARACTER_UNICODE_),
        4
    );
    dinfo.BYTES_ESCRITOS = 0;
    dinfo.TIPO_DE_EVENTO = 0;
    dinfo.Campo_Teclas_modificadoras.HUBO_MODIFICADORES = 0;

    //Implementación para Windows
    DWORD cantidad_leidos = 0;
    HANDLE consola_de_entrada = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD evento = {0};

    KEY_EVENT_RECORD* tecla = NULL;

    while (1) {
        if (
            ReadConsoleInputW(
                consola_de_entrada,
                &evento,
                1,
                &cantidad_leidos
            ) == FALSE
        ) return CapturarTeclaUTF8_Error_ReadConsoleInputW;

        if (evento.EventType == KEY_EVENT) {
            tecla = &(evento.Event.KeyEvent);

            if (dtecla.bKeyDown == TRUE) {
                switch (dtecla.wVirtualKeyCode)
                {
                    case VK_CONTROL:
                        dinfo.TIPO_DE_EVENTO = TECLA_CONTROL; break;
                    case VK_LCONTROL:
                        dinfo.IZQUIERDA_O_DERECHA = IZQUIERDA;
                        dinfo.TIPO_DE_EVENTO = TECLA_CONTROL; break;
                    case VK_RCONTROL:
                        dinfo.IZQUIERDA_O_DERECHA = DERECHA;
                        dinfo.TIPO_DE_EVENTO = TECLA_CONTROL; break;

                    case VK_MENU:
                        dinfo.TIPO_DE_EVENTO = TECLA_ALT; break;
                    case VK_LMENU:
                        dinfo.IZQUIERDA_O_DERECHA = IZQUIERDA;
                        dinfo.TIPO_DE_EVENTO = TECLA_ALT; break;
                    case VK_RMENU:
                        dinfo.IZQUIERDA_O_DERECHA = DERECHA;
                        dinfo.TIPO_DE_EVENTO = TECLA_ALT; break;

                    case VK_LWIN:
                        dinfo.IZQUIERDA_O_DERECHA = IZQUIERDA;
                        dinfo.TIPO_DE_EVENTO = TECLA_OS; break;
                    case VK_RWIN:
                        dinfo.IZQUIERDA_O_DERECHA = DERECHA;
                        dinfo.TIPO_DE_EVENTO = TECLA_OS; break;

                    case VK_SHIFT:
                        dinfo.TIPO_DE_EVENTO = TECLA_SHIFT; break;
                    case VK_LSHIFT:
                        dinfo.IZQUIERDA_O_DERECHA = IZQUIERDA;
                        dinfo.TIPO_DE_EVENTO = TECLA_SHIFT; break;
                    case VK_RSHIFT:
                        dinfo.IZQUIERDA_O_DERECHA = DERECHA;
                        dinfo.TIPO_DE_EVENTO = TECLA_SHIFT; break;

                    default:
                        dinfo.IZQUIERDA_O_DERECHA = 0;
                        switch (dtecla.wVirtualKeyCode)
                        {
                            case VK_ESCAPE: dinfo.TIPO_DE_EVENTO = TECLA_ESCAPE; break;
                            case VK_TAB:    dinfo.TIPO_DE_EVENTO = TECLA_TAB; break;
                            case VK_BACK:   dinfo.TIPO_DE_EVENTO = TECLA_BACKSPACE; break;
                            case VK_RETURN: dinfo.TIPO_DE_EVENTO = TECLA_ENTER; break;
                            case VK_DELETE: dinfo.TIPO_DE_EVENTO = TECLA_SUPRIMIR; break;
                            case VK_INSERT: dinfo.TIPO_DE_EVENTO = TECLA_INSERTAR; break;
                            case VK_UP:     dinfo.TIPO_DE_EVENTO = TECLA_FLECHA_ARRIBA; break;
                            case VK_DOWN:   dinfo.TIPO_DE_EVENTO = TECLA_FLECHA_ABAJO; break;
                            case VK_LEFT:   dinfo.TIPO_DE_EVENTO = TECLA_FLECHA_IZ; break;
                            case VK_RIGHT:  dinfo.TIPO_DE_EVENTO = TECLA_FLECHA_DE; break;
                            case VK_HOME:   dinfo.TIPO_DE_EVENTO = TECLA_INICIO; break;
                            case VK_END:    dinfo.TIPO_DE_EVENTO = TECLA_FIN; break;
                            case VK_PRIOR:  dinfo.TIPO_DE_EVENTO = TECLA_PAG_ARRIBA; break;
                            case VK_NEXT:   dinfo.TIPO_DE_EVENTO = TECLA_PAG_ABAJO; break;
                            case VK_F1: dinfo.TIPO_DE_EVENTO = TECLA_F1; break;
                            case VK_F2: dinfo.TIPO_DE_EVENTO = TECLA_F2; break;
                            case VK_F3: dinfo.TIPO_DE_EVENTO = TECLA_F3; break;
                            case VK_F4: dinfo.TIPO_DE_EVENTO = TECLA_F4; break;
                            case VK_F5: dinfo.TIPO_DE_EVENTO = TECLA_F5; break;
                            case VK_F6: dinfo.TIPO_DE_EVENTO = TECLA_F6; break;
                            case VK_F7: dinfo.TIPO_DE_EVENTO = TECLA_F7; break;
                            case VK_F8: dinfo.TIPO_DE_EVENTO = TECLA_F8; break;
                            case VK_F9: dinfo.TIPO_DE_EVENTO = TECLA_F9; break;
                            case VK_F10: dinfo.TIPO_DE_EVENTO = TECLA_F10; break;
                            case VK_F11: dinfo.TIPO_DE_EVENTO = TECLA_F11; break;
                            case VK_F12: dinfo.TIPO_DE_EVENTO = TECLA_F12; break;
                            case VK_F13: dinfo.TIPO_DE_EVENTO = TECLA_F13; break;
                            case VK_F14: dinfo.TIPO_DE_EVENTO = TECLA_F14; break;
                            case VK_F15: dinfo.TIPO_DE_EVENTO = TECLA_F15; break;
                            case VK_F16: dinfo.TIPO_DE_EVENTO = TECLA_F16; break;
                            case VK_F17: dinfo.TIPO_DE_EVENTO = TECLA_F17; break;
                            case VK_F18: dinfo.TIPO_DE_EVENTO = TECLA_F18; break;
                            case VK_F19: dinfo.TIPO_DE_EVENTO = TECLA_F19; break;
                            case VK_F20: dinfo.TIPO_DE_EVENTO = TECLA_F20; break;
                            case VK_F21: dinfo.TIPO_DE_EVENTO = TECLA_F21; break;
                            case VK_F22: dinfo.TIPO_DE_EVENTO = TECLA_F22; break;
                            case VK_F23: dinfo.TIPO_DE_EVENTO = TECLA_F23; break;
                            case VK_F24: dinfo.TIPO_DE_EVENTO = TECLA_F24; break;
                            default:     dinfo.TIPO_DE_EVENTO = TECLA_INDETERMINADA; break;
                        }
                }

                if (dtecla.uChar.UnicodeChar != L'\0') {
                    // produjo caracter Unicode.
                    Byte_t cantidad_de_bytes_escritos = 0;
                    Bool_t se_necesita_dos_WCHAR = No;
                    WCHAR par = dtecla.uChar.UnicodeChar;
                    WCHAR Caracter_UTF16[2] = {0};

                    Caracter_UTF16[0] = par;

                    if (par >= 0xd800 && par <= 0xdbff) {
                        se_necesita_dos_WCHAR = Si;

                        if (
                            ReadConsoleInputW(
                                consola_de_entrada,
                                &evento,
                                1,
                                &cantidad_leidos
                            ) == FALSE
                        ) return 0x02;

                        if (evento.EventType == KEY_EVENT) {
                            tecla = &(evento.Event.KeyEvent);

                            if (dtecla.bKeyDown == TRUE) {
                                par = dtecla.uChar.UnicodeChar;

                                if (par >= 0xdc00 && par <= 0xdfff)
                                    Caracter_UTF16[1] = par;
                                else
                                    return CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__Suplente_No_Correspondiente; 
                            } else
                                return CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__KeyDown_Falso;
                        } else
                            return CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__Sin_KeyEvent;
                    }

                    if (se_necesita_dos_WCHAR == Si) {
                        cantidad_de_bytes_escritos = (Byte_t)WideCharToMultiByte(
                            CP_UTF8,
                            0,
                            Caracter_UTF16,
                            2,
                            dinfo._CARACTER_UNICODE_,
                            4,
                            NULL,
                            NULL
                        );
                    } else {
                        cantidad_de_bytes_escritos = (Byte_t)WideCharToMultiByte(
                            CP_UTF8,
                            0,
                            Caracter_UTF16,
                            1,
                            dinfo._CARACTER_UNICODE_,
                            4,
                            NULL,
                            NULL
                        );
                    }

                    if (cantidad_de_bytes_escritos == 0)
                        return CapturarTeclaUTF8_Error_Escritos_Cero;
                    else
                        dinfo.BYTES_ESCRITOS = cantidad_de_bytes_escritos;

                    if (dinfo.TIPO_DE_EVENTO == TECLA_INDETERMINADA)
                        dinfo.TIPO_DE_EVENTO = TECLA_CARACTER;
                }

                if (dtecla.dwControlKeyState != 0) {
                    DWORD estado = dtecla.dwControlKeyState;
                    if (estado & RIGHT_ALT_PRESSED)
                        dinfo.Campo_Teclas_modificadoras.ALT_DERECHA         |= ALT_DE_PRESIONADO;
                    if (estado & LEFT_ALT_PRESSED)
                        dinfo.Campo_Teclas_modificadoras.ALT_IZQUIERDA       |= ALT_IZ_PRESIONADO;
                    if (estado & RIGHT_CTRL_PRESSED)
                        dinfo.Campo_Teclas_modificadoras.CTRL_DERECHA        |= CONTROL_DE_PRESIONADO;
                    if (estado & LEFT_CTRL_PRESSED)
                        dinfo.Campo_Teclas_modificadoras.CTRL_IZQUIERDA      |= CONTROL_IZ_PRESIONADO;
                    if (estado & SHIFT_PRESSED)
                        dinfo.Campo_Teclas_modificadoras.SHIFT               |= SHIFT_PRESIONADO;
                    if (estado & NUMLOCK_ON)
                        dinfo.Campo_Teclas_modificadoras.NUM_LOCK_ACTIVO     |= NUMLOCK_ACTVO;
                    if (estado & CAPSLOCK_ON)
                        dinfo.Campo_Teclas_modificadoras.MAYUS_ACTIVO        |= MAYUS_ACTVO;
                    if (estado & SCROLLLOCK_ON)
                        dinfo.Campo_Teclas_modificadoras.SCROLL_LOCK_ACTIVO  |= SCROLL_LOCK_ACTVO;
                } else
                    dinfo.Campo_Teclas_modificadoras.HUBO_MODIFICADORES = No;
                break;

            } else continue;
        }
    }

    #undef dtecla
    #undef dinfo
    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t CambiarCodigoDePagina(
    Byte_t _CODIGO_DE_PAGINA_,
    Byte_t _CONSOLA_A_CAMBIAR_
) {
    UINT CodPag = 0;

    switch (_CODIGO_DE_PAGINA_)
    {
        case CodPag_ANSI_SubProceso : CodPag = CP_THREAD_ACP;   break;
        case CodPag_ANSI_Predet     : CodPag = CP_ACP;          break;
        case CodPag_OEM_Predet      : CodPag = CP_OEMCP;        break;
        case CodPag_Macintosh       : CodPag = CP_MACCP;        break;
        case CodPag_Simbolos        : CodPag = CP_SYMBOL;       break;
        case CodPag_UTF7            : CodPag = CP_UTF7;         break;
        case CodPag_UTF8            : CodPag = CP_UTF8;         break;

        default:
            return CambiarCodigoDePagina_Error_Parametro_CodPag_Invalido;
    }

    if (_CONSOLA_A_CAMBIAR_ == CONSOLA_OUTPUT) {
        if (SetConsoleOutputCP(CodPag) == FALSE)
            return CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_SetConsoleOutputCP;
    } else if (_CONSOLA_A_CAMBIAR_ == CONSOLA_INPUT) {
        if (SetConsoleCP(CodPag) == FALSE)
            return CambiarCodigoDePagina_Error_CONSOLA_INPUT_SetConsoleCP;
    } else if (_CONSOLA_A_CAMBIAR_ == CONSOLA_OUTPUT_INPUT) {
        if (SetConsoleOutputCP(CodPag) == FALSE)
            return CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleOutputCP;
        if (SetConsoleCP(CodPag) == FALSE)
            return CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleCP;
    } else
        return CambiarCodigoDePagina_Error_Parametro_Consola_Invalido;
    
    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t LimpiarConsola(
    Byte_t CONSOLA_A_LIMPIAR
) {
    //implementacio de Windows
    HANDLE Entrada_Estandar = NULL;
    HANDLE Salida_Estandar  = NULL;
    HANDLE Error_Estandar   = NULL;

    if (CONSOLA_A_LIMPIAR == CONSOLA_INPUT) {
        Entrada_Estandar = GetStdHandle(STD_INPUT_HANDLE);
        if (
            Entrada_Estandar == INVALID_HANDLE_VALUE ||
            Entrada_Estandar == NULL
        ) return LimpiarConsola_Error_GetStdHandle_stdIn;
        {
            DWORD modo = 0;
            if (GetConsoleMode(Entrada_Estandar, &modo) == FALSE)
                return LimpiarConsola_Error_stdIn_Sin_Consola;
        }

        if (FlushConsoleInputBuffer(Entrada_Estandar) == FALSE)
            return LimpiarConsola_Error_FlushConsoleInputBuffer_stdIn;
        
    } else if (CONSOLA_A_LIMPIAR == CONSOLA_OUTPUT) {
        Salida_Estandar = GetStdHandle(STD_OUTPUT_HANDLE);
        if (
            Salida_Estandar == INVALID_HANDLE_VALUE ||
            Salida_Estandar == NULL
        ) return LimpiarConsola_Error_GetStdHandle_stdOut;
        {
            DWORD Modo = 0;
            if (GetConsoleMode(Salida_Estandar, &Modo) == FALSE)
                return LimpiarConsola_Error_stdOut_Sin_Consola;
        }

        CONSOLE_SCREEN_BUFFER_INFO informacion_buffer_consola = {0};
        DWORD cantidad = 0;
        COORD inicio = {0, 0};

        if (GetConsoleScreenBufferInfo(Salida_Estandar, &informacion_buffer_consola) == FALSE)
            return LimpiarConsola_Error_GetConsoleScreemBufferInfo_stdOut;

        DWORD Area_total = ((DWORD)informacion_buffer_consola.dwSize.Y) * ((DWORD)informacion_buffer_consola.dwSize.X);

        if (FillConsoleOutputCharacterA(
            Salida_Estandar,
            ' ',
            Area_total,
            inicio,
            &cantidad
        ) == FALSE) return LimpiarConsola_Error_FillConsoleCharacterA_stdOut;

        if (FillConsoleOutputAttribute(
            Salida_Estandar,
            informacion_buffer_consola.wAttributes,
            Area_total,
            inicio,
            &cantidad
        ) == FALSE) return LimpiarConsola_Error_FillConsoleAttribute_stdOut;

        if (SetConsoleCursorPosition(
            Salida_Estandar,
            inicio
        ) == FALSE) return LimpiarConsola_Error_SetCursor_stdOut;

    } else if (CONSOLA_A_LIMPIAR == CONSOLA_ERROR) {
        Error_Estandar  = GetStdHandle(STD_ERROR_HANDLE);
        if (
            Error_Estandar == INVALID_HANDLE_VALUE ||
            Error_Estandar == NULL
        ) return LimpiarConsola_Error_GetStdHandle_stdErr;
        {
            DWORD Modo = 0;
            if (GetConsoleMode(Error_Estandar, &Modo) == FALSE)
                return LimpiarConsola_Error_stdErr_Sin_Consola;
        }

        CONSOLE_SCREEN_BUFFER_INFO informacion_buffer_consola = {0};
        DWORD cantidad = 0;
        COORD inicio = {0, 0};

        if (GetConsoleScreenBufferInfo(Error_Estandar, &informacion_buffer_consola) == FALSE)
            return LimpiarConsola_Error_GetConsoleScreemBufferInfo_stdErr;

        DWORD Area_total = ((DWORD)informacion_buffer_consola.dwSize.Y) * ((DWORD)informacion_buffer_consola.dwSize.X);

        if (FillConsoleOutputCharacterA(
            Error_Estandar,
            ' ',
            Area_total,
            inicio,
            &cantidad
        ) == FALSE) return LimpiarConsola_Error_FillConsoleCharacterA_stdErr;

        if (FillConsoleOutputAttribute(
            Error_Estandar,
            informacion_buffer_consola.wAttributes,
            Area_total,
            inicio,
            &cantidad
        ) == FALSE) return LimpiarConsola_Error_FillConsoleAttribute_stdErr;

        if (SetConsoleCursorPosition(
            Error_Estandar,
            inicio
        ) == FALSE) return LimpiarConsola_Error_SetCursor_stdErr;

    } else return LimpiarConsola_Error_Parametro_Invalido;


    return 0;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t Entrada(
    ENTRADA_PARAMs* _CONFIGURACIONES_Y_PARAMETROS_
) {

    #define dConfParams (*_CONFIGURACIONES_Y_PARAMETROS_)
    #define BIT_0       0x01
    #define BIT_1       0X02
    #define BIT_2       0x04
    #define BIT_3       0x08

    ///////////configuramos salida y entrada:
    UINT entrada_antes;
    UINT salida_antes;
    if ((entrada_antes = GetConsoleCP()) == 0)
        return Entrada_Error_GetConsoleCP;
    if ((salida_antes = GetConsoleOutputCP()) == 0)
        return Entrada_Error_GetConsoleOutputCP;

    if (SetConsoleCP(CP_UTF8) == FALSE) {
        SetConsoleCP(entrada_antes);
        return Entrada_Error_SetConsoleCP;
    }
    if (SetConsoleOutputCP(CP_UTF8) == FALSE) {
        SetConsoleCP(entrada_antes);
        SetConsoleOutputCP(salida_antes);
        return Entrada_Error_SetConsoleOutputCP;
    }

    if (_CONFIGURACIONES_Y_PARAMETROS_ == NULL)
        return GENERAL_Error_Puntero_NULL;
    ///////////////////////////

    if (dConfParams._PUNTERO_BUFFER_DE_ENTRADA_ == NULL) {
        SetConsoleCP(entrada_antes);
        SetConsoleOutputCP(salida_antes);
        return Entrada_Error_Puntero_BufferEntrada_NULL;
    }

    char* buffer = dConfParams._PUNTERO_BUFFER_DE_ENTRADA_;

    if (dConfParams._LONGITUD_DEL_BUFFER_ < 2) {
        SetConsoleCP(entrada_antes);
        SetConsoleOutputCP(salida_antes);
        return Entrada_Error_LongitudBuffer_Menor_A_Dos;
    }

    size_t longitud = dConfParams._LONGITUD_DEL_BUFFER_;

    if (dConfParams._PERMITIR_CONFIGURACION_ == Si) {

        Bool_t prompt_predeterminado    = No;
        Bool_t mostrar_indicador        = No;
        Bool_t mostrar_prompt           = No;
        Bool_t usar_salida_especial     = No;
        Bool_t indicar_metodo_de_salida = No;
        Bool_t mostrar_mensaje          = No;
        const char* mensaje_de_usuario  = NULL;
        const char* prompt_de_usuario   = NULL;
        Byte_t metodo = 0;

        if (
            dConfParams.Campo_Configuracion.MOSTRAR_INDICADOR_DE_LONGITUD_USADA
        ) mostrar_indicador = Si;

        if (
            dConfParams.Campo_Configuracion.MOSTRAR_PROMPT_DE_ENTRADA
        ) mostrar_prompt = Si;

        if (mostrar_prompt == Si) {
            if (dConfParams.Campo_Configuracion._PROMPT_DE_ENTRADA_TEXTO_C_ == NULL)
                prompt_predeterminado = Si;
            else
                prompt_de_usuario = dConfParams.Campo_Configuracion._PROMPT_DE_ENTRADA_TEXTO_C_;
        }

        if (
            dConfParams.Campo_Configuracion.Campo_Avanzados.MOSTRAR_LISTA_DE_MENSAJES_ANTES_DE_LA_ENTRADA
        ) mostrar_mensaje = Si;

        if (mostrar_mensaje) {
            if (dConfParams.Campo_Configuracion.Campo_Avanzados._LISTA_DE_MENSAJES_ == NULL)
                mostrar_mensaje = No;
            else
                mensaje_de_usuario = dConfParams.Campo_Configuracion.Campo_Avanzados._LISTA_DE_MENSAJES_;

            COMPROBACION_PARAMs parametros = {0};
            parametros.Campo_datos_de_entrada._LISTA_DE_TEXTO_C_ = mensaje_de_usuario;
            parametros.Campo_datos_de_entrada._LONGITUD_DE_LA_LISTA_ = dConfParams.Campo_Configuracion.Campo_Avanzados._LONGITUD_DE_LA_LISTA_;
            if (ComprobarListaDeTexto(&parametros) != 0) {
                SetConsoleCP(entrada_antes);
                SetConsoleOutputCP(salida_antes);
                return Entrada_Error_Lista_De_Mensajes;
            }
        }

        if (
            dConfParams.Campo_Configuracion.Campo_Avanzados.USAR_METODO_DE_SALIDA_CON_TECLA_ESPECIAL
        ) usar_salida_especial = Si;

        if (
            (dConfParams.Campo_Configuracion.Campo_Avanzados.TECLA_ESPECIAL_DE_SALIDA)
            !=
            TECLA_CARACTER
            &&
            (dConfParams.Campo_Configuracion.Campo_Avanzados.TECLA_ESPECIAL_DE_SALIDA)
            !=
            0
        ) metodo = dConfParams.Campo_Configuracion.Campo_Avanzados.TECLA_ESPECIAL_DE_SALIDA;
        else metodo = TECLA_TAB;

        if (
            dConfParams.Campo_Configuracion.Campo_Avanzados.INDICAR_METODO_DE_SALIDA_AL_USUARIO
        ) indicar_metodo_de_salida = Si;


        EVENTO_TECLA evento = {0};
        size_t i = 0;
        if (mostrar_indicador) {
            while (1) {
                if (LimpiarConsola(CONSOLA_OUTPUT) != 0) {
                    SetConsoleCP(entrada_antes);
                    SetConsoleOutputCP(salida_antes);
                    return Entrada_Error_LimpiarConsola;
                }

                if (mostrar_mensaje) {
                    size_t iterador = 0;
                    while (1) {
                        if (mensaje_de_usuario[iterador] != '\0')
                            Escribir(
                                &(mensaje_de_usuario[iterador]),
                                1,
                                NULL,
                                CONSOLA_OUTPUT
                            );
                        else if (mensaje_de_usuario[iterador+1] == '\0')
                            break;
                        iterador++;
                    }
                }

                if (indicar_metodo_de_salida) {
                    Imprimir("[", NULL);
                    ImprimirTipoTecla(metodo);
                    Imprimir("]: salir\n", NULL);
                }

                Imprimir("límite [", NULL);
                Imprimir("%int/", &i);
                Imprimir("%int]\n", &longitud);

                if (mostrar_prompt) {
                    if (prompt_predeterminado)
                        Imprimir(">>> ", NULL);
                    else
                        Imprimir("%s", (void*)prompt_de_usuario);
                }

                Imprimir("%s", (void*)buffer);

                do {
                    if (CapturarTeclaUTF8(&evento) != 0) {
                        SetConsoleCP(entrada_antes);
                        SetConsoleOutputCP(salida_antes);
                        return Entrada_Error_CapturarTeclaUTF8;
                    }

                    if (usar_salida_especial) {
                        if (evento.TIPO_DE_EVENTO == metodo) {
                            SetConsoleCP(entrada_antes);
                            SetConsoleOutputCP(salida_antes);
                            return Entrada_ErrorNOFATAL_Salida_Por_Tecla_Especial;
                        }
                    }
                } while (
                    evento.TIPO_DE_EVENTO != TECLA_CARACTER  &&
                    evento.TIPO_DE_EVENTO != TECLA_ENTER     &&
                    evento.TIPO_DE_EVENTO != TECLA_BACKSPACE
                );

                if (
                    evento.TIPO_DE_EVENTO == TECLA_BACKSPACE ||
                    (evento._CARACTER_UNICODE_)[0] == '\b' 
                ) {
                    if (i > 0) {
                        while (1) {
                            if ((buffer[i-1] & 0xC0) == 0x80) {
                                i--;
                                buffer[i] = 0x00;
                            } else {
                                i--;
                                buffer[i] = 0x00;
                                break;
                            }
                        }
                    }
                } else if (
                    evento.TIPO_DE_EVENTO == TECLA_ENTER    ||
                    (evento._CARACTER_UNICODE_)[0] == '\n'  ||
                    (evento._CARACTER_UNICODE_)[0] == '\r'
                ) {
                    break;
                } else {
                    if ((i + evento.BYTES_ESCRITOS) < longitud) {
                        Byte_t escritos = 0;
                        while (escritos < evento.BYTES_ESCRITOS) {
                            buffer[i] = (evento._CARACTER_UNICODE_[escritos]);
                            escritos++;
                            i++;
                        }
                        buffer[i] = 0x00;
                    }
                }

            }

        } else {
            if (mostrar_mensaje) {
                size_t iterador = 0;
                while (1) {
                    if (mensaje_de_usuario[iterador] != '\0')
                        Escribir(
                            &(mensaje_de_usuario[iterador]),
                            1,
                            NULL,
                            CONSOLA_OUTPUT
                        );
                    else if (mensaje_de_usuario[iterador+1] == '\0')
                        break;
                    iterador++;
                }
            }

            if (indicar_metodo_de_salida) {
                Imprimir("[", NULL);
                ImprimirTipoTecla(metodo);
                Imprimir("]: salir\n", NULL);
            }
            if (mostrar_prompt) {
                if (prompt_predeterminado)
                    Imprimir(">>> ", NULL);
                else
                    Imprimir("%s", (void*)prompt_de_usuario);
            }
            while (1) {

                do {
                    if (CapturarTeclaUTF8(&evento) != 0) {
                        SetConsoleCP(entrada_antes);
                        SetConsoleOutputCP(salida_antes);
                        return Entrada_Error_CapturarTeclaUTF8;
                    }

                    if (usar_salida_especial) {
                        if (evento.TIPO_DE_EVENTO == metodo) {
                            SetConsoleCP(entrada_antes);
                            SetConsoleOutputCP(salida_antes);
                            return Entrada_ErrorNOFATAL_Salida_Por_Tecla_Especial;
                        }
                    }
                } while (
                    evento.TIPO_DE_EVENTO != TECLA_CARACTER  &&
                    evento.TIPO_DE_EVENTO != TECLA_ENTER     &&
                    evento.TIPO_DE_EVENTO != TECLA_BACKSPACE
                );

                if (
                    evento.TIPO_DE_EVENTO == TECLA_BACKSPACE ||
                    (evento._CARACTER_UNICODE_)[0] == '\b' 
                ) {
                    if (i > 0) {
                        while (1) {
                            if ((buffer[i-1] & 0xC0) == 0x80) {
                                i--;
                                buffer[i] = 0x00;
                            } else {
                                i--;
                                buffer[i] = 0x00;
                                break;
                            }
                        }
                        Imprimir("\b \b", NULL);
                    }
                } else if (
                    evento.TIPO_DE_EVENTO == TECLA_ENTER    ||
                    (evento._CARACTER_UNICODE_)[0] == '\n'  ||
                    (evento._CARACTER_UNICODE_)[0] == '\r'
                ) {
                    break;
                } else {
                    if ((i + evento.BYTES_ESCRITOS) < longitud) {
                        Byte_t escritos = 0;
                        while (escritos < evento.BYTES_ESCRITOS) {
                            buffer[i] = (evento._CARACTER_UNICODE_[escritos]);
                            escritos++;
                            i++;
                        }
                        buffer[i] = 0x00;
                        Imprimir("%s", (void*)((buffer+i)-escritos));
                    }
                }

            } 
        }

    } else { /********************************************************/
        // Estandar de la función.
        EVENTO_TECLA evento = {0};
        size_t i = 0;

        while (1) {

            do {
                if (CapturarTeclaUTF8(&evento) != 0) {
                    SetConsoleCP(entrada_antes);
                    SetConsoleOutputCP(salida_antes);
                    return Entrada_Error_CapturarTeclaUTF8;
                }
            } while (
                evento.TIPO_DE_EVENTO != TECLA_CARACTER  &&
                evento.TIPO_DE_EVENTO != TECLA_ENTER     &&
                evento.TIPO_DE_EVENTO != TECLA_BACKSPACE
            );

            if (
                evento.TIPO_DE_EVENTO == TECLA_BACKSPACE ||
                (evento._CARACTER_UNICODE_)[0] == '\b' 
            ) {
                if (i > 0) {
                    while (1) {
                        if ((buffer[i-1] & 0xC0) == 0x80) {
                            i--;
                            buffer[i] = 0x00;
                        } else {
                            i--;
                            buffer[i] = 0x00;
                            break;
                        }
                    }
                    Imprimir("\b \b", NULL);
                }
            } else if (
                evento.TIPO_DE_EVENTO == TECLA_ENTER    ||
                (evento._CARACTER_UNICODE_)[0] == '\n'  ||
                (evento._CARACTER_UNICODE_)[0] == '\r'
            ) {
                break;
            } else {
                if ((i + evento.BYTES_ESCRITOS) < longitud) {
                    Byte_t escritos = 0;
                    while (escritos < evento.BYTES_ESCRITOS) {
                        buffer[i] = (evento._CARACTER_UNICODE_[escritos]);
                        escritos++;
                        i++;
                    }
                    buffer[i] = 0x00;
                    Imprimir("%s", (void*)((buffer+i)-escritos));
                }
            }

        } 
    } //>>>> >>>> >>>> >>>> aquí termina el ELSE <<<< <<<< <<<< <<<<//

    if (SetConsoleCP(entrada_antes) == FALSE) {
        SetConsoleOutputCP(salida_antes);
        return Entrada_Error_SetConsoleCP;
    }
    if (SetConsoleOutputCP(salida_antes) == FALSE)
        return Entrada_Error_SetConsoleOutputCP;

    #undef BIT_0
    #undef BIT_1
    #undef BIT_2
    #undef BIT_3
    #undef dConfParams

    return 0x00;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Byte_t Escribir(
    const char*   _BUFFER_DE_TEXTO_C_,
    size_t  _CANTIDAD_DE_BYTES_A_ESCRIBIR_,
    Sint_t* _CANTIDAD_DE_BYTES_ESCRITOS_,
    Byte_t  _CONSOLA_OUTPUT_O_ERROR_
) {
    if (_BUFFER_DE_TEXTO_C_ == NULL)
        return GENERAL_Error_Puntero_NULL;

    Byte_t retorno = 0;

    DWORD escritos = 0;
    HANDLE consola;
    if (_CONSOLA_OUTPUT_O_ERROR_ == CONSOLA_OUTPUT)
        consola = GetStdHandle(STD_OUTPUT_HANDLE);
    else if (_CONSOLA_OUTPUT_O_ERROR_ == CONSOLA_ERROR)
        consola = GetStdHandle(STD_ERROR_HANDLE);
    else
        return Escribir_Error_Param_Invalido;

    if (
        consola == INVALID_HANDLE_VALUE ||
        consola == NULL
    ) return Escribir_Error_GetStdHandle;

    retorno = (Bool_t)WriteFile(
        consola,
        _BUFFER_DE_TEXTO_C_,
        (DWORD)_CANTIDAD_DE_BYTES_A_ESCRIBIR_,
        &escritos,
        NULL
    );

    if (!retorno)
        retorno = Escribir_Error_WriteFile;
    else if (escritos != (DWORD)_CANTIDAD_DE_BYTES_A_ESCRIBIR_)
        retorno = Escribir_ErrorNOFATAL_Escritos_No_Iguales;
    else
        retorno = 0;

    if (_CANTIDAD_DE_BYTES_ESCRITOS_ != NULL)
        *_CANTIDAD_DE_BYTES_ESCRITOS_ += (Sint_t)escritos;

    return retorno;
}


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


Sint_t Imprimir(
    const char* _TEXTO_C_,
    void* _PUNTERO_ARGUMENTO_O_NULL_
) {
    #define C(iterador) _TEXTO_C_[bytes+iterador]
    if (_TEXTO_C_ == NULL)
        return 0;

    Uint_t bytes = 0;
    Sint_t Cantidad_escritos = 0;  
    Byte_t RetEscribir = 0;

    while (1) {
        if (_TEXTO_C_[bytes] == 0x00) 
            break;  
        else {
            if (_TEXTO_C_[bytes] == '%') {
                Bool_t exito = Si;

                goto saltear_logica_puntero_nulo;

                puntero_nulo:
                RetEscribir = Escribir("NULL", 4, NULL, CONSOLA_OUTPUT);
                if (
                    RetEscribir != 0 &&
                    RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                ) return -(Cantidad_escritos); 
                goto volver;

                saltear_logica_puntero_nulo:    

                if (_TEXTO_C_[bytes+1] == 's' || _TEXTO_C_[bytes+1] == 'S') {  
                    if (_PUNTERO_ARGUMENTO_O_NULL_ == NULL)  
                        goto puntero_nulo;  

                    Uint_t i = 0;  
                    char* _nuevo_TEXTO_C_ = (char*)_PUNTERO_ARGUMENTO_O_NULL_;  

                    while (1) {  
                        if (_nuevo_TEXTO_C_[i] == 0x00)  
                            break; 
                        RetEscribir = Escribir(
                            (const char*)&(_nuevo_TEXTO_C_[i]),  
                            1,
                            (&Cantidad_escritos),
                            CONSOLA_OUTPUT
                        );
                        if (
                            RetEscribir != 0 &&
                            RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                        ) return -(Cantidad_escritos);
                        i++;  
                    }  
                } else if (_TEXTO_C_[bytes+1] == 'c' || _TEXTO_C_[bytes+1] == 'C') {  
                    if (_PUNTERO_ARGUMENTO_O_NULL_ == NULL)  
                        goto puntero_nulo;  

                    char _nuevo_caracter_ = *((char*)(_PUNTERO_ARGUMENTO_O_NULL_));  


                    RetEscribir = Escribir(
                        (const char*)&_nuevo_caracter_,  
                        1,
                        (&Cantidad_escritos),
                        CONSOLA_OUTPUT
                    );
                    if (
                        RetEscribir != 0 &&
                        RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                    ) return -(Cantidad_escritos);  
                } else if (_TEXTO_C_[bytes+1] == 'x' || _TEXTO_C_[bytes+1] == 'X') {  
                    if (_PUNTERO_ARGUMENTO_O_NULL_ == NULL)  
                        goto puntero_nulo;  

                    Bool_t minuscula = Si;  
                    if (_TEXTO_C_[bytes+1] == 'X')  
                        minuscula = No;  

                    Byte_t _hex_ = *((Byte_t*)(_PUNTERO_ARGUMENTO_O_NULL_));  

                    Byte_t  nibble_alto = _hex_ >> 4;  
                    Byte_t  nibble_bajo = _hex_ & 0x0f;  
                    char* nibble = NULL;  
                    Bool_t  termino = No;  

                    while (1) {  
                        if (termino == No)  
                            nibble = (char*)&nibble_alto;  
                        else  
                            nibble = (char*)&nibble_bajo;  

                        if (*nibble < 0x0A)  
                            *nibble += 0x30;  
                        else {  
                            if (minuscula)  
                                *nibble += 0x57;  
                            else  
                                *nibble += 0x37;  
                        }  


                        RetEscribir = Escribir(
                            (const char*)nibble,  
                            1,
                            (&Cantidad_escritos),
                            CONSOLA_OUTPUT
                        );
                        if (
                            RetEscribir != 0 &&
                            RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                        ) return -(Cantidad_escritos); 

                        if (termino == Si)  
                            break;  
                        else  
                            termino = Si;  

                    }  
                } else if (_TEXTO_C_[bytes+1] == 'b' || _TEXTO_C_[bytes+1] == 'B') {  
                    if (_PUNTERO_ARGUMENTO_O_NULL_ == NULL)  
                        goto puntero_nulo;

                    Byte_t mascara = 0b10000000;  
                    Byte_t _bin_ = *((Byte_t*)(_PUNTERO_ARGUMENTO_O_NULL_));  

                    for (Byte_t i = 0; i < 8; i++) {  
                        if ((mascara >> i)&(_bin_)) { 
                            RetEscribir = Escribir(
                                "1",  
                                1,
                                (&Cantidad_escritos),
                                CONSOLA_OUTPUT
                            );
                            if (
                                RetEscribir != 0 &&
                                RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                            ) return -(Cantidad_escritos); 
                        } else {  
                            RetEscribir = Escribir(
                                "0",  
                                1,
                                (&Cantidad_escritos),
                                CONSOLA_OUTPUT
                            );
                            if (
                                RetEscribir != 0 &&
                                RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                            ) return -(Cantidad_escritos); 
                        }  
                    }  
                } else if (
                    (C(1) == 'i' && C(2) == 'n' && C(3) == 't')
                    ||
                    (C(1) == 'u' && C(2) == 'i' && C(3) == 'n' && C(4) == 't')
                ) {
                    if (_PUNTERO_ARGUMENTO_O_NULL_ == NULL) {
                        if (C(1) == 'i')
                            bytes+=2;
                        else
                            bytes+=3;
                        goto puntero_nulo;
                    }
                    char numero_texto[12] = {0};
                    Uint_t i = 11;

                    if (C(1) == 'i') {
                        Byte_t tipo_de_repr = TipoReprDeSignos();

                        Bool_t es_negativo = No;
                        bytes+=2;
                        Sint_t numero = *((Sint_t*)(_PUNTERO_ARGUMENTO_O_NULL_));
                        Uint_t numero_negativo = 0;

                        if (numero < 0) {
                            if (tipo_de_repr == _SIGNO_Y_MAGNITUD_)
                                if (sizeof(Sint_t) == 1)
                                    numero = (numero & 0x7f);
                                else if (sizeof(Sint_t) == 2)
                                    numero = (numero & 0x7fff);
                                else if (sizeof(Sint_t) == 8)
                                    numero = (numero & 0x7fffffffffffffff);
                                // sino es ninguna de las otras, entonces es la general.
                                else
                                    numero = (numero & 0x7fffffff);
                                //
                            else if (tipo_de_repr == _COMPLEMENTO_UNO_)
                                numero_negativo = (Uint_t)~numero;
                            else
                                numero_negativo = ((Uint_t)~numero)+1;

                            es_negativo = Si;
                        } else {
                            numero_negativo = (Uint_t)numero;
                        }

                        if (tipo_de_repr != _SIGNO_Y_MAGNITUD_) {
                            do {
                                numero_texto[i] = '0'+(numero_negativo%10);

                                numero_negativo /= 10;

                                i--;
                            } while (numero_negativo != 0);
                        } else {
                            do {
                                numero_texto[i] = '0'+(numero%10);

                                numero /= 10;

                                i--;
                            } while (numero != 0);
                        }

                        if (es_negativo == Si) {
                            numero_texto[i] = '-';
                            i--;
                        }
                    } else {
                        bytes+=3;
                        Uint_t numero = *((Uint_t*)(_PUNTERO_ARGUMENTO_O_NULL_));

                        do {
                            numero_texto[i] = '0'+(numero%10);

                            numero /= 10;

                            i--;
                        } while (numero != 0);
                    }

                    while (i < 11) {
                        i++;
                        RetEscribir = Escribir(
                            (const char*)&(numero_texto[i]),
                            1,
                            (&Cantidad_escritos),
                            CONSOLA_OUTPUT
                        );
                        if (
                            RetEscribir != 0 &&
                            RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                        ) return -(Cantidad_escritos);
                    }
                }
                else {  
                    no_exito:
                    RetEscribir = Escribir(
                        (const char*)&(_TEXTO_C_[bytes]),  
                        1,
                        (&Cantidad_escritos),
                        CONSOLA_OUTPUT
                    );
                    if (
                        RetEscribir != 0 &&
                        RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                    ) return -(Cantidad_escritos);
                    exito = No;
                }

                if (exito == No)
                    bytes++;
                else {
                    volver:
                        bytes+=2;
                }
                continue;  
            } else {  
                RetEscribir = Escribir(
                    (const char*)&(_TEXTO_C_[bytes]),  
                    1,
                    (&Cantidad_escritos),
                    CONSOLA_OUTPUT
                );
                if (
                    RetEscribir != 0 &&
                    RetEscribir != Escribir_ErrorNOFATAL_Escritos_No_Iguales
                ) return -(Cantidad_escritos);
            }  
        }  
        bytes++;  
    }  

    return +(Cantidad_escritos);
    #undef C
}



//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//
//
//=======================
