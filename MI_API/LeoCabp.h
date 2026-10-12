// LEOCABp_H
#ifndef LEOCABp_H
 
    #define LEOCABp_H 1
     
    //=========================================================================
    //definiciones
     
    #define Verdadero  0x01  
    #define Falso      0x00  
     
    #define Si Verdadero  
    #define No Falso  
     
    typedef signed   int  Sint_t;
    typedef unsigned int  Uint_t;
    typedef unsigned char Byte_t;
    typedef unsigned char Bool_t;
    typedef unsigned char BoolBit_t;  
     
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
     
    #if LEO_OS < WINDOWS_GNRAL
        #include <windows.h>
    #else
        #include <unistd.h>
        #include <termios.h>
    #endif
 
     
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
 
    #define LIMPIAR_CONSOLA_OUTPUT 0x0f
    #define LIMPIAR_CONSOLA_ERROR  0xf0
     
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
     
    //////////////////////////////////////////////
    #define Escribir_Error                  0x01//
    #define Escribir_WinError_GetStdHandle  0x02//
    //////////////////////////////////////////////
   
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
 
    Byte_t REGISTRO_Imprimir = 0;
    Byte_t REGISTRO_Escribir = 0;
    Byte_t REGISTRO_LimpiarConsola = 0;
 
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
                BoolBit_t MOSTRAR_INDICADOR_POR_ACTUALIZACION_DE_CONSOLA__BIT1;
                BoolBit_t MOSTRAR_INDICADOR_POR_PROCESO_EFICIENTE__BIT2;
                BoolBit_t MOSTRAR_PROMPT_DE_ENTRADA__BIT3;
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
     
    static Byte_t SacarDirectorioActual(
        char*  __UBICACION_ACTUAL_DE_ESTE_ARCHIVO__entrada,
        char*  __UBICACION_MODIFICADA__resultado,
        size_t __LONGITUD_DEL_BUFFER_DE_RESULTADO__,
        Bool_t __DEJAR_BARRA_INVERTIDA__
    );
    //=========================================================================
    static Byte_t LimpiarBuffer(
        Byte_t*     _ESTRUCTURA_,
        size_t      _CANTIDAD_DE_BYTES_
    );
    //=========================================================================
    static Byte_t TipoReprDeSignos();
    //=========================================================================
    static Byte_t CopiarBuffer(
        void* BUFFER_ORIGEN,
        void* BUFFER_DESTINO,
        size_t LONGITUD_DEL_BUFFER_ORIGEN,
        size_t LONGITUD_DEL_BUFFER_DESTINO
    );
    //=========================================================================
    static void ImprimirTipoTecla(
        Byte_t TECLA_ESPECIAL_A_IMPRIMIR
    );
    //=========================================================================
    //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
    //=========================================================================
    static Byte_t CapturarTeclaUTF8(
        EVENTO_TECLA* INFORMACION_DE_LA_TECLA
    );
    //=========================================================================
    static Byte_t LimpiarConsola(
        Byte_t CONSOLA_A_LIMPIAR
    );
    //=========================================================================
    static Byte_t Entrada(
        ENTRADA_PARAMs* _CONFIGURACIONES_Y_PARAMETROS_
    );
    //=========================================================================
    static Byte_t Escribir(
        char*   _BUFFER_DE_TEXTO_C_,
        size_t  _CANTIDAD_DE_BYTES_A_ESCRIBIR_,
        Sint_t* _CANTIDAD_DE_BYTES_ESCRITOS_
    );
    //=========================================================================
    static Sint_t Imprimir(
        const char* _TEXTO_C_,
        void* _PUNTERO_ARGUMENTO_O_NULL_
    );
     
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
   
    static Byte_t SacarDirectorioActual(
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
     
       
    static Byte_t LimpiarBuffer(
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
     
     
    static Byte_t TipoReprDeSignos() {
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
     
     
    static Byte_t CopiarBuffer(
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
            size_t i = 0;
            while (i < LONGITUD_DEL_BUFFER_DESTINO) {
                if ((BUFFER_DESTINO+i) == BUFFER_ORIGEN)
                    return CopiarBuffer_Error_Solapamiento_Buffers_Destino_Origen;
                i++;
            }
            i = 0;
            while (i < LONGITUD_DEL_BUFFER_ORIGEN) {
                if ((BUFFER_ORIGEN+i) == BUFFER_DESTINO)
                    return CopiarBuffer_Error_Solapamiento_Buffers_Origen_Destino;
                i++;
            }
        } else return CopiarBuffer_Error_Mismos_Punteros_Origen_Destino;
 
        size_t i = 0;
        while (
            i < LONGITUD_DEL_BUFFER_DESTINO &&
            i < LONGITUD_DEL_BUFFER_ORIGEN
        ) {
            *((Byte_t*)BUFFER_DESTINO) = *((Byte_t*)BUFFER_ORIGEN);
            i++;
        }
         
        return 0;
    }
     
     
    /*----------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------*/
     
     
    static void ImprimirTipoTecla(
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
 
 
    // TODO: expandir para Linux
    static Byte_t CapturarTeclaUTF8(
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
 
        #if LEO_OS < WINDOWS_GNRAL
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
                ) return CapturarTeclaUTF8_WinError_ReadConsoleInputW;
 
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
                                            return CapturarTeclaUTF8_WinError_Lectura_De_Par_Suplente__Suplente_No_Correspondiente; 
                                    } else
                                        return CapturarTeclaUTF8_WinError_Lectura_De_Par_Suplente__KeyDown_Falso;
                                } else
                                    return CapturarTeclaUTF8_WinError_Lectura_De_Par_Suplente__Sin_KeyEvent;
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
             
        #else
            struct termios antes, ahora;
           
            tcgetattr(STDIN_FILENO, &antes);
           
            ahora = antes;
           
            ahora.c_lflag &= ~(ICANON | ECHO);
           
            tcsetattr(STDIN_FILENO, TCSANOW, &ahora);
        #endif
        #undef dtecla
        #undef dinfo
        return 0;
    }
     
     
    /*----------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------*/
 
 
    static Byte_t LimpiarConsola(
        Byte_t CONSOLA_A_LIMPIAR
    ) {
        #if LEO_OS < WINDOWS_GNRAL
            //implementacio de Windows
            HANDLE Salida_Estandar = NULL;
            HANDLE Error_Estandar  = NULL;
             
            if (CONSOLA_A_LIMPIAR == LIMPIAR_CONSOLA_OUTPUT) {
                Salida_Estandar = GetStdHandle(STD_OUTPUT_HANDLE);
                if (
                    Salida_Estandar == INVALID_HANDLE_VALUE ||
                    Salida_Estandar == NULL
                ) return LimpiarConsola_WinError_GetStdHandle_stdOut;
                {
                    DWORD Modo = 0;
                    if (GetConsoleMode(Salida_Estandar, &Modo) == FALSE)
                        return LimpiarConsola_WinError_stdOut_Sin_Consola;
                }
                 
                CONSOLE_SCREEN_BUFFER_INFO informacion_buffer_consola = {0};
                DWORD cantidad = 0;
                COORD inicio = {0, 0};
 
                if (GetConsoleScreenBufferInfo(Salida_Estandar, &informacion_buffer_consola) == FALSE)
                    return LimpiarConsola_WinError_GetConsoleScreemBufferInfo_stdOut;
 
                DWORD Area_total = ((DWORD)informacion_buffer_consola.dwSize.Y) * ((DWORD)informacion_buffer_consola.dwSize.X);
 
                if (FillConsoleOutputCharacterA(
                    Salida_Estandar,
                    ' ',
                    Area_total,
                    inicio,
                    &cantidad
                ) == FALSE) return LimpiarConsola_WinError_FillConsoleCharacterA_stdOut;
             
                if (FillConsoleOutputAttribute(
                    Salida_Estandar,
                    informacion_buffer_consola.wAttributes,
                    Area_total,
                    inicio,
                    &cantidad
                ) == FALSE) return LimpiarConsola_WinError_FillConsoleAttribute_stdOut;
 
                if (SetConsoleCursorPosition(
                    Salida_Estandar,
                    inicio
                ) == FALSE) return LimpiarConsola_WinError_SetCursor_stdOut;
                 
            } else if (CONSOLA_A_LIMPIAR == LIMPIAR_CONSOLA_ERROR) {
                Error_Estandar  = GetStdHandle(STD_ERROR_HANDLE);
                if (
                    Error_Estandar == INVALID_HANDLE_VALUE ||
                    Error_Estandar == NULL
                ) return LimpiarConsola_WinError_GetStdHandle_stdErr;
                {
                    DWORD Modo = 0;
                    if (GetConsoleMode(Error_Estandar, &Modo) == FALSE)
                        return LimpiarConsola_WinError_stdErr_Sin_Consola;
                }
 
                CONSOLE_SCREEN_BUFFER_INFO informacion_buffer_consola = {0};
                DWORD cantidad = 0;
                COORD inicio = {0, 0};
 
                if (GetConsoleScreenBufferInfo(Error_Estandar, &informacion_buffer_consola) == FALSE)
                    return LimpiarConsola_WinError_GetConsoleScreemBufferInfo_stdErr;
 
                DWORD Area_total = ((DWORD)informacion_buffer_consola.dwSize.Y) * ((DWORD)informacion_buffer_consola.dwSize.X);
 
                if (FillConsoleOutputCharacterA(
                    Error_Estandar,
                    ' ',
                    Area_total,
                    inicio,
                    &cantidad
                ) == FALSE) return LimpiarConsola_WinError_FillConsoleCharacterA_stdErr;
               
                if (FillConsoleOutputAttribute(
                    Error_Estandar,
                    informacion_buffer_consola.wAttributes,
                    Area_total,
                    inicio,
                    &cantidad
                ) == FALSE) return LimpiarConsola_WinError_FillConsoleAttribute_stdErr;
 
                if (SetConsoleCursorPosition(
                    Error_Estandar,
                    inicio
                ) == FALSE) return LimpiarConsola_WinError_SetCursor_stdErr;
                 
            } else return LimpiarConsola_Error_Parametro_Invalido;
           
 
            return 0;
        #else
            int Descriptor = 0;
            if (CONSOLA_A_LIMPIAR == LIMPIAR_CONSOLA_OUTPUT)
                Descriptor = STDOUT_FILENO;
            else if (CONSOLA_A_LIMPIAR == LIMPIAR_CONSOLA_ERROR)
                Descriptor = STDERR_FILENO;
            else return LimpiarConsola_Error_Parametro_Invalido;
 
            if (isatty(Descriptor) == 0) {
                if (Descriptor == STDOUT_FILENO)
                    return LimpiarConsola_LixError_stdOut_Sin_Terminal;
                else
                    return LimpiarConsola_LixError_stdErr_Sin_Terminal;
            }
 
            const char Secuencia_Para_Limpiar[] = "\033[2J\033[H";
 
            if (
                write(
                    Descriptor,
                    Secuencia_Para_Limpiar,
                    8
                ) < 0
            ) {
                if (Descriptor == STDOUT_FILENO)
                    return LimpiarConsola_LixError_Write_stdOut;
                else
                    return LimpiarConsola_LixError_Write_stdErr;
            }
 
            return 0;
        #endif
       
    }
 
     
    /*----------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------*/
 
     
    static Byte_t Entrada(
        ENTRADA_PARAMs* _CONFIGURACIONES_Y_PARAMETROS_
    ) {
         
        #define dConfParams (*_CONFIGURACIONES_Y_PARAMETROS_)
        #define BIT_0       0x01
        #define BIT_1       0X02
        #define BIT_2       0x04
        #define BIT_3       0x08


        #if LEO_OS < WINDOWS_GNRAL
            UINT entrada_antes;
            UINT salida_antes;
            if ((entrada_antes = GetConsoleCP()) == 0)
                return Entrada_WinError_GetConsoleCP;
            if ((salida_antes = GetConsoleOutputCP()) == 0)
                return Entrada_WinError_GetConsoleOutputCP;
            
            if (SetConsoleCP(CP_UTF8) == FALSE)
                return Entrada_WinError_SetConsoleCP;
            if (SetConsoleOutputCP(CP_UTF8) == FALSE)
                return Entrada_WinError_SetConsoleOutputCP;
        #else
            /* ... */
        #endif
 
        if (_CONFIGURACIONES_Y_PARAMETROS_ == NULL)
            return GENERAL_Error_Puntero_NULL;
 
        if (dConfParams._PUNTERO_BUFFER_DE_ENTRADA_ == NULL)
            return Entrada_Error_Puntero_BufferEntrada_NULL;
        
        char* buffer = dConfParams._PUNTERO_BUFFER_DE_ENTRADA_;
 
        if (dConfParams._LONGITUD_DEL_BUFFER_ < 2)
            return Entrada_Error_LongitudBuffer_Menor_A_Dos;
        
        size_t longitud = dConfParams._LONGITUD_DEL_BUFFER_;

        if (dConfParams._PERMITIR_CONFIGURACION_ == Si) {
            
            Bool_t prompt_predeterminado    = No;
            Bool_t mostrar_indicador        = No;
            Bool_t por_actualizacion        = No;
            Bool_t por_eficiencia           = No;
            Bool_t mostrar_prompt           = No;
            Bool_t usar_salida_especial     = No;
            Bool_t indicar_metodo_de_salida = No;
            Byte_t metodo = 0;

            if (
                (dConfParams.Campo_Configuracion.Campo_Booleanos.MOSTRAR_INDICADOR_DE_LONGITUD_USADA__BIT0 & BIT_0)
            ) mostrar_indicador = Si;
             
            if (mostrar_indicador) {
                if (
                    (dConfParams.Campo_Configuracion.Campo_Booleanos.MOSTRAR_INDICADOR_POR_ACTUALIZACION_DE_CONSOLA__BIT1 & BIT_1)
                ) por_actualizacion = Si;
                 
                if (
                    (
                        (dConfParams.Campo_Configuracion.Campo_Booleanos.MOSTRAR_INDICADOR_POR_PROCESO_EFICIENTE__BIT2 & BIT_2)
                    ) && (por_actualizacion == No)
                ) por_eficiencia = Si;
 
                if (por_actualizacion == No && por_eficiencia == No)
                    mostrar_indicador = No;
            }
             
            if (
                (dConfParams.Campo_Configuracion.Campo_Booleanos.MOSTRAR_PROMPT_DE_ENTRADA__BIT3 & BIT_3)
            ) mostrar_prompt = Si;
             
            if (mostrar_prompt == Si) {
                if (dConfParams.Campo_Configuracion._PROMPT_DE_ENTRADA_TEXTO_C_ == NULL)
                    prompt_predeterminado = Si;
            }

            if (
                (dConfParams.Campo_Configuracion.Campo_Avanzados.USAR_METODO_DE_SALIDA_CON_TECLA_ESPECIAL__BIT0 & BIT_0)
            ) usar_salida_especial = Si;

            if (
                (dConfParams.Campo_Configuracion._TECLA_ESPECIAL_DE_SALIDA_)
                !=
                TECLA_CARACTER
            ) metodo = dConfParams.Campo_Configuracion._TECLA_ESPECIAL_DE_SALIDA_;
            else metodo = TECLA_TAB;

            if (
                (dConfParams.Campo_Configuracion.Campo_Avanzados.INDICAR_METODO_DE_SALIDA_AL_USUARIO__BIT1 & BIT_1)
            ) indicar_metodo_de_salida = Si;
         
             
            EVENTO_TECLA evento = {0};
            size_t i = 0;
            if (mostrar_indicador) {
                if (por_actualizacion) {
                    while (1) {
                        if (LimpiarConsola(LIMPIAR_CONSOLA_OUTPUT) != 0)
                            return Entrada_Error_LimpiarConsola;
                        
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
                                Imprimir("%s", (void*)(dConfParams.Campo_Configuracion._PROMPT_DE_ENTRADA_TEXTO_C_));
                        }

                        Imprimir("%s", (void*)buffer);

                        do {
                            if (CapturarTeclaUTF8(&evento))
                                return Entrada_Error_CapturarTeclaUTF8;
                             
                            if (usar_salida_especial) {
                                if (evento.TIPO_DE_EVENTO == metodo)
                                    return Entrada_ErrorNOFATAL_Salida_Por_Tecla_Especial;
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
                    /* ... */
                }
            } else {
                if (indicar_metodo_de_salida) {
                    Imprimir("[", NULL);
                    ImprimirTipoTecla(metodo);
                    Imprimir("]: salir\n", NULL);
                }
                if (mostrar_prompt) {
                    if (prompt_predeterminado)
                        Imprimir(">>> ", NULL);
                    else
                        Imprimir("%s", (void*)(dConfParams.Campo_Configuracion._PROMPT_DE_ENTRADA_TEXTO_C_));
                }
                while (1) {
                     
                    do {
                        if (CapturarTeclaUTF8(&evento))
                            return Entrada_Error_CapturarTeclaUTF8;
                         
                        if (usar_salida_especial) {
                            if (evento.TIPO_DE_EVENTO == metodo)
                                return Entrada_ErrorNOFATAL_Salida_Por_Tecla_Especial;
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
                    if (CapturarTeclaUTF8(&evento))
                        return Entrada_Error_CapturarTeclaUTF8;
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
        
        #if LEO_OS < WINDOWS_GNRAL
        if (SetConsoleCP(entrada_antes) == FALSE)
            return Entrada_WinError_SetConsoleCP;
        if (SetConsoleOutputCP(salida_antes) == FALSE)
            return Entrada_WinError_SetConsoleOutputCP;
        #else
            /* ... */
        #endif

        #undef dConfParams
        #undef BIT_0
        #undef BIT_1
        #undef BIT_2
        #undef BIT_3

        return 0x00;
    }
 
 
    /*----------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------*/
     
   
    static Byte_t Escribir(
        char*   _BUFFER_DE_TEXTO_C_,
        size_t  _CANTIDAD_DE_BYTES_A_ESCRIBIR_,
        Sint_t* _CANTIDAD_DE_BYTES_ESCRITOS_
    ) {
        if (_BUFFER_DE_TEXTO_C_ == NULL)
            return Falso;
   
        Byte_t retorno = 0;
         
        #if LEO_OS < WINDOWS_GNRAL
            DWORD escritos = 0;
            HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
            if (
                consola == INVALID_HANDLE_VALUE ||
                consola == NULL
            ) return Escribir_WinError_GetStdHandle;
       
            retorno = (Bool_t)WriteFile(
                consola,
                _BUFFER_DE_TEXTO_C_,
                (DWORD)_CANTIDAD_DE_BYTES_A_ESCRIBIR_,
                &escritos,
                NULL
            );
       
            if (!retorno && escritos != (DWORD)_CANTIDAD_DE_BYTES_A_ESCRIBIR_)
                retorno = Escribir_Error;
            else
                retorno = 0;
        #else
            ssize_t escritos = write(
                STDOUT_FILENO,
                _BUFFER_DE_TEXTO_C_,
                _CANTIDAD_DE_BYTES_A_ESCRIBIR_
            );
            if (escritos == -1 || escritos != _CANTIDAD_DE_BYTES_A_ESCRIBIR_)
                retorno = Escribir_Error;
            else
                retorno = 0;
        #endif
     
        if (_CANTIDAD_DE_BYTES_ESCRITOS_ != NULL)
            *_CANTIDAD_DE_BYTES_ESCRITOS_ += (Sint_t)escritos;
         
        return retorno;
    }
   
   
    /*----------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------*/
 
 
    static Sint_t Imprimir(
        const char* _TEXTO_C_,
        void* _PUNTERO_ARGUMENTO_O_NULL_
    ) {
        #define C(iterador) _TEXTO_C_[bytes+iterador]
        if (_TEXTO_C_ == NULL)
            return 0;
   
        Uint_t bytes = 0;
        Sint_t Cantidad_escritos = 0;  
   
        while (1) {
            if (_TEXTO_C_[bytes] == 0x00) {  
                break;  
            } else {
                if (_TEXTO_C_[bytes] == '%') {
                    Bool_t exito = Si;
 
                    goto saltear_logica_puntero_nulo;
                     
                    puntero_nulo:


                    if (Escribir("NULL", 4, NULL) != 0)
                        return -(Cantidad_escritos);
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
                            if (
                                Escribir(
                                    &(_nuevo_TEXTO_C_[i]),  
                                    1,
                                    (&Cantidad_escritos)
                                ) != 0
                            ) return -(Cantidad_escritos);
                            i++;  
                        }  
                    } else if (_TEXTO_C_[bytes+1] == 'c' || _TEXTO_C_[bytes+1] == 'C') {  
                        if (_PUNTERO_ARGUMENTO_O_NULL_ == NULL)  
                            goto puntero_nulo;  
                       
                        char _nuevo_caracter_ = *((char*)(_PUNTERO_ARGUMENTO_O_NULL_));  
                   
                        if (
                            Escribir(
                                &_nuevo_caracter_,  
                                1,
                                (&Cantidad_escritos)
                            ) != 0
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
     
                            if (
                                Escribir(
                                    nibble,  
                                    1,
                                    (&Cantidad_escritos)
                                ) != 0
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
                                if (
                                    Escribir(
                                        "1",  
                                        1,
                                        (&Cantidad_escritos)
                                    ) != 0
                                ) return -(Cantidad_escritos);
                            } else {  
                                if (
                                    Escribir(
                                        "0",  
                                        1,
                                        (&Cantidad_escritos)
                                    ) != 0
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
                            if (
                                Escribir(
                                    &(numero_texto[i]),
                                    1,
                                    (&Cantidad_escritos)
                                ) != 0
                            ) return -(Cantidad_escritos);
                        }
                    }
                    else {  
                        no_exito:
                        if (
                            Escribir(
                                (char*)&(_TEXTO_C_[bytes]),  
                                1,
                                (&Cantidad_escritos)
                            ) != 0
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
                    if (
                        Escribir(
                            (char*)&(_TEXTO_C_[bytes]),  
                            1,
                            (&Cantidad_escritos)
                        ) != 0
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
#endif
