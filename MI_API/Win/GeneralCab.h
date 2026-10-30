// GeneralCab.h
#ifndef GNRALCAB_H
    #define GNRALCAB_H "V: 1.2 | NumCab: 3"
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

    #define CONSOLA_OUTPUT 0x03 // 00000011
    #define CONSOLA_INPUT  0x3c // 00111100
    #define CONSOLA_ERROR  0xc0 // 11000000
#endif
