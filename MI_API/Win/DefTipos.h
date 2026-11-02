// DefTipos.h
#ifndef TIPOS_CAB_H
    #define TIPOS_CAB_H "V: 1.7 | NumCab: 6"

    // @attention: Sin seguridad adecuada entre implementaciones.

    #if defined(__GNUC__) || defined(__clang__)

        #if __CHAR_BIT__ == 8
            // Con Signos
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            #ifdef __INT8_TYPE__
                typedef __INT8_TYPE__ S8;
            #else
                #error "'__INT8_TYPE__' is not defined | '__INT8_TYPE__' no está definido"
            #endif

            #ifdef __INT16_TYPE__
                typedef __INT16_TYPE__ S16;
            #else
                #error "'__INT16_TYPE__' is not defined | '__INT16_TYPE__' no está definido"
            #endif

            #ifdef __INT32_TYPE__
                typedef __INT32_TYPE__ S32;
            #else
                #error "'__INT32_TYPE__' is not defined | '__INT32_TYPE__' no está definido"
            #endif

            #ifdef __INT64_TYPE__
                typedef __INT64_TYPE__ S64;
                #define INT64_DIS_AVA 1
            #else
                #warning "'__INT64_TYPE__' is not defined by compiler. This is not an error | '__INT64_TYPE__' no está definido por el compilador. Esto no es un error"
            #endif
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII


            // Sin Signos
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            #ifdef __UINT8_TYPE__
                typedef __UINT8_TYPE__ U8;
            #else
                #error "'__UINT8_TYPE__' is not defined | '__UINT8_TYPE__' no está definido"
            #endif

            #ifdef __UINT16_TYPE__
                typedef __UINT16_TYPE__ U16;
            #else
                #error "'__UINT16_TYPE__' is not defined | '__UINT16_TYPE__' no está definido"
            #endif

            #ifdef __UINT32_TYPE__
                typedef __UINT32_TYPE__ U32;
            #else
                #error "'__UINT32_TYPE__' is not defined | '__UINT32_TYPE__' no está definido"
            #endif

            #ifdef __SIZE_TYPE__
                typedef __SIZE_TYPE__ size_t;
            #else
                #error "'__SIZE_TYPE__' is not defined | '__SIZE_TYPE__' no está definido"
            #endif

            #ifdef __UINT64_TYPE__
                typedef __UINT64_TYPE__ U64;
                #define UINT64_DIS_AVA 1
            #else
                #warning "'__UINT64_TYPE__' is not defined by compiler. This is not an error | '__UINT64_TYPE__' no está definido por el compilador. Esto no es un error"
            #endif

            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
            //IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
        #else
            #error "'__CHAR_BIT__' is not of 8 bit / '__CHAR_BIT__' no es de 8 bit"
        #endif
    #elif defined(_MSC_VER)
        // TODO: COMPLETAR PARA MSVC
    #else
        #error "Unsupported compiler | Sin soporte para este compilador"
    #endif
#endif
