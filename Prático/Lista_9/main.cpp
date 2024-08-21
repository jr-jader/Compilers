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

void avancar(){
    token = get_token();
}

void comer(int t){
    if (erro_impresso) {
        avancar();
    }
    if (token == t) {
        avancar();
    }else {
        erro(t);
    }   
}

void S() {
    if (erro_impresso){
        return;
    }
    switch (token)
    {
    case IF:
        comer(IF);
        E();
        comer(THEN);
        S();
        comer(ELSE);
        S();
        break;
    
    case BEGIN:
        comer(BEGIN);
        S();
        L();
        break;

    case PRINT;
        comer(BEGIN);
        E();
        break;
    
    default:
        erro_impresso = 1;
        cout << "ERRO SINTATICO EM: " << get_token_errado() << "ESPERADO: if, begin, print";
        return;
    }
}

void L() {
    if (erro_impresso) {
        return;
    }
    switch (token)
    {
    case END:
        comer(END);
        break;
    
    case SEMI:
        comer(SEMI);
        S();
        L();
        break;
    
    default:
        erro_impresso = 1; 
        cout << "ERRO SINTATICO EM: " << get_token_errado() << " ESPERADO: end, ;"; 
        return;
    }
}

void E() {
    if (erro_impresso){
        return;
    }
    comer(NUM);
    comer(EQ);
    comer(NUM);
}

string get_token_esperado(int t) {
    switch (t) {
        case IF: return "if";
        case THEN: return "then";
        case ELSE: return "else";
        case BEGIN: return "begin";
        case END: return "end";
        case PRINT: return "print";
        case SEMI: return ";";
        case NUM: return "num";
        case EQ: return "=";
        default: return "";
    }
}

void avancar_cadeia() {
    char caractere_lido;
    caractere_lido = cin.get();
    while (caractere_lido != '\n') {
        if (caractere_lido == -1) {
            exit(0);
        }
        caractere_lido = cin.get();
    }
    avancar();
}

string get_token_errado() {
    if (token == NUM) {
        return "num";
    }
    return get_ultimo_token_lido();
}