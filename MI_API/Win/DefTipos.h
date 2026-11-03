// DefTipos.h
#ifndef TIPOS_CAB_H
    #define TIPOS_CAB_H "V: 2.0.5 | NumCab: 6"

    #define SOLO_64BIT_SIN_SIGNO 2
    #define SOLO_64BIT_CON_SIGNO 3
    /* @attention: Esta cabecera no- *\
    |  garantiza seguridad y consis-  |
    |  tencia entre implementaciones. |
    |                                 |
    |  @note: Esta cabecera solo      |
    |  será en español.               |
    |                                 |
    |  pd: Me cuesta hacerlo en el    |
    |  celular :P                     |
    \*                               */ 

    #if defined(__GNUC__) || defined(__clang__)

        #if __CHAR_BIT__ == 8
            // Con Signos
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            #ifdef __INT8_TYPE__
                typedef __INT8_TYPE__ S8;
            #else
                #error "'__INT8_TYPE__' no está definido"
            #endif

            #ifdef __INT16_TYPE__
                typedef __INT16_TYPE__ S16;
            #else
                #error "'__INT16_TYPE__' no está definido"
            #endif

            #ifdef __INT32_TYPE__
                typedef __INT32_TYPE__ S32;
            #else
                #error "'__INT32_TYPE__' no está definido"
            #endif

            #ifdef __INT64_TYPE__
                typedef __INT64_TYPE__ S64;
            #else
                #warning "'__INT64_TYPE__' no está definido por el compilador. Esto no es un error"
            #endif
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII


            // Sin Signos
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            #ifdef __UINT8_TYPE__
                typedef __UINT8_TYPE__ U8;
            #else
                #error "'__UINT8_TYPE__' no está definido"
            #endif

            #ifdef __UINT16_TYPE__
                typedef __UINT16_TYPE__ U16;
            #else
                #error "'__UINT16_TYPE__' no está definido"
            #endif

            #ifdef __UINT32_TYPE__
                typedef __UINT32_TYPE__ U32;
            #else
                #error "'__UINT32_TYPE__' no está definido"
            #endif

            #ifdef __SIZE_TYPE__
                typedef __SIZE_TYPE__ size_t;
            #else
                #error "'__SIZE_TYPE__' no está definido"
            #endif

            #ifdef __UINT64_TYPE__
                typedef __UINT64_TYPE__ U64;
                #define UINT64_DIS_AVA 1
            #else
                #warning "'__UINT64_TYPE__' no está definido por el compilador. Esto no es un error"
            #endif

            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
        
            #if defined(__INT64_TYPE__) && defined(__UINT64_TYPE__)
                #define ESTA_DISPONIBLE_64BIT 1
            #elif defined(__INT64_TYPE__) && !(defined(__UINT64_TYPE__))
                #define ESTA_DISPONIBLE_64BIT SOLO_64BIT_CON_SIGNO
            #elif !(defined(__INT64_TYPE__)) && defined(__UINT64_TYPE__)
                #define ESTA_DISPONIBLE_64BIT SOLO_64BIT_SIN_SIGNO
            #else
                #define ESTA_DISPONIBLE_64BIT 0
            #endif
        #else
            #error "'__CHAR_BIT__' no es de 8 bit"
        #endif
    #elif defined(_MSC_VER)
        // TODO: COMPLETAR PARA MSVC
    #else
        #error "Sin soporte para este compilador"
    #endif
#endif
