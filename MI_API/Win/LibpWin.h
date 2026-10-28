// LIBPWIN_H
#ifndef LIBPWIN_H

    #define LIBPWIN_H "V: 1.5 | NumCab: 1"
    #include <stdint.h>
    #include "GeneralCab.h"
    #include "DefErrorWin.h"

    //=========================================================================
    //definiciones

    #define CodPag_ANSI_Predet      0x01
    #define CodPag_OEM_Predet       0x02
    #define CodPag_Macintosh        0x03
    #define CodPag_ANSI_SubProceso  0x04
    #define CodPag_Simbolos         0x05
    #define CodPag_UTF7             0x06
    #define CodPag_UTF8             0x07
    #define CodPag_INDETERMINADO    0xff

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
    //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
    //=========================================================================
    Byte_t CapturarTeclaUTF8(
        EVENTO_TECLA* INFORMACION_DE_LA_TECLA
    );
    //=========================================================================
    Byte_t CambiarCodigoDePagina(
        Byte_t _CODIGO_DE_PAGINA_,
        Byte_t _CONSOLA_A_CAMBIAR_
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
