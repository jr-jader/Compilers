#include <iostream>
#include <string>

#define ESTADOS 8

int get_indice(char c);

int main() {
    int transicoes[][128] = {
        /*         +, -, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z */
        /*0*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*1*/    {3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        /*2*/    {0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        /*3*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*4*/    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*5*/    {0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*6*/    {7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*7*/    {0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*8*/    {0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int estadosFinais[ESTADOS + 1] = {0, 0, 1, 1, 1, 1, 0, 0, 1};
    int estadoInicial = 1;
    int tamanhoEntrada;
    int i;

    std::string entrada;

    int estadoAtual;
    int inicioCadeia;
    int cursorUltimoFinal;
    int ultimoEstadoFinal;
    int cursorAtual;

    while (std::getline(std::cin, entrada)) {
        tamanhoEntrada = entrada.length();
        estadoAtual = 1;
        inicioCadeia = 0;
        ultimoEstadoFinal = 0;
        cursorUltimoFinal = 0;
        cursorAtual = -1;

        while (cursorAtual <= tamanhoEntrada) {
            cursorAtual++;
            estadoAtual = transicoes[estadoAtual][get_indice(entrada[cursorAtual])];
            if (estadoAtual == 0) {
                if (ultimoEstadoFinal == 0) {
                    if (entrada[cursorAtual] != 10) {
                        std::cout << "ERRO";
                    }
                    if (cursorAtual != inicioCadeia) {
                        cursorAtual = inicioCadeia;
                        inicioCadeia++;
                    } else {
                        inicioCadeia++;
                    }
                    estadoAtual = estadoInicial;
                    if (inicioCadeia != tamanhoEntrada) {
                        std::cout << std::endl;
                    }
                } else {
                    for (i = inicioCadeia; i <= cursorUltimoFinal; i++) {
                        if (entrada[i] != 10 && entrada[i] != 32) {
                            std::cout << entrada[i];
                        }
                    }
                    inicioCadeia = cursorUltimoFinal + 1;
                    cursorAtual = cursorUltimoFinal;
                    estadoAtual = estadoInicial;
                    ultimoEstadoFinal = 0;
                    if (inicioCadeia != tamanhoEntrada) {
                        std::cout << std::endl;
                    }
                }
            }
            if (estadosFinais[estadoAtual]) {
                ultimoEstadoFinal = estadoAtual;
                cursorUltimoFinal = cursorAtual;
            }
            if (inicioCadeia == tamanhoEntrada) {
                break;
            }
        }
    }
    return 0;
}

int get_indice(char c) {
    if (c == '+') return 0;
    else if (c == '-') return 1;
    else if (c >= 48 && c <= 57) return c - 46;
    else if (c >= 97 && c <= 122) return c - 85;
    else return 38;
}
