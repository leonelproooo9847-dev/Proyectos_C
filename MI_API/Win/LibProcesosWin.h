// LibProcesosWin.h
#ifndef LIBPROCESOSWIN_H
    #define LIBPROCESOSWIN_H 3

    #include "GeneralCab.h"


    //====================================================================
    // estructuras y definiciones de tipos:


    typedef void* MANEJADOR;

    //--------------------------------------------------|

    typedef struct _PARAMETROS_DEL_PROCESO {
        char* DIRECCION_DEL_EJECUTABLE;
        char* LINEA_DE_ARGUMENTOS;
        struct {
            Bool_t CREAR_VENTANA;
            struct {
                Uint_t POS_EJE_Y;
                Uint_t POS_EJE_X;
                Uint_t TAM_EJE_Y;
                Uint_t TAM_EJE_X;
            } Campo_dimenciones_de_ventana;
            Bool_t NOMBRAR_VENTANA;
            char* NOMBRE_DE_LA_VENTANA;
        } Campo_configuracion;
    } PARAMETROS_DEL_PROCESO;

    //--------------------------------------------------|

    typedef struct _INFORMACION_DEL_PROCESO {
        struct { // no es necesario que lo vea el programador
            MANEJADOR MANEJADOR_DEL_PROCESO;
            MANEJADOR MANEJADOR_DEL_HILO;
        } Campo_manejadores;
        Uint_t PROCESO_ID;
        Uint_t HILO_ID;
    } INFORMACION_DEL_PROCESO;


    //====================================================================

#endif
