#include "lexico.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "automato.h"
#include "sintatico.h"

using namespace std;

static char ultimo_token_lido[64];
static char ultimo_caractere_lido;
static char inicio_cadeia;

static int quebra_linha;

string get_ultimo_token_lido() {
    return string(ultimo_token_lido);
}

char get_ultimo_caractere_lido() {
    return ultimo_caractere_lido;
}

void reset_quebra_linha() {
    quebra_linha = 0;
}

int leu_quebra_linha() {
    return quebra_linha;
}