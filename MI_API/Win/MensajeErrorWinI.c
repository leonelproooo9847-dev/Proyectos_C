// MensajeErrorWinI.c

#include "MensajeErrorWin.h"
#include <stddef.h>
#include <windows.h>

static void escribirErr(
    const char* _texto_,
    DWORD cantidad
) {
    if (_texto_ == NULL)
        return;
    
    HANDLE consola = GetStdHandle(STD_ERROR_HANDLE);
    if (
        consola == INVALID_HANDLE_VALUE ||
        consola == NULL
    ) return;

    WriteFile(
        consola,
        (void*)_texto_,
        cantidad,
        NULL,
        NULL
    );

    return;
}

static void imprimirErr (
    const char* _texto_,
    void* ptr_arg_o_NULL
) {
    DWORD cantidad = 0;

    while (_texto_[cantidad] != 0x00)
        cantidad++;
    
    DWORD i = 0;

    while (i < cantidad) {
        char C = _texto_[i];

        if (C == '%') {
            if (ptr_arg_o_NULL == NULL)
                escribirErr("%", 1);
            else {
                Byte_t i_ = 11;
                Uint_t num = *((Uint_t*)(ptr_arg_o_NULL));
                char num_txt[12] = {0};
                
                do {
                    num_txt[i_] = '0'+(num%10);

                    num /= 10;

                    i_--;
                } while (num != 0);

                while (i_ < 11) {
                    i_++;
                    escribirErr((const char*)&(num_txt[i]), 1);
                }
            }
        } else {
            escribirErr((const char*)(&C), 1);
        }

        i++;
    }

    return;
}

void ImprimirMensajeDeError(
    void*  _PUNTERO_DE_RETORNO_O_DE_CODIGO_DE_ERROR_,
    Byte_t _FUNCION_ESPECIFICA_DEL_ERROR_
) {
    #define ptrRet  (_PUNTERO_DE_RETORNO_O_DE_CODIGO_DE_ERROR_)
    #define ptrRetDes(TIPO_DESREFERENCIA)   (*((TIPO_DESREFERENCIA*)(_PUNTERO_DE_RETORNO_O_DE_CODIGO_DE_ERROR_)))
    #define Especif_Funcion (_FUNCION_ESPECIFICA_DEL_ERROR_)

    escribirErr("Error : ", 8);

    if (_FUNCION_ESPECIFICA_DEL_ERROR_ == 0) {
        imprimirErr(
            "NO_ESPECIFICO : NO_DATOS : %",
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
                        escribirErr(
                            "SacarDirectorioActual :\n\t"
                            "Uno o ambos parametros punteros buffer a char es NULL",
                            78
                        );
                    break;

                    case SacarDirectorioActual_Error_Longitud_Corta:
                        escribirErr(
                            "SacarDirectorioActual :\n\t"
                            "Longitud corta del buffer de resultado",
                            63
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
                        escribirErr(
                            "LimpiarBuffer :\n\t"
                            "El parametro de puntero buffer Byte_t es NULL",
                            62
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
                        escribirErr(
                            "CopiarBuffer :\n\t"
                            "Uno o ambos parametros de punteros buffer void es NULL",
                            70
                        );
                    break;

                    case CopiarBuffer_Error_Longitudes_Buffers_Cero:
                        escribirErr(
                            "CopiarBuffer :\n\t"
                            "Uno o ambos parametros de longitudes de buffers es cero",
                            71
                        );
                    break;

                    case CopiarBuffer_Error_Solapamiento_Buffers_Destino_Origen:
                        escribirErr(
                            "CopiarBuffer :\n\t"
                            "Hay solapamiento de memoria de los buffers Destino sobre Origen",
                            79
                        );
                    break;

                    case CopiarBuffer_Error_Solapamiento_Buffers_Origen_Destino:
                        escribirErr(
                            "CopiarBuffer :\n\t"
                            "Hay solapamiento de memoria de los buffers Origen sobre Destino",
                            79
                        );
                    break;

                    case CopiarBuffer_Error_Mismos_Punteros_Origen_Destino:
                        escribirErr(
                            "CopiarBuffer :\n\t"
                            "Ambos parametros de punteros buffer void son iguales",
                            68
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
                        escribirErr(
                            "ComprobarListaDeTexto :\n\t"
                            "El parametro de puntero a COMPROBACION_PARAMs es NULL",
                            79
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Longitud_Cero:
                        escribirErr(
                            "ComprobarListaDeTexto :\n\t"
                            "En el Campo_datos_de_entrada :\n\t\t"
                            "La longitud del buffer es cero",
                            88
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Inicio_Con_Cero:
                        escribirErr(
                            "ComprobarListaDeTexto :\n\t"
                            "La lista de texto compienza con cero: \\000",
                            67
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP1:
                    case ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP2:
                    case ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP3:
                        escribirErr(
                            "ComprobarListaDeTexto :\n\t"
                            "No se pudo analizar toda la estructura :\n\t\t"
                            "Etapa en enum\n\t\t|       ",
                            92
                        );
                        if (ptrRetDes(Byte_t) == ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP1) {
                            escribirErr(
                                "NADA", 4
                            );
                        } else if (ptrRetDes(Byte_t) == ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP2) {
                            escribirErr(
                                "TEXTO_C", 7
                            );
                        } else {
                            escribirErr(
                                "CARACTER_CERO", 13
                            );
                        }
                    break;

                    case ComprobarListaDeTexto_Error_Puntero_De_Lista_De_Texto_C_NULL:
                        escribirErr(
                            "ComprobarListaDeTexto :\n\t"
                            "En el Campo_datos_de_entrada :\n\t\t"
                            "El puntero buffer char es NULL",
                            88
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Cantidad_De_Sizes_Cero:
                        escribirErr(
                            "ComprobarListaDeTexto :\n\t"
                            "En el Campo_datos_de_salida :\n\t\t"
                            "La cantidad de Sizes proporcionada es cero",
                            99
                        );
                    break;

                    case ComprobarListaDeTexto_Error_Lista_Sizes_Insuficientes:
                        escribirErr(
                            "ComprobarListaDeTexto :\n\t"
                            "En el Campo_datos_de_salida :\n\t\t"
                            "Hay menos Sizes que cantidad de elementos en la lista",
                            111
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
                        escribirErr(
                            "CapturarTeclaUTF8 :\n\t"
                            "El parametro de puntero de EVENTO_TECLA es NULL",
                            68
                        );
                    break;

                    case CapturarTeclaUTF8_Error_ReadConsoleInputW:
                        escribirErr(
                            "CapturarTeclaUTF8 :\n\t"
                            "Error API windows.h\n\t|       ReadConsoleInputW",
                            67
                        );    
                    break;

                    case CapturarTeclaUTF8_Error_Escritos_Cero:
                        escribirErr(
                            "CapturarTeclaUTF8 :\n\t"
                            "La cantidad escrita de byte a _Caracter_UNICODE_ es cero",
                            77
                        );
                    break;

                    case CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__Sin_KeyEvent:
                        escribirErr(
                            "CapturarTeclaUTF8 :\n\t"
                            "Lectura de par suplente :\n\t\tSin KeyEvent",
                            61
                        );
                    break;

                    case CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__KeyDown_Falso:
                        escribirErr(
                            "CapturarTeclaUTF8 :\n\t"
                            "Lectura de par suplente :\n\t\tKeyDown Falso",
                            62
                        );
                    break;

                    case CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__Suplente_No_Correspondiente:
                        escribirErr(
                            "CapturarTeclaUTF8 :\n\t"
                            "Lectura de par suplente :\n\t\tSuplente no correspondiente",
                            76
                        );
                    break;
                }
            break;
            //==============================================================
            // CambiarCodigoDePagina
            //==============================================================
            case Especif_CambiarCodigoDePagina:
                escribirErr(
                    "CambiarCodigoDePagina :\n\t",
                    25
                );
                switch (ptrRetDes(Byte_t)) {
                    case CambiarCodigoDePagina_Error_Parametro_CodPag_Invalido:
                        escribirErr(
                            "El codigo de pagina seleccionado no es reconocido",
                            49
                        );
                    break;

                    case CambiarCodigoDePagina_Error_Parametro_Consola_Invalido:
                        escribirErr(
                            "La consola seleccionada no es reconocida",
                            40
                        );
                    break;

                    case CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_SetConsoleOutputCP:
                        escribirErr(
                            "En Consola Output :\n\t\t"
                            "Error API windows.h\n\t\t"
                            "|       SetConsoleOutputCP",
                            70
                        );
                    break;

                    case CambiarCodigoDePagina_Error_CONSOLA_INPUT_SetConsoleCP:
                        escribirErr(
                            "En Consola Input :\n\t\t"
                            "Error API windows.h\n\t\t"
                            "|       SetConsoleCP",
                            63
                        );
                    break;

                    case CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleOutputCP:
                    case CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleCP:
                        escribirErr(
                            "En Consola Output y Input :\n\t\t"
                            "Error API windows.h\n\t\t",
                            52
                        );
                        escribirErr ("|       SetConsoleOutputCP: ", 28);
                        if (ptrRetDes(Byte_t) == CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleOutputCP) {
                            escribirErr("ERR", 3);
                            break;
                        } else escribirErr("OK\n\t\t", 5);

                        escribirErr(
                            "|       SetConsoleCP: ERR\n\t\t"
                            "Estado de consola incompleto.\n\t\t"
                            "Falta configurar CONSOLA_INPUT.", 
                            91
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
                        escribirErr(
                            "LimpiarConsola :\n\t"
                            "El parametro de especificacion de consola es invalido o incorrecto",
                            84
                        );
                    break;

                    case LimpiarConsola_Error_stdOut_Sin_Consola:
                        escribirErr(
                            "LimpiarConsola :\n\t"
                            "stdOut sin consola para limpiar",
                            49
                        );
                    break;

                    case LimpiarConsola_Error_stdErr_Sin_Consola:
                        escribirErr(
                            "LimpiarConsola :\n\t"
                            "stdErr sin consola para limpiar",
                            49
                        );
                    break;

                    case LimpiarConsola_Error_GetStdHandle_stdIn:
                        escribirErr(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetStdHandle en stdIn",
                            68
                        );
                    break;

                    case LimpiarConsola_Error_stdIn_Sin_Consola:
                        escribirErr(
                            "LimpiarConsola :\n\t"
                            "stdIn sin consola para limpiar",
                            48
                        );
                    break;

                    case LimpiarConsola_Error_FlushConsoleInputBuffer_stdIn:
                        escribirErr(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       FlushConsoleInputBuffer en stdIn",
                            79
                        );
                    break;

                    case LimpiarConsola_Error_GetStdHandle_stdOut:
                    case LimpiarConsola_Error_GetStdHandle_stdErr:
                        escribirErr(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetStdHandle",
                            59
                        );
                    break;

                    case LimpiarConsola_Error_GetConsoleScreemBufferInfo_stdOut:
                    case LimpiarConsola_Error_GetConsoleScreemBufferInfo_stdErr:
                        escribirErr(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetConsoleScreemBufferInfo",
                            73
                        );
                    break;

                    case LimpiarConsola_Error_FillConsoleCharacterA_stdOut:
                    case LimpiarConsola_Error_FillConsoleCharacterA_stdErr:
                        escribirErr(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       FillConsoleOutputCharacterA",
                            74
                        );
                    break;

                    case LimpiarConsola_Error_FillConsoleAttribute_stdOut:
                    case LimpiarConsola_Error_FillConsoleAttribute_stdErr:
                        escribirErr(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       FillConsoleOutputAttribute",
                            73
                        );
                    break;

                    case LimpiarConsola_Error_SetCursor_stdOut:
                    case LimpiarConsola_Error_SetCursor_stdErr:
                        escribirErr(
                            "LimpiarConsola :\n\t"
                            "Error API windows.h\n\t"
                            "|       SetConsoleCursorPosition",
                            71
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
                        escribirErr(
                            " en stdOut",
                            10
                        );
                    } else {
                        /*STDERR*/
                        escribirErr(
                            " en stdErr",
                            10
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
                        escribirErr(
                            "Entrada :\n\t"
                            "El parametro de puntero ENTRADA_PARAMs es NULL",
                            57
                        );
                    break;

                    case Entrada_Error_Puntero_BufferEntrada_NULL:
                        escribirErr(
                            "Entrada :\n\t"
                            "En ENTRADA_PARAMs :\n\t\t"
                            "El puntero al buffer de entrada es NULL",
                            72
                        );
                    break;

                    case Entrada_Error_LongitudBuffer_Menor_A_Dos:
                        escribirErr(
                            "Entrada :\n\t"
                            "En ENTRADA_PARAMs :\n\t\t"
                            "La longitud del buffer proporcionada es menor a 2 bytes",
                            88
                        );
                    break;

                    case Entrada_Error_Lista_De_Mensajes:
                        escribirErr(
                            "Entrada :\n\t"
                            "La lista de mensajes proporcionada es invalida o incorrecta (ComprobarListaDeTexto)",
                            94
                        );
                    break;

                    case Entrada_Error_CapturarTeclaUTF8:
                        escribirErr(
                            "Entrada :\n\t"
                            "Error en CapturarTeclaUTF8",
                            37
                        );
                    break;

                    case Entrada_ErrorNOFATAL_Salida_Por_Tecla_Especial:
                        escribirErr(
                            "NOFATAL : Entrada :\n\t"
                            "Interrupcion por tecla especial",
                            53
                        );
                    break;

                    case Entrada_Error_LimpiarConsola:
                        escribirErr(
                            "Entrada :\n\t"
                            "Error en LimpiarConsola",
                            34
                        );
                    break;

                    case Entrada_Error_GetConsoleCP:
                        escribirErr(
                            "Entrada :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetConsoleCP",
                            52
                        );
                    break;

                    case Entrada_Error_GetConsoleOutputCP:
                        escribirErr(
                            "Entrada :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetConsoleOutputCP",
                            58
                        );
                    break;

                    case Entrada_Error_SetConsoleCP:
                        escribirErr(
                            "Entrada :\n\t"
                            "Error API windows.h\n\t"
                            "|       SetConsoleCP",
                            52
                        );
                    break;

                    case Entrada_Error_SetConsoleOutputCP:
                        escribirErr(
                            "Entrada :\n\t"
                            "Error API windows.h\n\t"
                            "|       SetConsoleOutputCP", 
                            58
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
                        escribirErr(
                            "escribir :\n\t"
                            "El parametro de especificacion de consola es invalido",
                            65
                        );
                    break;

                    case Escribir_Error_Puntero_NULL:
                        escribirErr(
                            "escribir :\n\t"
                            "El parametro de puntero buffer const char es NULL",
                            61
                        );
                    break;

                    case Escribir_ErrorNOFATAL_Escritos_No_Iguales:
                        escribirErr(
                            "NOFATAL : escribir :\n\t"
                            "La cantidad de escritura realizada no es igual al proporcionado",
                            85
                        );
                    break;

                    case Escribir_Error_GetStdHandle:
                        escribirErr(
                            "escribir :\n\t"
                            "Error API windows.h\n\t"
                            "|       GetStdHandle",
                            53
                        );
                    break;

                    case Escribir_Error_WriteFile:
                        escribirErr(
                            "escribir :\n\t"
                            "Error API windows.h\n\t"
                            "|       WriteFile",
                            50
                        );
                    break;
                }
            break;

            default:
                imprimirErr(
                    "NO_ESPECIFICO : NO_DATOS : %",
                    _PUNTERO_DE_RETORNO_O_DE_CODIGO_DE_ERROR_
                );
            break;
        }
    }

    #undef ptrRet
    #undef ptrRetDes
    #undef Especif
}
