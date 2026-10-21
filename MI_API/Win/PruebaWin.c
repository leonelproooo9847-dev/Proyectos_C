
#include "LibpWin.h"

int main(void) {
    Imprimir(
        "========================================\n"
        " PRUEBAS DE FUNCIONES PORTABLES - Libp\n"
        "========================================\n\n",
        NULL
    );

    // ============================================================
    // 1. SacarDirectorioActual
    // ============================================================

    Imprimir("[1] SacarDirectorioActual\n", NULL);

    {
        char ruta[] = "proyecto\\src\\main.c";
        char directorio[64] = {0};

        Byte_t resultado = SacarDirectorioActual(
            ruta,
            directorio,
            sizeof(directorio),
            No
        );

        if (resultado != 0) {
            ImprimirMensajeDeError(
                &resultado,
                Especif_SacarDirectorioActual
            );
            Imprimir("\n", NULL);
        } else {
            Imprimir("Directorio obtenido: %s\n", directorio);
        }

        // Prueba de error: puntero de entrada NULL.
        resultado = SacarDirectorioActual(
            NULL,
            directorio,
            sizeof(directorio),
            No
        );

        if (resultado != 0) {
            Imprimir("Prueba de error:\n", NULL);
            ImprimirMensajeDeError(
                &resultado,
                Especif_SacarDirectorioActual
            );
            Imprimir("\n", NULL);
        }
    }

    // ============================================================
    // 2. LimpiarBuffer
    // ============================================================

    Imprimir("\n[2] LimpiarBuffer\n", NULL);

    {
        Byte_t buffer[] = {
            0x12, 0x34, 0x56, 0x78
        };

        Byte_t resultado = LimpiarBuffer(
            buffer,
            sizeof(buffer)
        );

        if (resultado != 0) {
            ImprimirMensajeDeError(
                &resultado,
                Especif_LimpiarBuffer
            );
        } else {
            Imprimir("Buffer limpiado: ", NULL);

            for (size_t i = 0; i < sizeof(buffer); i++) {
                Imprimir("%x ", &buffer[i]);
            }

            Imprimir("\n", NULL);
        }

        // Prueba de error: puntero NULL.
        resultado = LimpiarBuffer(NULL, 4);

        if (resultado != 0) {
            Imprimir("Prueba de error:\n", NULL);
            ImprimirMensajeDeError(
                &resultado,
                Especif_LimpiarBuffer
            );
            Imprimir("\n", NULL);
        }
    }

    // ============================================================
    // 3. TipoReprDeSignos
    // ============================================================

    Imprimir("\n[3] TipoReprDeSignos\n", NULL);

    {
        Byte_t representacion = TipoReprDeSignos();

        if (representacion == _SIGNO_Y_MAGNITUD_) {
            Imprimir("Representacion: SIGNO Y MAGNITUD\n", NULL);
        } else if (representacion == _COMPLEMENTO_UNO_) {
            Imprimir("Representacion: COMPLEMENTO A UNO\n", NULL);
        } else if (representacion == _COMPLEMENTO_DOS_) {
            Imprimir("Representacion: COMPLEMENTO A DOS\n", NULL);
        } else {
            Imprimir("Representacion desconocida: %x\n",
                     &representacion);
        }
    }

    // ============================================================
    // 4. CopiarBuffer
    // ============================================================

    Imprimir("\n[4] CopiarBuffer\n", NULL);

    {
        Byte_t origen[] = {
            0x11, 0x22, 0x33, 0x44
        };

        Byte_t destino[4] = {0};

        Byte_t resultado = CopiarBuffer(
            origen,
            destino,
            sizeof(origen),
            sizeof(destino)
        );

        if (resultado != 0) {
            ImprimirMensajeDeError(
                &resultado,
                Especif_CopiarBuffer
            );
        } else {
            Imprimir("Contenido copiado: ", NULL);

            for (size_t i = 0; i < sizeof(destino); i++) {
                Imprimir("%x ", &destino[i]);
            }

            Imprimir("\n", NULL);
        }

        // Prueba de error: buffers con el mismo puntero.
        resultado = CopiarBuffer(
            origen,
            origen,
            sizeof(origen),
            sizeof(origen)
        );

        if (resultado != 0) {
            Imprimir("Prueba de error:\n", NULL);
            ImprimirMensajeDeError(
                &resultado,
                Especif_CopiarBuffer
            );
            Imprimir("\n", NULL);
        }
    }

    // ============================================================
    // 5. ComprobarListaDeTexto
    // ============================================================

    Imprimir("\n[5] ComprobarListaDeTexto\n", NULL);

    {
        const char lista[] =
            "Hola\0Mundo\0ProtoGex\0\0";

        size_t indices[3] = {0};

        COMPROBACION_PARAMs parametros = {0};

        parametros.Campo_datos_de_entrada
            ._LISTA_DE_TEXTO_C_ = lista;

        parametros.Campo_datos_de_entrada
            ._LONGITUD_DE_LA_LISTA_ = sizeof(lista);

        parametros.Campo_datos_de_salida
            ._LISTA_DE_SIZEs__GUARDADO_DE_INDICES_ = indices;

        parametros.Campo_datos_de_salida
            ._CANTIDAD_DE_SIZEs_ =
                sizeof(indices) / sizeof(indices[0]);

        Byte_t resultado = ComprobarListaDeTexto(
            &parametros
        );

        if (resultado != 0) {
            ImprimirMensajeDeError(
                &resultado,
                Especif_ComprobarListaDeTexto
            );
        } else {
            Imprimir("Lista valida.\n", NULL);

            for (size_t i = 0; i < 3; i++) {
                Imprimir("Indice del texto: %uint\n", &indices[i]);
            }
        }

        // Prueba de error: estructura NULL.
        resultado = ComprobarListaDeTexto(NULL);

        if (resultado != 0) {
            Imprimir("Prueba de error:\n", NULL);
            ImprimirMensajeDeError(
                &resultado,
                Especif_ComprobarListaDeTexto
            );
            Imprimir("\n", NULL);
        }
    }

    // ============================================================
    // 6. ImprimirMensajeDeError
    // ============================================================

    Imprimir("\n[6] ImprimirMensajeDeError\n", NULL);

    {
        // Generamos un error real de LimpiarBuffer.
        Byte_t resultado = LimpiarBuffer(NULL, 10);

        if (resultado != 0) {
            Imprimir("Diagnostico del error generado:\n", NULL);

            ImprimirMensajeDeError(
                &resultado,
                Especif_LimpiarBuffer
            );
        }
    }

    Imprimir(
        "\n========================================\n"
        " FIN DE LAS PRUEBAS\n"
        "========================================\n",
        NULL
    );

    return 0;
}