#include <iostream>
#include <cstdlib>
#include "lexico.h"
#include "sintatico.h"

using namespace std;

int token;
int token_anterior;
int erro_impresso;
int cadeia_incompleta;

void S();
void L();
void E();

void erro(int t);
void comer(int t);
void avancar();
string get_token_esperado(int t);
void avancar_cadeia();
string get_token_errado();

void erro(int t) {
    if (erro_impresso) {
        return;
    }
    erro_impresso = 1;
    
    if (get_ultimo_caractere_lido() != 10 && leu_quebra_linha()) {
        cadeia_incompleta = 1;
        cout << "ERRO SINTATICO: CADEIA INCOMPLETA";
    } else {
        cout << "ERRO SINTATICO EM: " << get_token_errado() << " ESPERADO: " << get_token_esperado(t);
    }
    return;
}
