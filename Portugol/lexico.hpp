#include "automato.hpp"

using namespace std;



class Lexico {
   public:
    int analisador_lexico(string line) {
        int current_state = 1;
        int last_final_state = 0;
        int last_final_state_position = 0;
        string current_token = "";
        string last_final_token = "";

        for (int i = 0; i < line.length(); i++) {
            int next_state = transistions_table[current_state][line[i]];
            current_token += line[i];

            if (next_state != 0 && next_state != 171) {
                current_state = next_state;

                if (line[i] == '\n') {
                    line_number++;
                    column_number = 1;
                } else {
                    column_number++;
                }
                
                if (final_states[current_state] == 1) {
                    last_final_state = current_state;
                    last_final_state_position = i;
                    last_final_token = current_token;
                }

                if (i == line.length() - 1) {
                    if (final_states[current_state] == 1) {
                        if (last_final_token == " ") {
                            continue;
                        }
                        input.erase(0, last_final_state_position + 1);
                        token_read = last_final_token;
                        return tokens[last_final_state];
                    }
                }

            } else {

                if (last_final_state != 0) {
                    if (last_final_token != " ") {
                        input.erase(0, last_final_state_position + 1);
                        token_read = last_final_token;
                        return tokens[last_final_state];
                    }
                } else {
                    if (line[i] == ' ') {
                        current_state = 1;
                        last_final_state = 0;
                        last_final_state_position = 0;
                        last_final_token = "";
                        current_token = "";
                        column_number++;
                        continue;
                    } else if (line[i] == '\n') {
                        line_number++;
                        column_number = 1;
                        input.erase(0, i + 1);
                        token_read = last_final_token;
                        return OUTRO;
                    }
                    cout << "ERRO LEXICO. Linha: " << line_number << " Coluna: " << column_number << " -> \'" << current_token << "\'";
                    return ERRO;
                }
            }
        }
        return ERRO;
    }
};
