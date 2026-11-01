// LibProcesosWin.h
#ifndef LIB_PROCESOS_WIN_H
    #define LIB_PROCESOS_WIN_H "V: 1.4.5 | NumCab: 2"

    #include "DefErrorWin.h"
    #include "DefGeneral.h"

    #define TODAS_LAS_CONSOLAS (CONSOLA_ERROR | CONSOLA_INPUT | CONSOLA_OUTPUT)

    //====================================================================
    // estructuras y definiciones de tipos:


    typedef void* MANEJADOR;


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
                Bool_t HEREDAR_FLUJO_OUTPUT;
                Bool_t HEREDAR_FLUJO_ERROR;
                Bool_t HEREDAR_FLUJO_INPUT;
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
