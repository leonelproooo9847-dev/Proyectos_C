// LibProcesosWin.h
#ifndef LIBPROCESOSWIN_H
    #define LIBPROCESOSWIN_H "V: 1.1 | NumCab: 2"

    #include "DefErrorWin.h"
    #include "GeneralCab.h"
    #include <stdint.h>


    //====================================================================
    // estructuras y definiciones de tipos:


    typedef void* MANEJADOR;
    typedef uint32_t DPALABRA;

    //--------------------------------------------------|

    typedef struct _PARAMETROS_DEL_PROCESO {
        char* DIRECCION_DEL_EJECUTABLE;
        char* LINEA_DE_COMANDOS;
        Bool_t ACTIVAR_CONFIGURACION;
        struct {
            Bool_t CREAR_VENTANA;
            struct {
                Bool_t PREDETERMINADOS;
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
        DPALABRA PROCESO_ID;
        DPALABRA HILO_ID;
    } INFORMACION_DEL_PROCESO;


    //====================================================================

#endif
