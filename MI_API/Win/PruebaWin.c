#include "LibpWin.h"

int main() {

    char texto[] = "algo_1\0algo_2\0algo_3\0algo_4\0\0";
    size_t lista[4] = {0};
    Byte_t error = 0;

    COMPROBACION_PARAMs params = {0};

    params.Campo_datos_de_entrada._LISTA_DE_TEXTO_C_ = texto;
    params.Campo_datos_de_entrada._LONGITUD_DE_LA_LISTA_ = 29;

    params.Campo_datos_de_salida._CANTIDAD_DE_SIZEs_ = 3;
    params.Campo_datos_de_salida._LISTA_DE_SIZEs__GUARDADO_DE_INDICES_ = &lista[0];

    error = ComprobarListaDeTexto(&params);

    if (error != 0) {
        ImprimirMensajeDeError((void*)&error, Especif_ComprobarListaDeTexto);
        Imprimir("\n\n", NULL);
        return 1;
    }

    Imprimir("\nOK\n", NULL);
    return 0;
}

/* resultado:

C:\...\Win> .\PruebaWin.exe
Error : ComprobarListaDeTexto :
        En el Campo_datos_de_salida :
                Hay menos Sizes que cantidad de elememtos en la lista
*/
