#include <iostream>
#include <vector>
#include <string>

#define NUM_STATES 22
#define NUM_FINALS 12
#define NUM_CHARACTERS 41

bool printed = false;

std::vector<int> finalStates = {3, 6, 8, 10, 13, 14, 15, 16, 17, 18, 19, 22};

std::vector<std::string> tokens = {
    " ", " ", "ELE", " ", " ", "ELA", " ", "DELE", " ", "DELA", " ", " ", "GATO",
    "CARRO", "GATOS", "CARROS", "MAIS", "MENOS", "INTEIRO", " ", " ", "REAL"
};

std::vector<char> columns = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'c', 'e', 'h', 'i', 'r', 's', 't', '+', '-'
};

std::vector<std::vector<int>> edges = {
    /* 0   1   2   3   4   5   6   7   8   9   a   c   e   h   i   r   s   t   +   - */
    /*s1*/  {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 0,  11, 0,  2,  0,  0,  4,  0,  17, 18},
    /*s2*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  7,  0,  0,  0,  0,  0 },
    /*s3*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,  0 },
    /*s4*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  0,  0,  0,  0,  0,  0 },
    /*s5*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0,  0,  0 },
    /*s6*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    /*s7*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,  0,  0,  0 },
    /*s8*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    /*s9*/  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  10, 0,  0,  0 },
    /*s10*/ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    /*s11*/ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  12, 0,  0,  0,  0,  0,  0,  0,  0,  0 },
    /*s12*/ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  14, 0,  13, 0,  0 },
    /*s13*/ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  15, 0,  0,  0 },
    /*s14*/ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  16, 0,  0,  0 },
    /*s15*/ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    /*s16*/ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    /*s17*/ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    /*s18*/ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    /*s19*/ {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 0,  0,  20, 0,  0,  0,  0,  0,  0,  0 },
    /*s20*/ {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 0,  0,  0,  0,  0,  0,  0,  0,  21, 21},
    /*s21*/ {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 0,  0,  0,  0,   0,  0,  0,  0,  0,  0 },
    /*s22*/ {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0 }
};

int getColumn(char c) {
    for (int i = 0; i < NUM_CHARACTERS; i++) {
        if (columns[i] == c) {
            return i;
        }
    }
    return -1;
}

bool isFinal(int state) {
    for (int i = 0; i < NUM_FINALS; i++) {
        if (finalStates[i] == state) {
            return true;
        }
    }
    return false;
}

void printToken(int state) {
    if (printed) {
        std::cout << std::endl;
    }
    std::cout << tokens[state];
    if (state == 19 || state == 22) {
        std::cout << " ";
    }
    printed = true;
}

void printErro() {
    if (printed) {
        std::cout << std::endl;
    }
    std::cout << "ERRO";
    printed = true;
}

void zeroNum(std::string& number) {
    number.clear();
}

int main() {
    std::string input;

    while (std::cin >> input) {
        int lastRead;
        int currentState = 1;
        int lastFinalState = 0;
        int lastFinalPos = 0;
        int lastSuccessPos = 0;
        std::string number;

        for (lastRead = 0; input[lastRead] != '\0'; lastRead++) {
            int column = getColumn(input[lastRead]);
            if (column != -1) {
                currentState = edges[currentState - 1][column];

                if (isFinal(currentState)) {
                    lastFinalState = currentState;
                    lastFinalPos = lastRead;
                }

                if ((lastFinalState == 19 || lastFinalState == 22) && currentState != 0) {
                    number += input[lastRead];
                }

                if (currentState == 0) {
                    if (lastFinalState != 0) {
                        printToken(lastFinalState - 1);
                        if (lastFinalState == 19 || lastFinalState == 22) {
                            if (number.back() == 'e') {
                                number.pop_back();
                                std::cout << " " << number;
                                printErro();
                            }
                            else {
                                std::cout << " " << number;
                            }
                            zeroNum(number);
                        }
                        lastRead = lastFinalPos;
                        lastSuccessPos = lastRead;
                        lastSuccessPos++;
                        lastFinalPos = 0;
                    }
                    else {
                        printErro();
                        lastRead = lastSuccessPos;
                        lastSuccessPos++;
                    }
                    currentState = 1;
                    lastFinalState = 0;
                }
            }
            else {
                if (lastFinalState != 0) {
                    printToken(lastFinalState - 1);
                    if (lastFinalState == 19 || lastFinalState == 22) {
                        if (number.back() == 'e') {
                            number.pop_back();
                            std::cout << " " << number;
                            printErro();
                        }
                        else {
                            std::cout << " " << number;
                        }
                        zeroNum(number);
                    }
                    lastRead = lastFinalPos;
                    lastSuccessPos = lastRead;
                    lastSuccessPos++;
                    lastFinalPos = 0;
                }
                else {
                    printErro();
                    lastRead = lastSuccessPos;
                    lastSuccessPos++;
                }
                currentState = 1;
                lastFinalState = 0;
            }
        }

        if (lastFinalState != 0) {
            printToken(lastFinalState - 1);
            if (lastFinalState == 19 || lastFinalState == 22) {
                if (number.back() == 'e') {
                    number.pop_back();
                    std::cout << " " << number;
                    printErro();
                }
                else {
                    std::cout << " " << number;
                }
                zeroNum(number);
            }
        }
        else if (currentState != 1) {
            while (lastSuccessPos < lastRead) {
                printErro();
                lastSuccessPos++;
            }
        }
    }

    return 0;
}
