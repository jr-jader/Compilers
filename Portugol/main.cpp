#include "sintatico.hpp"
#include "automato.hpp"
#include "lexico.hpp"

using namespace std;

int main () {

    input = "";
    char c;

    while ((c = getchar()) != EOF) {
        input += c;
    }

    Lexico lexico;

    Sintatico syntactic;

    int correct_program = 1;
    
    s.push(".");
    s.push("BlocoComandos");
    s.push("ProcedimentoFuncao");
    s.push("BlocoVariaveis");
    s.push(";");
    s.push("id");
    s.push("algoritmo");

    while(input.size() > 0) {

        if(ask_for_new_token) {

            token_read_value = lexico.analisador_lexico(input);

            if(token_read_value == 0) {
                correct_program = 0;
                break;
            } else if (token_read_value == 54 || token_read_value == 55 || token_read_value == 57) {
                continue;
            }

        }

        syntactic.analisador_sintatico(token_read_value);

    }

    if(correct_program) {
        cout << "PROGRAMA CORRETO.";
    }

    return 0;
}