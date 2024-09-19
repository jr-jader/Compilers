#include "automato.hpp"

using namespace std;

class Sintatico {
   public:

    void algo_func() {

        if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "algoritmo") {
            column_number -= token_read.size();
            cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
            exit(0);
        }

        s.pop();
        ask_for_new_token = true;
    }

    void point_func() {
        ask_for_new_token = false;

        if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != ".") {
            column_number -= token_read.size();
            cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
            exit(0);
        }
        s.pop();
        ask_for_new_token = true;
    }

    void id_func() {
        ask_for_new_token = false;
            
        if (s.top() == "DeclaraParametros") {
            s.pop();
            s.push("Declaracoes");
        } else if (s.top() == "Declaracoes") {
            s.pop();
            s.push("Declaracoes\'");
            s.push("DeclaraVariaveis");
        } else if (s.top() == "DeclaraVariaveis") {
            s.pop();
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("TipoBasico");
        } else if (s.top() == "DeclaraIdentificador") {
            s.pop();
            s.push("DeclaraIdentificador\'");
            s.push("id");
        } else if (s.top() == "TipoBasico") {
            s.pop();
            s.push("id");
        } else if (s.top() == "ListaComandos") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Comandos");
        } else if (s.top() == "Comandos") {
            s.pop();
            s.push("ComandosExtra");
            s.push("id");
        } else if (s.top() == "Expressao") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples");
        } else if (s.top() == "ExpressaoSimples") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("Termo");
        } else if (s.top() == "Termo") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Fator");
        } else if (s.top() == "Fator") {
            s.pop();
            s.push("FatorExtra");
            s.push("id");
        } else if (s.top() == "Variavel") {
            s.pop();
            s.push("Variavel\'");
            s.push("id");
        } else if (s.top() == "ExprIter") {
            s.pop();
            s.push("ExprIterExtra");
            s.push("id");
        } else if (s.top() == "Declaracoes\'") {
            s.pop();
            s.push("Declaracoes\'");
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("id");
        } else if (s.top() == "Declaracoes\'\'") {
            s.pop();
            s.push("Declaracoes\'");
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("id");
        } else if (s.top() == "ListaComandos\'") {
            s.pop();
            s.push("ListaComandosExtra\'");
            s.push("id");
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper)) {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;
            
        }
    }

    void semicolon_func() {
        ask_for_new_token = false;
        if (s.top() == "Parametros") {
            s.pop();
        } else if (s.top() == "ComandosExtra") {
            s.pop();
            s.push("Comandos\'\'\'");
        } else if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "DeclaraIdentificador\'") {
            s.pop();
        } else if (s.top() == "ListaComandosExtra\'") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Comandos\'\'\'");
        } else if (s.top() == "Comandos\'\'\'") {
            s.pop();
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != ";") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;
            
        }
    }

    void proc_func() {
        ask_for_new_token = false;
        if (s.top() == "ProcedimentoFuncao") {
            s.pop();
            s.push("ProcedimentoFuncao");
            s.push("DeclaraProcedimento");
        } else if (s.top() == "DeclaraProcedimento") {
            s.pop();
            s.push(";");
            s.push("BlocoComandos");
            s.push("BlocoVariaveis");
            s.push("DeclaraParametros");
            s.push(";");
            s.push("Parametros");
            s.push("id");
            s.push("procedimento");
        } else if (s.top() == "BlocoVariaveis") {
            s.pop();
        } else if (s.top() == "Declaracoes\'") {
            s.pop();
        } else if (s.top() == "Declaracoes\'\'") {
            s.pop();
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "procedimento") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;
            
        }
    }

    void function_func() {
        ask_for_new_token = false;

        if (s.top() == "ProcedimentoFuncao") {
            s.pop();
            s.push("ProcedimentoFuncao");
            s.push("DeclaraFuncao");
        } else if (s.top() == "DeclaraFuncao") {
            s.pop();
            s.push(";");
            s.push("BlocoComandos");
            s.push("BlocoVariaveis");
            s.push("DeclaraParametros");
            s.push(";");
            s.push("TipoBasico");
            s.push(":");
            s.push("Parametros");
            s.push("id");
            s.push("funcao");
        } else if (s.top() == "BlocoVariaveis") {
            s.pop();
        } else if (s.top() == "Declaracoes\'") {
            s.pop();
        } else if (s.top() == "Declaracoes\'\'") {
            s.pop();
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "funcao") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;
            
        }
    }

    void colon_func() {
        ask_for_new_token = false;
        if (s.top() == "Parametros") {
            s.pop();
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != ":") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;
            
        }
    }

    void open_par_func() {
        ask_for_new_token = false;
        if (s.top() == "Parametros") {
            s.pop();
            s.push(")");
            s.push("DeclaraIdentificador");
            s.push("(");
        } else if (s.top() == "ComandosExtra") {
            s.pop();
            s.push("Comandos\'\'\'");
        } else if (s.top() == "Expressao") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples");
        } else if (s.top() == "ExpressaoSimples") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("Termo");
        } else if (s.top() == "Termo") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Fator");
        } else if (s.top() == "Fator") {
            s.pop();
            s.push(")");
            s.push("Expressao");
            s.push("(");
        } else if (s.top() == "FatorExtra") {
            s.pop();
            s.push(")");
            s.push("ExprIter");
            s.push("(");
        } else if (s.top() == "ExprIter") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push(")");
            s.push("Expressao");
            s.push("(");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push(")");
            s.push("ExprIter");
            s.push("(");
        } else if (s.top() == "ListaComandosExtra\'") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Comandos\'\'\'");
        } else if (s.top() == "Comandos\'\'\'") {
            s.pop();
            s.push(")");
            s.push("ExprIter");
            s.push("(");
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "(") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;
            
        }
    }

    void close_par_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "DeclaraIdentificador\'") {
            s.pop();
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "ExprIter\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != ")") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;
            
        }
    }

    void var_func() {
        ask_for_new_token = false;
        if (s.top() == "DeclaraParametros") {
            s.pop();
        } else if (s.top() == "BlocoVariaveis") {
            s.pop();
            s.push("Declaracoes");
            s.push("variaveis");
        } else if (s.top() == "Declaracoes\'") {
            s.pop();
        } else if (s.top() == "Declaracoes\'\'") {
            s.pop();
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "variaveis") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;
            
        }
    }

    void type_func() {
        ask_for_new_token = false;
        if (s.top() == "DeclaraParametros") {
            s.pop();
            s.push("Declaracoes");
        } else if (s.top() == "Declaracoes") {
            s.pop();
            s.push("Declaracoes\'\'");
            s.push("DeclaraTipo");
        } else if (s.top() == "DeclaraTipo") {
            s.pop();
            s.push(";");
            s.push("TipoBasico");
            s.push("]");
            s.push("Dimensao");
            s.push("[");
            s.push("VetorMatriz");
            s.push("=");
            s.push("id");
            s.push("tipo");
        } else if (s.top() == "Declaracoes\'") {
            s.pop();
            s.push("Declaracoes\'\'");
            s.push(";");
            s.push("TipoBasico");
            s.push("]");
            s.push("Dimensao");
            s.push("[");
            s.push("VetorMatriz");
            s.push("=");
            s.push("id");
            s.push("tipo");
        } else if (s.top() == "Declaracoes\'\'") {
            s.pop();
            s.push("Declaracoes\'\'");
            s.push(";");
            s.push("TipoBasico");
            s.push("]");
            s.push("Dimensao");
            s.push("[");
            s.push("VetorMatriz");
            s.push("=");
            s.push("id");
            s.push("tipo");
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "tipo") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;
            
        }
    }

    void equal_func() {

        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "Expressao\'") {
            s.pop();
            s.push("ExpressaoSimples");
            s.push("=");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("Expressao\'");
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "=") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;
            
        }
    }

    void open_bracket_func() {
        ask_for_new_token = false;
        if (s.top() == "ComandosExtra") {
            s.pop();
            s.push("Expressao");
            s.push("<-");
            s.push("Variavel\'");
        } else if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "ListaComandosExtra\'") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Expressao");
            s.push("<-");
            s.push("Variavel\'");
        } else if (s.top() == "Variavel\'") {
            s.pop();
            s.push("]");
            s.push("ExprIter");
            s.push("[");
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "[") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;
            
        }
    }

    void close_bracket_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "Dimensao\'") {
            s.pop();
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "ExprIter\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {

            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "]") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }

            s.pop();
            ask_for_new_token = true;

        }

    }

    void vector_func() {
        ask_for_new_token = false;
        if (s.top() == "VetorMatriz") {
            s.pop();
            s.push("vetor");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "vetor") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void matrix_func() {
        ask_for_new_token = false;
        if (s.top() == "VetorMatriz") {
            s.pop();
            s.push("matriz");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "matriz") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void int_func() {
        ask_for_new_token = false;
        if (s.top() == "Dimensao") {
            s.pop();
            s.push("Dimensao\'");
            s.push("numero_inteiro");
            s.push(":");
            s.push("numero_inteiro");
        } else if (s.top() == "Expressao") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples");
        } else if (s.top() == "ExpressaoSimples") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("Termo");
        } else if (s.top() == "Termo") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Fator");
        } else if (s.top() == "Fator") {
            s.pop();
            s.push("numero_inteiro");
        } else if (s.top() == "ExprIter") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("numero_inteiro");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "numero_inteiro") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void integer_func() {
        ask_for_new_token = false;
        if (s.top() == "DeclaraParametros") {
            s.pop();
            s.push("Declaracoes");
        } else if (s.top() == "Declaracoes") {
            s.pop();
            s.push("Declaracoes\'");
            s.push("DeclaraVariaveis");
        } else if (s.top() == "DeclaraVariaveis") {
            s.pop();
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("TipoBasico");
        } else if (s.top() == "TipoBasico") {
            s.pop();
            s.push("inteiro");
        } else if (s.top() == "Declaracoes\'") {
            s.pop();
            s.push("Declaracoes\'");
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("inteiro");
        } else if (s.top() == "Declaracoes\'\'") {
            s.pop();
            s.push("Declaracoes\'");
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("inteiro");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "inteiro") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void real_func() {
        ask_for_new_token = false;
        if (s.top() == "DeclaraParametros") {
            s.pop();
            s.push("Declaracoes");
        } else if (s.top() == "Declaracoes") {
            s.pop();
            s.push("Declaracoes\'");
            s.push("DeclaraVariaveis");
        } else if (s.top() == "DeclaraVariaveis") {
            s.pop();
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("TipoBasico");
        } else if (s.top() == "TipoBasico") {
            s.pop();
            s.push("real");
        } else if (s.top() == "Declaracoes\'") {
            s.pop();
            s.push("Declaracoes\'");
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("real");
        } else if (s.top() == "Declaracoes\'\'") {
            s.pop();
            s.push("Declaracoes\'");
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("real");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "real") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void char_func() {
        ask_for_new_token = false;
        if (s.top() == "DeclaraParametros") {
            s.pop();
            s.push("Declaracoes");
        } else if (s.top() == "Declaracoes") {
            s.pop();
            s.push("Declaracoes\'");
            s.push("DeclaraVariaveis");
        } else if (s.top() == "DeclaraVariaveis") {
            s.pop();
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("TipoBasico");
        } else if (s.top() == "TipoBasico") {
            s.pop();
            s.push("caractere");
        } else if (s.top() == "Declaracoes\'") {
            s.pop();
            s.push("Declaracoes\'");
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("caractere");
        } else if (s.top() == "Declaracoes\'\'") {
            s.pop();
            s.push("Declaracoes\'");
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("caractere");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "caractere") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void logical_func() {
        ask_for_new_token = false;
        if (s.top() == "DeclaraParametros") {
            s.pop();
            s.push("Declaracoes");
        } else if (s.top() == "Declaracoes") {
            s.pop();
            s.push("Declaracoes\'");
            s.push("DeclaraVariaveis");
        } else if (s.top() == "DeclaraVariaveis") {
            s.pop();
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("TipoBasico");
        } else if (s.top() == "TipoBasico") {
            s.pop();
            s.push("logico");
        } else if (s.top() == "Declaracoes\'") {
            s.pop();
            s.push("Declaracoes\'");
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("logico");
        } else if (s.top() == "Declaracoes\'\'") {
            s.pop();
            s.push("Declaracoes\'");
            s.push(";");
            s.push("DeclaraIdentificador");
            s.push(":");
            s.push("logico");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "logico") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void begin_func() {
        ask_for_new_token = false;
        if (s.top() == "ProcedimentoFuncao") {
            s.pop();
        } else if (s.top() == "DeclaraParametros") {
            s.pop();
        } else if (s.top() == "BlocoVariaveis") {
            s.pop();
        } else if (s.top() == "BlocoComandos") {
            s.pop();
            s.push("fim");
            s.push("ListaComandos");
            s.push("inicio");
        } else if (s.top() == "Declaracoes\'") {
            s.pop();
        } else if (s.top() == "Declaracoes\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "inicio") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void end_func() {
        ask_for_new_token = false;
        if (s.top() == "ListaComandos\'") {
            s.pop();
        } else if (s.top() == "Comandos\'\'") {
            s.pop();
            s.push("se");
            s.push("fim");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "fim") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void if_func() {
        ask_for_new_token = false;
        if (s.top() == "ListaComandos") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Comandos");
        } else if (s.top() == "Comandos") {
            s.pop();
            s.push("Comandos\'\'");
            s.push("ListaComandos");
            s.push("entao");
            s.push("Expressao");
            s.push("se");
        } else if (s.top() == "ListaComandos\'") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Comandos\'\'");
            s.push("ListaComandos");
            s.push("entao");
            s.push("Expressao");
            s.push("se");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "se") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void then_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "entao") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void for_func() {
        ask_for_new_token = false;
        if (s.top() == "ListaComandos") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Comandos");
        } else if (s.top() == "Comandos") {
            s.pop();
            s.push("Comandos\'");
            s.push("Expressao");
            s.push("ate");
            s.push("Expressao");
            s.push("de");
            s.push("id");
            s.push("para");
        } else if (s.top() == "ListaComandos\'") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Comandos\'");
            s.push("Expressao");
            s.push("ate");
            s.push("Expressao");
            s.push("de");
            s.push("id");
            s.push("para");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "para") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void from_func() {
        ask_for_new_token = false;

        if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "de") {
            column_number -= token_read.size();
            cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
            exit(0);
        }
        s.pop();
        ask_for_new_token = true;
    }

    void until_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ListaComandos\'") {
            s.pop();
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "ate") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void while_func() {
        ask_for_new_token = false;
        if (s.top() == "ListaComandos") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Comandos");
        } else if (s.top() == "Comandos") {
            s.pop();
            s.push("enquanto");
            s.push("fim");
            s.push("ListaComandos");
            s.push("faca");
            s.push("Expressao");
            s.push("enquanto");
        } else if (s.top() == "ListaComandos\'") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("enquanto");
            s.push("fim");
            s.push("ListaComandos");
            s.push("faca");
            s.push("Expressao");
            s.push("enquanto");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "enquanto") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void do_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "Comandos\'") {
            s.pop();
            s.push("para");
            s.push("fim");
            s.push("ListaComandos");
            s.push("faca");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "faca") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void repeat_func() {
        ask_for_new_token = false;
        if (s.top() == "ListaComandos") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Comandos");
        } else if (s.top() == "Comandos") {
            s.pop();
            s.push("Expressao");
            s.push("ate");
            s.push("ListaComandos");
            s.push("repita");
        } else if (s.top() == "ListaComandos\'") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Expressao");
            s.push("ate");
            s.push("ListaComandos");
            s.push("repita");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "repita") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void read_func() {
        ask_for_new_token = false;
        if (s.top() == "ListaComandos") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Comandos");
        } else if (s.top() == "Comandos") {
            s.pop();
            s.push(")");
            s.push("Variavel");
            s.push("(");
            s.push("leia");
        } else if (s.top() == "ListaComandos\'") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push(")");
            s.push("Variavel");
            s.push("(");
            s.push("leia");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "leia") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void print_func() {
        ask_for_new_token = false;
        if (s.top() == "ListaComandos") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Comandos");
        } else if (s.top() == "Comandos") {
            s.pop();
            s.push(")");
            s.push("ExprIter");
            s.push("(");
            s.push("imprima");
        } else if (s.top() == "ListaComandos\'") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push(")");
            s.push("ExprIter");
            s.push("(");
            s.push("imprima");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "imprima") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void attrib_func() {
        ask_for_new_token = false;
        if (s.top() == "ComandosExtra") {
            s.pop();
            s.push("Expressao");
            s.push("<-");
            s.push("Variavel\'");
        } else if (s.top() == "ListaComandosExtra\'") {
            s.pop();
            s.push("ListaComandos\'");
            s.push(";");
            s.push("Expressao");
            s.push("<-");
            s.push("Variavel\'");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "<-") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void plus_func() {
        ask_for_new_token = false;
        if (s.top() == "Expressao") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples");
        } else if (s.top() == "ExpressaoSimples") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("Termo");
            s.push("+");
        } else if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIter") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("+");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "ExpressaoSimples\'") {
            s.pop();
            s.push("Termo");
            s.push("+");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("ExpressaoSimples\'");
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "+") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void minus_func() {
        ask_for_new_token = false;
        if (s.top() == "Expressao") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples");
        } else if (s.top() == "ExpressaoSimples") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("Termo");
            s.push("-");
        } else if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIter") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("-");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "ExpressaoSimples\'") {
            s.pop();
            s.push("Termo");
            s.push("-");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("ExpressaoSimples\'");
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "-") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void not_func() {
        ask_for_new_token = false;
        if (s.top() == "Expressao") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples");
        } else if (s.top() == "ExpressaoSimples") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("Termo");
        } else if (s.top() == "Termo") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Fator");
        } else if (s.top() == "Fator") {
            s.pop();
            s.push("Fator");
            s.push("nao");
        } else if (s.top() == "ExprIter") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Fator");
            s.push("nao");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "nao") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void real_num_func() {
        ask_for_new_token = false;
        if (s.top() == "Expressao") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples");
        } else if (s.top() == "ExpressaoSimples") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("Termo");
        } else if (s.top() == "Termo") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Fator");
        } else if (s.top() == "Fator") {
            s.pop();
            s.push("numero_real");
        } else if (s.top() == "ExprIter") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("numero_real");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "numero_real") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void true_func() {
        ask_for_new_token = false;
        if (s.top() == "Expressao") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples");
        } else if (s.top() == "ExpressaoSimples") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("Termo");
        } else if (s.top() == "Termo") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Fator");
        } else if (s.top() == "Fator") {
            s.pop();
            s.push("verdadeiro");
        } else if (s.top() == "ExprIter") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("verdadeiro");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "verdadeiro") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void false_func() {
        ask_for_new_token = false;
        if (s.top() == "Expressao") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples");
        } else if (s.top() == "ExpressaoSimples") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("Termo");
        } else if (s.top() == "Termo") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Fator");
        } else if (s.top() == "Fator") {
            s.pop();
            s.push("falso");
        } else if (s.top() == "ExprIter") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("falso");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "falso") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void text_func() {
        ask_for_new_token = false;
        if (s.top() == "Expressao") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples");
        } else if (s.top() == "ExpressaoSimples") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("Termo");
        } else if (s.top() == "Termo") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Fator");
        } else if (s.top() == "Fator") {
            s.pop();
            s.push("texto");
        } else if (s.top() == "ExprIter") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("texto");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "texto") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void comma_func() {
        ask_for_new_token = false;

        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "DeclaraIdentificador\'") {
            s.pop();
            s.push("DeclaraIdentificador");
            s.push(",");
        } else if (s.top() == "Dimensao\'") {
            s.pop();
            s.push("Dimensao");
            s.push(",");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "ExprIter\'") {
            s.pop();
            s.push("ExprIter");
            s.push(",");
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != ",") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void step_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "Comandos\'") {
            s.pop();
            s.push("para");
            s.push("fim");
            s.push("ListaComandos");
            s.push("faca");
            s.push("Expressao");
            s.push("passo");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "passo") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void else_func() {
        ask_for_new_token = false;
        if (s.top() == "ListaComandos\'") {
            s.pop();
        } else if (s.top() == "Comandos\'\'") {
            s.pop();
            s.push("se");
            s.push("fim");
            s.push("ListaComandos");
            s.push("senao");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "senao") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void diff_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "Expressao\'") {
            s.pop();
            s.push("ExpressaoSimples");
            s.push("<>");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("Expressao\'");
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "<>") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void less_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "Expressao\'") {
            s.pop();
            s.push("ExpressaoSimples");
            s.push("<");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("Expressao\'");
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "<") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void less_equal_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "Expressao\'") {
            s.pop();
            s.push("ExpressaoSimples");
            s.push("<=");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("Expressao\'");
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "<=") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void greater_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "Expressao\'") {
            s.pop();
            s.push("ExpressaoSimples");
            s.push(">");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("Expressao\'");
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != ">") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void greater_equal_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "Expressao\'") {
            s.pop();
            s.push("ExpressaoSimples");
            s.push(">=");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Expressao\'\'") {
            s.pop();
            s.push("Expressao\'\'");
            s.push("Expressao\'");
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != ">=") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void or_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra\'") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "ExpressaoSimples\'") {
            s.pop();
            s.push("Termo");
            s.push("ou");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "ExpressaoSimples\'\'") {
            s.pop();
            s.push("ExpressaoSimples\'\'");
            s.push("ExpressaoSimples\'");
        } else if (s.top() == "Termo\'\'") {
            s.pop();
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "ou") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void times_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "Termo\'") {
            s.pop();
            s.push("Fator");
            s.push("*");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Termo\'");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "*") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void division_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "Termo\'") {
            s.pop();
            s.push("Fator");
            s.push("/");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Termo\'");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "/") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void div_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "Termo\'") {
            s.pop();
            s.push("Fator");
            s.push("div");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Termo\'");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "div") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }

    void and_func() {
        ask_for_new_token = false;
        if (s.top() == "FatorExtra") {
            s.pop();
            s.push("Variavel\'");
        } else if (s.top() == "ExprIterExtra") {
            s.pop();
            s.push("ExprIter\'");
            s.push("Expressao\'\'");
            s.push("ExpressaoSimples\'\'");
            s.push("Termo\'\'");
            s.push("Variavel\'");
        } else if (s.top() == "Termo\'") {
            s.pop();
            s.push("Fator");
            s.push("e");
        } else if (s.top() == "Variavel\'") {
            s.pop();
        } else if (s.top() == "Termo\'\'") {
            s.pop();
            s.push("Termo\'\'");
            s.push("Termo\'");
        } else {
            if (any_of(s.top().begin(), s.top().end(), ::isupper) || s.top() != "e") {
                column_number -= token_read.size();
                cout << "ERRO DE SINTAXE. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << token_read << "\'";
                exit(0);
            }
            s.pop();
            ask_for_new_token = true;
        }
    }
    
void analisador_sintatico(int token_value) {

        switch (token_value) {
            case ALGORITMO:
                algo_func();
                break;
            case PONTO:
                point_func();
                break;
            case ID:
                id_func();
                break;
            case PONTO_VIRGULA:
                semicolon_func();
                break;
            case PROCEDIMENTO:
                proc_func();
                break;
            case FUNCAO:
                function_func();
                break;
            case DOIS_PONTOS:
                colon_func();
                break;
            case ABRE_PAR:
                open_par_func();
                break;
            case FECHA_PAR:
                close_par_func();
                break;
            case VARIAVEIS:
                var_func();
                break;
            case TIPO:
                type_func();
                break;
            case IGUAL:
                equal_func();
                break;
            case ABRE_COL:
                open_bracket_func();
                break;
            case FECHA_COL:
                close_bracket_func();
                break;
            case VETOR:
                vector_func();
                break;
            case MATRIZ:
                matrix_func();
                break;
            case NUMERO_INTEIRO:
                int_func();
                break;
            case INTEIRO:
                integer_func();
                break;
            case REAL:
                real_func();
                break;
            case CARACTERE:
                char_func();
                break;
            case LOGICO:
                logical_func();
                break;
            case INICIO:
                begin_func();
                break;
            case FIM:
                end_func();
                break;
            case SE:
                if_func();
                break;
            case ENTAO:
                then_func();
                break;
            case PARA:
                for_func();
                break;
            case DE:
                from_func();
                break;
            case ATE:
                until_func();
                break;
            case ENQUANTO:
                while_func();
                break;
            case FACA:
                do_func();
                break;
            case REPITA:
                repeat_func();
                break;
            case LEIA:
                read_func();
                break;
            case IMPRIMA:
                print_func();
                break;
            case ATRIBUICAO:
                attrib_func();
                break;
            case MAIS:
                plus_func();
                break;
            case MENOS:
                minus_func();
                break;
            case NAO:
                not_func();
                break;
            case NUMERO_REAL:
                real_num_func();
                break;
            case VERDADEIRO:
                true_func();
                break;
            case FALSO:
                false_func();
                break;
            case TEXTO:
                text_func();
                break;
            case VIRGULA:
                comma_func();
                break;
            case PASSO:
                step_func();
                break;
            case SENAO:
                else_func();
                break;
            case DIFERENTE:
                diff_func();
                break;
            case MENOR:
                less_func();
                break;
            case MENOR_IGUAL:
                less_equal_func();
                break;
            case MAIOR:
                greater_func();
                break;
            case MAIOR_IGUAL:
                greater_equal_func();
                break;
            case OU:
                or_func();
                break;
            case VEZES:
                times_func();
                break;
            case DIVISAO:
                division_func();
                break;
            case DIV:
                div_func();
                break;
            case E:
                and_func();
                break;
            default:
                break;
            break;
        }
    }
};
