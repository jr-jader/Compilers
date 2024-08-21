#include <iostream>
#include <string>
#include <vector>

#define ESTADOS 13

int get_indice(char c);
void imprimir_token(int ultimoEstadoFinal);

int main() {
    std::vector<std::vector<int>> transicoes = {
        /*  \n,  , +, -, ., 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, OTHER */
        /*0*/ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*1*/ {0, 12, 13, 9, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 13},
        /*2*/ {0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0},
        /*3*/ {0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0},
        /*4*/ {0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0},
        /*5*/ {0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*6*/ {0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*7*/ {0, 0, 0, 0, 8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*8*/ {0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*9*/ {0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*10*/ {11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0},
        /*11*/ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*12*/ {0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*13*/ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    std::vector<int> estadosFinais(ESTADOS + 1, 0);
    estadosFinais[2] = 1;
    estadosFinais[3] = 1;
    estadosFinais[4] = 1;
    estadosFinais[5] = 1;
    estadosFinais[6] = 1;
    estadosFinais[7] = 1;
    estadosFinais[8] = 1;
    estadosFinais[9] = 1;
    estadosFinais[12] = 1;
    estadosFinais[11] = 1;
    estadosFinais[13] = 1;

    int estadoInicial = 1;
    std::string entrada;
    int estadoAtual;
    int inicioCadeia;
    int cursorUltimoFinal;
    int ultimoEstadoFinal;
    int cursorAtual;

    while (std::getline(std::cin, entrada)) {
        int tamanhoEntrada = entrada.length();
        estadoAtual = estadoInicial;
        inicioCadeia = 0;
        ultimoEstadoFinal = 0;
        cursorUltimoFinal = 0;
        cursorAtual = -1;

        while (cursorAtual <= tamanhoEntrada) {
            cursorAtual++;
            if (cursorAtual < tamanhoEntrada) {
                estadoAtual = transicoes[estadoAtual][get_indice(entrada[cursorAtual])];
            } else {
                estadoAtual = 0;
            }

            if (estadoAtual == 0) {
                if (ultimoEstadoFinal == 0) {
                    if (cursorAtual != inicioCadeia) {
                        cursorAtual = inicioCadeia;
                        inicioCadeia++;
                    } else {
                        inicioCadeia++;
                    }
                    estadoAtual = estadoInicial;
                } else {
                    for (int i = inicioCadeia; i <= cursorUltimoFinal; i++) {
                        if (entrada[i] != '\n' && entrada[i] != ' ') {
                            std::cout << entrada[i];
                        }
                    }

                    imprimir_token(ultimoEstadoFinal);

                    inicioCadeia = cursorUltimoFinal + 1;
                    cursorAtual = cursorUltimoFinal;
                    estadoAtual = estadoInicial;
                    ultimoEstadoFinal = 0;

                    if (inicioCadeia != tamanhoEntrada) {
                        std::cout << "\n";
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
    if (c == '\n') return 0;
    else if (c == ' ') return 1;
    else if (c == '+') return 2;
    else if (c == '-') return 3;
    else if (c == '.') return 4;
    else if (c >= '0' && c <= '9') return c - '0' + 5;
    else if (c >= 'a' && c <= 'z') return c - 'a' + 15;
    else return 41;
}

void imprimir_token(int ultimoEstadoFinal) {
    if (ultimoEstadoFinal == 2) std::cout << " ID";
    else if (ultimoEstadoFinal == 3) std::cout << " IF";
    else if (ultimoEstadoFinal == 4) std::cout << " ID";
    else if (ultimoEstadoFinal == 5) std::cout << " error";
    else if (ultimoEstadoFinal == 6) std::cout << " REAL";
    else if (ultimoEstadoFinal == 7) std::cout << " NUM";
    else if (ultimoEstadoFinal == 8) std::cout << " REAL";
    else if (ultimoEstadoFinal == 9) std::cout << " error";
    else if (ultimoEstadoFinal == 12) std::cout << "white space";
    else if (ultimoEstadoFinal == 11) std::cout << " comment\n";
    else if (ultimoEstadoFinal == 13) std::cout << " error";
}
