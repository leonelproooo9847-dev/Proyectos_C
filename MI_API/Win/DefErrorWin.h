#ifndef DEF_ERROR_WIN_H
    #define DEF_ERROR_WIN_H "V: 1.1 | NumCab: 4"

    // Errores definiciones
    //======================================================================
    /* generales */
    #define GENERAL_Error_Puntero_NULL                      0x01
    //======================================================================
    /* funciones portables */
    #define SacarDirectorioActual_Error_Punteros_NULLs      0x01
    #define SacarDirectorioActual_Error_Longitud_Corta      0x02
    ////////////////////////////////////////////////////////////////////////
    #define LimpiarBuffer_Error_Puntero_NULL                0x01
    ////////////////////////////////////////////////////////////////////////
    #define CopiarBuffer_Error_Punteros_Buffers_NULLs               0x01
    #define CopiarBuffer_Error_Longitudes_Buffers_Cero              0x02
    #define CopiarBuffer_Error_Solapamiento_Buffers_Destino_Origen  0x03
    #define CopiarBuffer_Error_Solapamiento_Buffers_Origen_Destino  0x04
    #define CopiarBuffer_Error_Mismos_Punteros_Origen_Destino       0x05
    ////////////////////////////////////////////////////////////////////////
    #define ComprobarListaDeTexto_Error_Longitud_Cero                       0x01
    #define ComprobarListaDeTexto_Error_Inicio_Con_Cero                     0x02
    #define ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP1           0x03
    #define ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP2           0x04
    #define ComprobarListaDeTexto_Error_Etapa_No_Terminada_EXCEP3           0x05
    #define ComprobarListaDeTexto_Error_Estructura_NULL                     0x06
    #define ComprobarListaDeTexto_Error_Puntero_De_Lista_De_Texto_C_NULL    0x07
    #define ComprobarListaDeTexto_Error_Cantidad_De_Sizes_Cero              0x08
    #define ComprobarListaDeTexto_Error_Lista_Sizes_Insuficientes           0x09
    //======================================================================
    // CapturarTeclaUTF8(...);
    ///////////////////////////////////////////////////////////////////////////////////////////////
    #define CapturarTeclaUTF8_Error_Puntero_NULL                                             0x01//
    #define CapturarTeclaUTF8_Error_Escritos_Cero                                            0x03//
    #define CapturarTeclaUTF8_Error_ReadConsoleInputW                                        0x02//
    #define CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__Sin_KeyEvent                    0x05//
    #define CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__KeyDown_Falso                   0x06//
    #define CapturarTeclaUTF8_Error_Lectura_De_Par_Suplente__Suplente_No_Correspondiente     0x07//
    ///////////////////////////////////////////////////////////////////////////////////////////////

    // CambiarCodigoDePagina()
    //////////////////////////////////////////////////////////////////////////////////
    #define CambiarCodigoDePagina_Error_Parametro_CodPag_Invalido               0x7f//
    #define CambiarCodigoDePagina_Error_Parametro_Consola_Invalido              0xff//
    #define CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_SetConsoleOutputCP       0x01//
    #define CambiarCodigoDePagina_Error_CONSOLA_INPUT_SetConsoleCP              0x02//
    #define CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleOutputCP 0x04//
    #define CambiarCodigoDePagina_Error_CONSOLA_OUTPUT_INPUT_SetConsoleCP       0x08//
    //////////////////////////////////////////////////////////////////////////////////


    // LimpiarConsola(...);
    ////////////////////////////////////////////////////////////////////////
    #define LimpiarConsola_Error_Parametro_Invalido                   0xff//
    #define LimpiarConsola_Error_GetStdHandle_stdOut                  0x01//
    #define LimpiarConsola_Error_GetStdHandle_stdErr                  0x10//
    #define LimpiarConsola_Error_GetStdHandle_stdIn                   0xf1//
    #define LimpiarConsola_Error_stdIn_Sin_Consola                    0xf2//
    #define LimpiarConsola_Error_FlushConsoleInputBuffer_stdIn        0xf3//
    #define LimpiarConsola_Error_stdOut_Sin_Consola                   0x02//
    #define LimpiarConsola_Error_stdErr_Sin_Consola                   0x20//
    #define LimpiarConsola_Error_GetConsoleScreemBufferInfo_stdOut    0x03//
    #define LimpiarConsola_Error_FillConsoleCharacterA_stdOut         0x04//
    #define LimpiarConsola_Error_FillConsoleAttribute_stdOut          0x05//
    #define LimpiarConsola_Error_SetCursor_stdOut                     0x06//
    #define LimpiarConsola_Error_GetConsoleScreemBufferInfo_stdErr    0x30//
    #define LimpiarConsola_Error_FillConsoleCharacterA_stdErr         0x40//
    #define LimpiarConsola_Error_FillConsoleAttribute_stdErr          0x50//
    #define LimpiarConsola_Error_SetCursor_stdErr                     0x60//
    ////////////////////////////////////////////////////////////////////////


    // Entrada(...);
    //////////////////////////////////////////////////////////////
    #define Entrada_Error_Puntero_Estructura_NULL           0x01//
    #define Entrada_Error_Puntero_BufferEntrada_NULL        0x02//
    #define Entrada_Error_LongitudBuffer_Menor_A_Dos        0x03//
    #define Entrada_Error_Lista_De_Mensajes                 0x10//
    #define Entrada_Error_CapturarTeclaUTF8                 0x04//
    #define Entrada_ErrorNOFATAL_Salida_Por_Tecla_Especial  0x05//
    #define Entrada_Error_LimpiarConsola                    0x06//
    #define Entrada_Error_GetConsoleCP                      0x07//
    #define Entrada_Error_GetConsoleOutputCP                0x08//
    #define Entrada_Error_SetConsoleCP                      0x09//
    #define Entrada_Error_SetConsoleOutputCP                0x0f//
    //////////////////////////////////////////////////////////////

    // Escribir(...)
    //////////////////////////////////////////////////////////////////////
    #define Escribir_Error_Param_Invalido                           0x01//
    #define Escribir_Error_Puntero_NULL                             0x02//
    #define Escribir_ErrorNOFATAL_Escritos_No_Iguales               0x05//
    #define Escribir_Error_GetStdHandle                             0x03//
    #define Escribir_Error_WriteFile                                0x04//
    //////////////////////////////////////////////////////////////////////

    // CrearProceso(...)
    //
    #define CrearProceso_Error_Estructura_Parametros_NULL       0x01
    #define CrearProceso_Error_Estructura_Informacion_NULL      0x02
    #define CrearProceso_Error_Direccion_NULL                   0x03
    //

    //=========================================================================

    // funciones especificas:
    //=========================================================================
    #define Especif_SacarDirectorioActual       0x01
    #define Especif_LimpiarBuffer               0x02
    #define Especif_CopiarBuffer                0x03
    #define Especif_ComprobarListaDeTexto       0x04
    #define Especif_CapturarTeclaUTF8           0x05
    #define Especif_CambiarCodigoDePagina       0x06
    #define Especif_LimpiarConsola              0x07
    #define Especif_Entrada                     0x08
    #define Especif_Escribir                    0x09
    #define Especif_CrearProceso                0x0A

#endif
