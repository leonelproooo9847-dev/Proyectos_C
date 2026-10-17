// LEOCABp_H
#ifndef LIBP_H
 
    #define LIBP_H 2
    #include <stddef.h>
     
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
        #define LEO_OS WINDOWS_64BIT
    #elif defined(_WIN32)
        #define LEO_OS WINDOWS_32BIT
    #elif defined(__linux__)
        #define LEO_OS LINUX
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
 
    /**
     * @date: La firma de las definiciones de error están hechas de este modo:
     *      CATEGORÍA | ERROR _ FATAL O NO | DATO ESPECIFICO DEL ERROR
   
     * CATEGORÍA        : puede ser desde una función a algo general.
     * ERROR            : indica que es un error. Además si viene acompañado de
     *                  la abreviación 'Win' o 'Lix' al inicio 'Error' quieren decir que
     *                  son específico de ese entorno.
     * FATAL O NO       : indica si es fatal o no, en los errores fatales
     *                  no se indica mientras que en los no fatales se indica
     *                  especeficiamente como 'NOFATAL'. Es decir, que la ausencia de
     *                  'NOFATAL' en el nombre de la definición, quiere decir que ES fatal.
     * DATO ESPECIFICO  : este apartado indica qué error describe la función en base con su
     *                  Número de retorno.
     * @exception: algunas funciones no trabajan con valores de retornos
     *           que indiquen exactamente su estado, como en el caso de Imprimir.
     *           Imprimir devuelve 0 si el texto pasado es NULL,
     *           - si tuvo exito devuelve la cantidad de caracteres escrito en positivo,
     *           - si tuvo algún error al llamar Escribir, devuelve la cantidad de 
     *             caracteres escritos en negativo.
     */
    //======================================================================
    /* generales */
    #define GENERAL_Error_Puntero_NULL                      0x01
    //======================================================================
    /* funciones portables */
    #define SacarDirectorioActual_Error_Punteros_NULLs      0x01
    #define SacarDirectorioActual_Error_Longitud_Corta      0x02
     
    #define LimpiarBuffer_Error_Puntero_NULL                0x01
     
    #define CopiarBuffer_Error_Punteros_Buffers_NULLs               0x01
    #define CopiarBuffer_Error_Longitudes_Buffers_Cero              0x02
    #define CopiarBuffer_Error_Solapamiento_Buffers_Destino_Origen  0x03
    #define CopiarBuffer_Error_Solapamiento_Buffers_Origen_Destino  0x04
    #define CopiarBuffer_Error_Mismos_Punteros_Origen_Destino       0x05
    //======================================================================
    /* funciones de entornos de Windows y Linux */
    // CapturarTeclaUTF8(...);
    ///////////////////////////////////////////////////////////////////////////////////////////////
    #define CapturarTeclaUTF8_Error_Puntero_NULL                                             0x01//
    #define CapturarTeclaUTF8_Error_Escritos_Cero                                            0x03//
    #define CapturarTeclaUTF8_WinError_ReadConsoleInputW                                     0x02//
    #define CapturarTeclaUTF8_WinError_Lectura_De_Par_Suplente__Sin_KeyEvent                 0x05//
    #define CapturarTeclaUTF8_WinError_Lectura_De_Par_Suplente__KeyDown_Falso                0x06//
    #define CapturarTeclaUTF8_WinError_Lectura_De_Par_Suplente__Suplente_No_Correspondiente  0x07//
    ///////////////////////////////////////////////////////////////////////////////////////////////
     
    // LimpiarConsola(...);
    ////////////////////////////////////////////////////////////////////////
    #define LimpiarConsola_Error_Parametro_Invalido                   0xff//
    /********************************************************************///
    #define LimpiarConsola_WinError_GetStdHandle_stdOut               0x01//
    #define LimpiarConsola_WinError_GetStdHandle_stdErr               0x10//
    #define LimpiarConsola_WinError_stdOut_Sin_Consola                0x02//
    #define LimpiarConsola_WinError_stdErr_Sin_Consola                0x20//
    #define LimpiarConsola_WinError_GetConsoleScreemBufferInfo_stdOut 0x03//
    #define LimpiarConsola_WinError_FillConsoleCharacterA_stdOut      0x04//
    #define LimpiarConsola_WinError_FillConsoleAttribute_stdOut       0x05//
    #define LimpiarConsola_WinError_SetCursor_stdOut                  0x06//
    #define LimpiarConsola_WinError_GetConsoleScreemBufferInfo_stdErr 0x30//
    #define LimpiarConsola_WinError_FillConsoleCharacterA_stdErr      0x40//
    #define LimpiarConsola_WinError_FillConsoleAttribute_stdErr       0x50//
    #define LimpiarConsola_WinError_SetCursor_stdErr                  0x60//
    /********************************************************************///
    #define LimpiarConsola_LixError_stdOut_Sin_Terminal               0X01//
    #define LimpiarConsola_LixError_Write_stdOut                      0x02//
    #define LimpiarConsola_LixError_stdErr_Sin_Terminal               0x10//
    #define LimpiarConsola_LixError_Write_stdErr                      0x20//
    ////////////////////////////////////////////////////////////////////////
     
    // Entrada(...);
    //////////////////////////////////////////////////////////////
    #define Entrada_Error_PunteroEstructura_NULL            0x01//
    #define Entrada_Error_Puntero_BufferEntrada_NULL        0x02//
    #define Entrada_Error_LongitudBuffer_Menor_A_Dos        0x03//
    #define Entrada_Error_CapturarTeclaUTF8                 0x04//
    #define Entrada_ErrorNOFATAL_Salida_Por_Tecla_Especial  0x05//
    #define Entrada_Error_LimpiarConsola                    0x06//
    #define Entrada_WinError_GetConsoleCP                   0x07//
    #define Entrada_WinError_GetConsoleOutputCP             0x08//
    #define Entrada_WinError_SetConsoleCP                   0x09//
    #define Entrada_WinError_SetConsoleOutputCP             0x0f//
    // TODO: EXPANDIR DEFINICIONES DE ERRORES DE 'Entrada' Y DE LA MISMA FUNCIÓN
     
    //////////////////////////////////////////////////////////////////////
    #define Escribir_Error_Param_Invalido                           0x01//
    #define Escribir_Error_Puntero_NULL                             0x02//
    #define Escribir_ErrorNOFATAL_Escritos_No_Iguales               0x05//
    /******************************************************************///
    #define Escribir_WinError_GetStdHandle                          0x03//
    #define Escribir_WinError_WriteFile                             0x04//
    /******************************************************************///
    #define Escribir_LixError_write                                 0x04//
    //////////////////////////////////////////////////////////////////////
   
    //=========================================================================
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
            union {
                BoolBit_t MOSTRAR_INDICADOR_DE_LONGITUD_USADA__BIT0;
                BoolBit_t MOSTRAR_PROMPT_DE_ENTRADA__BIT1;
            } Campo_Booleanos;
            union {
                BoolBit_t USAR_METODO_DE_SALIDA_CON_TECLA_ESPECIAL__BIT0;
                BoolBit_t INDICAR_METODO_DE_SALIDA_AL_USUARIO__BIT1;
            } Campo_Avanzados;
            char*  _PROMPT_DE_ENTRADA_TEXTO_C_;
            Byte_t _TECLA_ESPECIAL_DE_SALIDA_;
        } Campo_Configuracion;
    } ENTRADA_PARAMs;
     
     
       
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
    //=========================================================================
    void ImprimirTipoTecla(
        Byte_t TECLA_ESPECIAL_A_IMPRIMIR
    );
    //=========================================================================
    //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
    //=========================================================================
    Byte_t CapturarTeclaUTF8(
        EVENTO_TECLA* INFORMACION_DE_LA_TECLA
    );
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
        char*   _BUFFER_DE_TEXTO_C_,
        size_t  _CANTIDAD_DE_BYTES_A_ESCRIBIR_,
        Sint_t* _CANTIDAD_DE_BYTES_ESCRITOS_,
        Byte_t  _CONSOLA_STDOUT_O_STDERR_
    );
    //=========================================================================
    Sint_t Imprimir(
        const char* _TEXTO_C_,
        void* _PUNTERO_ARGUMENTO_O_NULL_
    );
     
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
#endif
