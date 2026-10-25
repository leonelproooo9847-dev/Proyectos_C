// LibpWin.h
#ifndef LIBPWIN_H

    #define LIBPWIN_H 2
    #include <stdint.h>

    //=========================================================================
    //definiciones

    #define WINDOWS_32BIT 0x10
    #define WINDOWS_64BIT 0x20
    #define WINDOWS_GNRAL 0x40
    #define LINUX         0xb0

    #define _SIGNO_Y_MAGNITUD_ 0x01
    #define _COMPLEMENTO_UNO_  0x02
    #define _COMPLEMENTO_DOS_  0x03

    #if defined(_WIN64)
        #define Sistema_Operativo WINDOWS_64BIT
    #elif defined(_WIN32)
        #define Sistema_Operativo WINDOWS_32BIT
    #elif defined(__linux__)
        #define Sistema_Operativo LINUX
    #else
        #error "Entorno desconocido (solo LINUX y WINDOWS)"
    #endif

    #define Verdadero  0x01  
    #define Falso      0x00  

    #define Si Verdadero  
    #define No Falso  

    typedef signed   int  Sint_t;
    typedef unsigned int  Uint_t;
    typedef unsigned char Byte_t;
    typedef unsigned char Bool_t;
    typedef unsigned char BoolBit_t;
    typedef void* MANEJADOR;

    #define Si_BIT0 (0b00000001)
    #define Si_BIT1 (0b00000010)
    #define Si_BIT2 (0b00000100)
    #define Si_BIT3 (0b00001000)
    #define Si_BIT4 (0b00010000)
    #define Si_BIT5 (0b00100000)
    #define Si_BIT6 (0b01000000)
    #define Si_BIT7 (0b10000000)

    #define No_BIT0 (~(0b00000001))
    #define No_BIT1 (~(0b00000010))
    #define No_BIT2 (~(0b00000100))
    #define No_BIT3 (~(0b00001000))
    #define No_BIT4 (~(0b00010000))
    #define No_BIT5 (~(0b00100000))
    #define No_BIT6 (~(0b01000000))
    #define No_BIT7 (~(0b10000000))

    #define CONSOLA_OUTPUT 0x0f // 00001111
    #define CONSOLA_INPUT  0x3c // 00111100
    #define CONSOLA_ERROR  0xf0 // 11110000

    #define IZQUIERDA  0x01
    #define DERECHA    0x02

    #define TECLA_INDETERMINADA         0x00
    #define TECLA_CARACTER              0xff
    #define ALT_DE_PRESIONADO       0x01
    #define ALT_IZ_PRESIONADO       0x02
    #define CONTROL_DE_PRESIONADO   0x04
    #define CONTROL_IZ_PRESIONADO   0x08
    #define SHIFT_PRESIONADO        0x10
    #define NUMLOCK_ACTVO           0x20
    #define MAYUS_ACTVO             0X40
    #define SCROLL_LOCK_ACTVO       0x80
    #define TECLA_CONTROL_DE    0x01        // VK_RCONTROL
    #define TECLA_CONTROL_IZ    0x02        // VK_LCONTROL
    #define TECLA_CONTROL       0x03
    #define TECLA_ALT_DE        0x04        // VK_RMENU
    #define TECLA_ALT_IZ        0x05        // VK_LMENU
    #define TECLA_ALT           0x06
    #define TECLA_OS_DE         0x07        // VK_RWIN
    #define TECLA_OS_IZ         0x08        // VK_LWIN
    #define TECLA_OS            0x09
    #define TECLA_SHIFT_DE      0x0a        // VK_RSHIFT
    #define TECLA_SHIFT_IZ      0x0b        // VK_LSHIFT
    #define TECLA_SHIFT         0x0c
    #define TECLA_ESCAPE        0x0d        // VK_ESCAPE
    #define TECLA_TAB           0x0e        // VK_TAB
    #define TECLA_BACKSPACE     0x0f        // VK_BACK
    #define TECLA_ENTER         0x10        // VK_RETURN
    #define TECLA_SUPRIMIR      0x11        // VK_DELETE
    #define TECLA_INSERTAR      0x12        // VK_INSERT
    #define TECLA_FLECHA_ARRIBA 0x13        // VK_UP
    #define TECLA_FLECHA_ABAJO  0x14        // VK_DOWN
    #define TECLA_FLECHA_IZ     0x15        // VK_LEFT
    #define TECLA_FLECHA_DE     0x16        // VK_RIGHT
    #define TECLA_INICIO        0x17        // VK_HOME
    #define TECLA_FIN           0x18        // VK_END
    #define TECLA_PAG_ARRIBA    0x19        // VK_PRIOR
    #define TECLA_PAG_ABAJO     0x1a        // VK_NEXT
    #define TECLA_F1            0x1b
    #define TECLA_F2            0x1c
    #define TECLA_F3            0x1d
    #define TECLA_F4            0x1e
    #define TECLA_F5            0x1f
    #define TECLA_F6            0x20
    #define TECLA_F7            0x21
    #define TECLA_F8            0x22
    #define TECLA_F9            0x23
    #define TECLA_F10           0x24
    #define TECLA_F11           0x25
    #define TECLA_F12           0x26


    #define TECLA_F13           0x27
    #define TECLA_F14           0x28
    #define TECLA_F15           0x29
    #define TECLA_F16           0x2a
    #define TECLA_F17           0x2b
    #define TECLA_F18           0x2c
    #define TECLA_F19           0x2d
    #define TECLA_F20           0x2e
    #define TECLA_F21           0x2f
    #define TECLA_F22           0x30
    #define TECLA_F23           0x31
    #define TECLA_F24           0x32


    // Errores de funciones
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

    // CambiarCodPag_UTF8() y RestaurarCodPag()
    //////////////////////////////////////////////////////////////////
    #define CambiarCodPagUTF8_Error_SetConsoleCP_Entrada        0x01//
    #define CambiarCodPagUTF8_Error_SetConsoleOutputCP_Salida   0x02//
    #define CambiarCodPagUTF8_Error_AmbasOperaciones            0x03//
    #define CambiarCodPagUTF8_Error_GetConsoleCP_Entrada        0x04//
    #define CambiarCodPagUTF8_Error_GetConsoleOutputCP_Salida   0x05//
    /****************************************************************/
    #define RestaurarCodPag_Error_SetConsoleCP_Entrada          0x01//
    #define RestaurarCodPag_Error_SetConsoleOutputCP_Salida     0x02//
    #define RestaurarCodPag_Error_AmbasOperaciones              0x03//
    #define RestaurarCodPag_Error_Registro_Entrada_Cero         0x04//
    #define RestaurarCodPag_Error_Registro_Salida_Cero          0x05//
    //////////////////////////////////////////////////////////////////


    // LimpiarConsola(...);
    ////////////////////////////////////////////////////////////////////////
    #define LimpiarConsola_Error_Parametro_Invalido                   0xff//
    #define LimpiarConsola_Error_GetStdHandle_stdOut                  0x01//
    #define LimpiarConsola_Error_GetStdHandle_stdErr                  0x10//
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


    //////////////////////////////////////////////////////////////////////
    #define Escribir_Error_Param_Invalido                           0x01//
    #define Escribir_Error_Puntero_NULL                             0x02//
    #define Escribir_ErrorNOFATAL_Escritos_No_Iguales               0x05//
    #define Escribir_Error_GetStdHandle                             0x03//
    #define Escribir_Error_WriteFile                                0x04//
    //////////////////////////////////////////////////////////////////////

    // CrearProceso(...);
    //////////////////////////////////////////////////////////////////////////
    #define CrearProceso_Error_Puntero_Estructura_NULL                  0x01//
    #define CrearProceso_Error_Puntero_Ruta_Ejecutable_NULL             0x02//
    #define CrearProceso_Error_NoImprimirEnEstaConsola_INVALID_HANDLE   0x03//
    #define CrearProceso_Error_CreateProcessA                           0x04//
    //////////////////////////////////////////////////////////////////////////

    //=========================================================================

    // funciones especificas:
    //=========================================================================
    #define Especif_SacarDirectorioActual       0x01
    #define Especif_LimpiarBuffer               0x02
    #define Especif_CopiarBuffer                0x03
    #define Especif_ComprobarListaDeTexto       0x04
    #define Especif_CapturarTeclaUTF8           0x05
    #define Especif_CambiarCodPagUTF8           0x06
    #define Especif_RestaurarCodPag             0x07
    #define Especif_LimpiarConsola              0x08
    #define Especif_Entrada                     0x09
    #define Especif_Escribir                    0x0A
    #define Especif_CrearProceso                0x0B
//--
//
//
//
//
//
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
// estructuras y registros:


    /*----------------------------------------------------------------------------*/


    typedef struct _REGISTROS_CODIGO_DE_PAGINA {
        Uint_t ENTRADA_CodPag;
        Uint_t SALIDA_CodPag;
    } REGISTROS_CODIGO_DE_PAGINA;


    /*----------------------------------------------------------------------------*/


    typedef struct _EVENTO_TECLA {
        char _CARACTER_UNICODE_[4];
        Byte_t BYTES_ESCRITOS;
        Byte_t TIPO_DE_EVENTO;
        Byte_t IZQUIERDA_O_DERECHA;
        union {
            Bool_t    HUBO_MODIFICADORES;
            BoolBit_t CTRL_DERECHA;
            BoolBit_t CTRL_IZQUIERDA;
            BoolBit_t ALT_DERECHA;
            BoolBit_t ALT_IZQUIERDA;
            BoolBit_t SHIFT;
            BoolBit_t NUM_LOCK_ACTIVO;
            BoolBit_t MAYUS_ACTIVO;
            BoolBit_t SCROLL_LOCK_ACTIVO;
        } Campo_Teclas_modificadoras;
    } EVENTO_TECLA;


    /*----------------------------------------------------------------------------*/


    typedef struct _ENTRADA_PARAMs {
        char*   _PUNTERO_BUFFER_DE_ENTRADA_;
        size_t  _LONGITUD_DEL_BUFFER_;
        Bool_t _PERMITIR_CONFIGURACION_;
        struct {
            Bool_t MOSTRAR_INDICADOR_DE_LONGITUD_USADA;
            Bool_t MOSTRAR_PROMPT_DE_ENTRADA;
            const char*  _PROMPT_DE_ENTRADA_TEXTO_C_;
            struct {
                Bool_t USAR_METODO_DE_SALIDA_CON_TECLA_ESPECIAL;
                Byte_t TECLA_ESPECIAL_DE_SALIDA;
                Bool_t INDICAR_METODO_DE_SALIDA_AL_USUARIO;
                Bool_t MOSTRAR_LISTA_DE_MENSAJES_ANTES_DE_LA_ENTRADA;
                const char*  _LISTA_DE_MENSAJES_;
                size_t       _LONGITUD_DE_LA_LISTA_;
            } Campo_Avanzados;
        } Campo_Configuracion;
    } ENTRADA_PARAMs;


    /*----------------------------------------------------------------------------*/


    typedef struct _COMPROBACION_PARAMs {
        struct {
            const char* _LISTA_DE_TEXTO_C_;
            size_t  _LONGITUD_DE_LA_LISTA_;
        } Campo_datos_de_entrada;
        struct {
            size_t* _LISTA_DE_SIZEs__GUARDADO_DE_INDICES_;
            size_t  _CANTIDAD_DE_SIZEs_;
        } Campo_datos_de_salida;
    } COMPROBACION_PARAMs;



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
// definiciones de funciones de esta API:


    Byte_t SacarDirectorioActual(
        char*  __UBICACION_ACTUAL_DE_ESTE_ARCHIVO__entrada,
        char*  __UBICACION_MODIFICADA__resultado,
        size_t __LONGITUD_DEL_BUFFER_DE_RESULTADO__,
        Bool_t __DEJAR_BARRA_INVERTIDA__
    );
    //=========================================================================
    Byte_t LimpiarBuffer(
        Byte_t*     _ESTRUCTURA_,
        size_t      _CANTIDAD_DE_BYTES_
    );
    //=========================================================================
    Byte_t TipoReprDeSignos();
    //=========================================================================
    Byte_t CopiarBuffer(
        void* BUFFER_ORIGEN,
        void* BUFFER_DESTINO,
        size_t LONGITUD_DEL_BUFFER_ORIGEN,
        size_t LONGITUD_DEL_BUFFER_DESTINO
    );
    Byte_t ComprobarListaDeTexto(
        COMPROBACION_PARAMs* PARAMETROS
    );
    //=========================================================================
    void ImprimirTipoTecla(
        Byte_t TECLA_ESPECIAL_A_IMPRIMIR
    );
    //=========================================================================
    void ImprimirMensajeDeError(
        void*  _PUNTERO_DE_RETORNO_O_DE_CODIGO_DE_ERROR_,
        Byte_t _FUNCION_ESPECIFICA_DEL_ERROR_
    );
    //=========================================================================
    //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
    //=========================================================================
    Byte_t CapturarTeclaUTF8(
        EVENTO_TECLA* INFORMACION_DE_LA_TECLA
    );
    //=========================================================================
    Byte_t CambiarCodPagUTF8();
    Byte_t RestaurarCodPag(
        Bool_t CONSULTAR_REGISTROS_O_PREDETERMINADO
    );
    REGISTROS_CODIGO_DE_PAGINA ConsultarRegistros();
    //=========================================================================
    Byte_t LimpiarConsola(
        Byte_t CONSOLA_A_LIMPIAR
    );
    //=========================================================================
    Byte_t Entrada(
        ENTRADA_PARAMs* _CONFIGURACIONES_Y_PARAMETROS_
    );
    //=========================================================================
    Byte_t Escribir(
        const char*   _BUFFER_DE_TEXTO_C_,
        size_t  _CANTIDAD_DE_BYTES_A_ESCRIBIR_,
        Sint_t* _CANTIDAD_DE_BYTES_ESCRITOS_,
        Byte_t  _CONSOLA_OUTPUT_O_ERROR_
    );
    //=========================================================================
    Sint_t Imprimir(
        const char* _TEXTO_C_,
        void* _PUNTERO_ARGUMENTO_O_NULL_
    );


//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
#endif
