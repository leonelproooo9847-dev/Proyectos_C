// LibProcesosWin.h
#ifndef LIBPROCESOSWIN_H
    #define LIBPROCESOSWIN_H "V: 1.3 | NumCab: 2"

    #include "DefErrorWin.h"
    #include "GeneralCab.h"
    #include <stdint.h>

    #define TODAS_LAS_CONSOLAS (CONSOLA_ERROR | CONSOLA_INPUT | CONSOLA_OUTPUT)


    //====================================================================
    // estructuras y definiciones de tipos:


    typedef void* MANEJADOR;
    typedef uint32_t U32;

    //--------------------------------------------------|

    typedef struct _PARAMETROS_DEL_PROCESO {
        char* _DIRECCION_DEL_EJECUTABLE_;
        char* _LINEA_DE_COMANDOS_;
        Bool_t ACTIVAR_CONFIGURACION;
        struct {
            Bool_t CREAR_VENTANA;
            struct {
                Bool_t PREDETERMINADOS;
                U32 _POS_EJE_Y_;
                U32 _POS_EJE_X_;
                U32 _TAM_EJE_Y_;
                U32 _TAM_EJE_X_;
            } Campo_dimenciones_de_ventana;
            Bool_t NOMBRAR_VENTANA;
            char* _NOMBRE_DE_LA_VENTANA_;
            Bool_t PERMITIR_HERENCIA_DE_CONSOLA;
            struct {
                Bool_t HEREDAR_CONSOLA_OUTPUT;
                Bool_t HEREDAR_CONSOLA_ERROR;
                Bool_t HEREDAR_CONSOLA_INPUT;
                Byte_t FORZAR_LA_HERENCIA_EN;
            } Campo_herencias;
        } Campo_configuracion;
    } PARAMETROS_DEL_PROCESO;

    //--------------------------------------------------|

    typedef struct _INFORMACION_DEL_PROCESO {
        struct { // no es necesario que lo vea el programador
            MANEJADOR MANEJADOR_DEL_PROCESO;
            MANEJADOR MANEJADOR_DEL_HILO;
        } Campo_manejadores;
        U32 PROCESO_ID;
        U32 HILO_ID;
    } INFORMACION_DEL_PROCESO;


    //====================================================================

#endif
