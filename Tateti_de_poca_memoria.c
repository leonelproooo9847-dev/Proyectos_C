#include <stdio.h>
#include <stdlib.h>
void nvl(){printf("\n");}
#if defined(_WIN32)
void limpiar(){system("cls");}
#else
void limpiar(){system("clear");}
#endif
// macros:
#define elif else if
#define ERROR 0b11111111

/****MASCARAS****/
// leer_cas
#define MASC1 0b11100000
#define MASC2 0b00011100
#define MASC3 0b00000011

// escribir_cas
#define MASC2_3 0b00011111
#define MASC1_3 0b11100011
#define MASC1_2 0b11111100

#define MASCI 0b00001111
#define MASCS 0b11110000

// pedir
#define EOF_PROGRAM 0b11111111
#define INICI 0b00000000

#define MASCT 0b00001111
#define MASCV 0b11110000

#define BASURA  0b00001111
#define userNUM 0b00000001
#define userS   0b00000010
#define userX   0b00000100
#define userO   0b00001000

// main
#define MASCTurno 0b01111111
#define turnoX    0b10000000
#define turnoO    0b00000000
#define turno     0b10000000
/****************/

#define codeX   0b00000001 // 1
#define codeO   0b00000010 // 2
#define codeNUM 0b00000011 // 3

typedef unsigned char Byte;

Byte tablero[3] = {
    0b01101111, 0b01101111, 0b01101111
    // equivale a: "ooo"
};

Byte leer_cas(
    Byte num
) {
    if (num < 1 || num > 9) {
        return ERROR;
    }

    if (num == 1 || num == 4 || num == 7) {
        if (num == 1) {
            return ((tablero[0]&MASC1)>>5);
        } elif (num == 4) {
            return ((tablero[1]&MASC1)>>5);
        } else {
            return ((tablero[2]&MASC1)>>5);
        }
    } elif (num == 2 || num == 5 || num == 8) {
        if (num == 2) {
            return ((tablero[0]&MASC2)>>2);
        } elif (num == 5) {
            return ((tablero[1]&MASC2)>>2);
        } else {
            return ((tablero[2]&MASC2)>>2);
        }
    } elif (num == 3 || num == 6 || num == 9) {
        if (num == 3) {
            return (tablero[0]&MASC3);
        } elif (num == 6) {
            return (tablero[1]&MASC3);
        } else {
            return (tablero[2]&MASC3);
        }
    }
}




void escribir_cas(
    Byte dato
    // dato: 0biiii-dddd
) {
    if (
        ((dato&MASCS)>>4) == 1 ||
        ((dato&MASCS)>>4) == 4 ||
        ((dato&MASCS)>>4) == 7
    ) {
        if (((dato&MASCS)>>4) == 1) {
            tablero[0] &= MASC2_3;
            tablero[0] |= ((dato&MASCI)<<5);
        } elif (((dato&MASCS)>>4) == 4) {
            tablero[1] &= MASC2_3;
            tablero[1] |= ((dato&MASCI)<<5);
        } elif (((dato&MASCS)>>4) == 7) {
            tablero[2] &= MASC2_3;
            tablero[2] |= ((dato&MASCI)<<5);
        }
    } elif (
        ((dato&MASCS)>>4) == 2 ||
        ((dato&MASCS)>>4) == 5 ||
        ((dato&MASCS)>>4) == 8
    ) {
        if (((dato&MASCS)>>4) == 2) {
            tablero[0] &= MASC1_3;
            tablero[0] |= ((dato&MASCI)<<2);
        } elif (((dato&MASCS)>>4) == 5) {
            tablero[1] &= MASC1_3;
            tablero[1] |= ((dato&MASCI)<<2);
        } elif (((dato&MASCS)>>4) == 8) {
            tablero[2] &= MASC1_3;
            tablero[2] |= ((dato&MASCI)<<2);
        }
    } elif (
        ((dato&MASCS)>>4) == 3 ||
        ((dato&MASCS)>>4) == 6 ||
        ((dato&MASCS)>>4) == 9
    ) {
        if (((dato&MASCS)>>4) == 3) {
            tablero[0] &= MASC1_2;
            tablero[0] |= (dato&MASCI);
        } elif (((dato&MASCS)>>4) == 6) {
            tablero[1] &= MASC1_2;
            tablero[1] |= (dato&MASCI);
        } elif (((dato&MASCS)>>4) == 9) {
            tablero[2] &= MASC1_2;
            tablero[2] |= (dato&MASCI);
        }
    }
}


Byte interpretar(
    Byte casilla
) {
    if (casilla == codeX) {
        return 'X';
    } elif (casilla == codeO) {
        return 'O';
    } elif (casilla == codeNUM) {
        return '0';
    }
    return ' ';  
}


void mostrar_tablero() {
    Byte i = 1;

    while (i <= 9) {
        if (interpretar(leer_cas(i)) == '0') {
            printf(" %c |", (interpretar(leer_cas(i))+i));
        } else {
            printf(" %c |", interpretar(leer_cas(i)));
        }
        i++;
        if (interpretar(leer_cas(i)) == '0') {
            printf(" %c |", (interpretar(leer_cas(i))+i));
        } else {
            printf(" %c |", interpretar(leer_cas(i)));
        }
        i++;
        if (interpretar(leer_cas(i)) == '0') {
            printf(" %c ", (interpretar(leer_cas(i))+i));
        } else {
            printf(" %c ", interpretar(leer_cas(i)));
        }
        i++;
        nvl();
        if (i < 9) {
            printf("---+---+---");
        }
        nvl();
    }
}

Byte pedir() {
    Byte C = '\0';
    Byte estado = INICI;
    
    /*
        ordenamiento de datos en 'estado':
            vvvv tttt

            vvvv: si es num, se almacena aquí  (almacenamiento)
            tttt: tipo X, O, S o 1 al 9        (tipo)
    */

    do {
        printf(">>> ");
        while ((C = (Byte)getchar()) != '\n' && C != EOF_PROGRAM) {
           
            if ((estado&MASCT) == 0) {
                if (C == ' ') {
                    continue;
                }
                if (C >= '1' && C <= '9') {
                    estado |= userNUM; // numero
                    estado |= ((C-'0')<<4);
                } elif (C == 'S' || C == 's') {
                    estado |= userS; // salir
                } elif (C == 'X' || C == 'x') {
                    estado |= userX; // X
                    // 0b00000100 == X
                } elif (C == 'O' || C == 'o') {
                    estado |= userO; // O
                    // 0b00001000 == O
                } else {
                    estado |= BASURA; // basura
                }
            } else {
                if ((estado&MASCT) != MASCT) {
                    if (C != ' ') {
                        estado = BASURA; // basura
                    }
                }
            }
        }
        if ((estado&MASCT) != BASURA) {
            if (estado&userNUM) {
                return (estado>>4);
            } else {
                if (estado&userS) {
                    return 'S';
                } elif (estado&userX) {
                    return 'X';
                } elif (estado&userO) {
                    return 'O';
                } else {
                    return ERROR;
                }
            }
        } else {
            estado &= INICI;
        }
        
    } while (1);

    return ERROR;
}

Byte termino_en(
    Byte EST_J
) {
    /*
    code = j iiiiiii
    j:         jugador actual
    iiiiiii:   espacio para iteraciones     
    */
    #define EMPATE      0b00001111
    #define Xgana       0b00000001
    #define Ogana       0b00000010
    #define NINGUNO     EST_J&turno
    #define I           (EST_J&MASCTurno)

    if (EST_J == turnoX) {
        EST_J = turnoO;
    } else {
        EST_J = turnoX;
    }
    
    if ((EST_J&turno) == turnoX) {
        EST_J &= turno;
        while (I < 9) {
            if (
                leer_cas(1+I) == codeX &&
                leer_cas(2+I) == codeX &&
                leer_cas(3+I) == codeX
            ) {
                return Xgana;
            }
            EST_J+=(Byte)3;
        }
        EST_J &= turno;
        while (I < 3) {
            if (
                leer_cas(1+I) == codeX &&
                leer_cas(4+I) == codeX &&
                leer_cas(7+I) == codeX
            ) {
                return Xgana;
            }
            EST_J+=(Byte)1;
        }
        EST_J &= turno;

        if (
            (
                leer_cas(1) == codeX &&
                leer_cas(5) == codeX &&
                leer_cas(9) == codeX
            ) || (
                leer_cas(7) == codeX &&
                leer_cas(5) == codeX &&
                leer_cas(3) == codeX
            )
        ) {
            return Xgana;
        }
        return NINGUNO;
    } else {
        EST_J &= turno;
        while (I < 9) {
            if (
                leer_cas(1+I) == codeO &&
                leer_cas(2+I) == codeO &&
                leer_cas(3+I) == codeO
            ) {
                return Ogana;
            }
            EST_J+=(Byte)3;
        }
        EST_J &= turno;
        while (I < 3) {
            if (
                leer_cas(1+I) == codeO &&
                leer_cas(4+I) == codeO &&
                leer_cas(7+I) == codeO
            ) {
                return Ogana;
            }
            EST_J+=(Byte)1;
        }
        EST_J &= turno;

        if (
            (
                leer_cas(1) == codeO &&
                leer_cas(5) == codeO &&
                leer_cas(9) == codeO
            ) || (
                leer_cas(7) == codeO &&
                leer_cas(5) == codeO &&
                leer_cas(3) == codeO
            )
        ) {
            return Ogana;
        }
        return NINGUNO;
    }

    #undef I
    #undef EMPATE 
    #undef Xgana  
    #undef Ogana  
    #undef NINGUNO
}


int main() {
    // tener en cuenta de ver los valores como numeros binarios internos.
    de_vuelta:
        tablero[0] = 0b01101111;  // se separa en 3 elementos, 011 | 011 | 11
        tablero[1] = 0b01101111;
        tablero[2] = 0b01101111;
        // equivalente a "ooo"
        /*
        solo hay:
            00 = ' '
            01 = 'X'
            10 = 'O'
            11 = '0' + indice_del_tablero
            el índice del tablero es hecho solo por la función mostrar_tablero.
        */
        limpiar();
    
    Byte user = '\0';
    Byte EST = 0b00000000;

    printf("elige [X | O | S]");
    nvl();  // salto de línea.
    
    do {
        user = pedir();
        /* pedir() devuelve:
        |
        ->     'S': si apretó S
        ->     'X': si apretó X
        ->     'O': si apretó O
        ->     1-9: si apretó las teclas del 1-9 y las resuelve dando solo el número lógico, no el caracter.
        */
        
        if (user == 'S') {
            goto salir;
        } elif (user == 'X' || user == 'O') {
            if (user == 'X') {
                EST = turnoX;
                // 0b10000000
            } else {
                EST = turnoO;
                // 0b00000000
            }
            break;
        }
    } while (1);
    user = '\0';
    // 0b00000000
    
    limpiar();
    
    while(1) {
        mostrar_tablero(); // void, no devuelve nada.
        
        if ((termino_en(EST)&MASCTurno)) {
            EST = termino_en(EST)&MASCTurno;
            /* termino_en() devuelve:
            |  EST & 0b01111111(MASCTurno):
            ->     0b00001111: empate
            ->     0b00000001: codeX
            ->     0b00000010: codeO
            ->     0b00000000: NINGUNO
            |      ^^^^^^^^^^: (en realidad devuelve el estado invertido al turno, pero MASCTurno lo borra y da un False lógico)
            */ 
            if (EST == codeX) {
                printf("Jugador X gana!!");
            } elif (EST == codeO) {
                printf("Jugador O gana!!");
            } else {
                printf("Empate!!");
            }
            nvl();
            goto preguntar;
        }
        
        if (EST == turnoX) {
            // 0b10000000(turnoX)
            printf("turno de X");
        } elif (EST == turnoO) {
            // 0b00000000(turnoO)
            printf("turno de O");
        }
        nvl();
        
        printf("elige la casilla o S (salir)");
        nvl();
        do {
            user = pedir();

            if (user == 'S') {
                goto salir;
            } elif (
                user == 'X' ||
                user == 'O' ||
                user == ERROR
            ) {
                user = '\0';
            } else {
                if (user >= 1)
                    break;
            }
        } while (1);
        
        if (!(leer_cas(user) < 3)) { // si la casilla no está ocupada 
            /* leer_cas() devuelve:
            |
            ->     0b00000001: codeX
            ->     0b00000010: codeO
            ->     0b00000011: '0' o equivalente a casilla vacía.
            */
        
            if (EST == turnoX) {
                escribir_cas(((user<<4)|codeX));
                /* lo que se le pasa a escribir_cas es:
                |      0biiiidddd
                veamos la lógica:
                    si por ejemplo, user vale 3, internamente al ser un caracter
                    se verá así:
                        0b00000011

                    la operación '<<4' indica que los bits se muevas hacia la izquierda.

                    el resultado es literalmente: 0b0000011 -> 0b00110000 (se movieron hacia la izquierda)

                    el operador | es un operador lógico que, resumiendo, agrega el dato que va a escribir en
                    la casilla según el túrno.

                    si, por ejemplo, el turno es de X entonces agrega solo 0b00000001 a 0b00110000

                    entonces se verá:
                        0b00110001

                    si en cambio es el turno de 0 entonces agrega solo 0b00000010 a 0b00110000

                    entonces se verá:
                        0b00110010

                    si te lo describo a palabras de cómo lo interpreta escribir_cas. queda:
                        "quier que en este número de casilla 0b0011, escribas estos datos nuevos 0b0010",

                        0011        |        0010
                        ^^^^                 ^^^^
                        le dice              le dice
                        a donde              qué quiere escribir.
                */
                EST = turnoO;
            } elif (EST == turnoO) {
                escribir_cas(((user<<4)|codeO));
                EST = turnoX;
            }
        }
        
        limpiar();
        user = '\0';
    }

    preguntar:
        user = '\0';
        printf("volver a jugar? [X|O]");
        nvl();
        do {
            user = pedir();
            if (user == 'X') {
                goto salir;
            } elif (user == 'O') {
                goto de_vuelta;
            } else {
                user = '\0';
            }
        } while (1);
    
    salir:
        return 0;
}
