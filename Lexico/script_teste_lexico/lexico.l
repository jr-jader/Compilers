%option noyywrap

%{
    #include <iostream>
    #include <string>

    int line = 1;
    int column = 1;

    int comment_line = 0;
    int comment_column = 0;

    bool first = true;

    void printfVerification() {
        if (first) {
            first = false;
        } else {
            std::cout << std::endl;
        }
    }

    void printString_Character(const std::string& str) {
        std::string aux = str.substr(1, str.length() - 2);
        std::cout << "(" << aux << ")";
    }
%}

%x comment
%x comment_slashes

%%

\n                  { line++; column = 1; }
[\f\t\r ]+          { column += yyleng; }

"/*"                { 
                        BEGIN(comment); 
                        comment_line = line; 
                        comment_column = column; 
                        column += yyleng; 
                    }
<comment><<EOF>>    { 
                        BEGIN(INITIAL); 
                        printfVerification(); 
                        std::cout << "error:lexical:" << comment_line << ":" << comment_column << ": unterminated comment"; 
                    }
<comment>\n                  {column = 1; line++;}
<comment>"/*/"       { 
                        BEGIN(INITIAL); 
                        column += yyleng; 
                    }
<comment>"*/"       { 
                        BEGIN(INITIAL); 
                        column += yyleng; 
                    }
<comment>"/*"       { 
                        std::cout << "\nwarning:" << line << ":" << column << ": '/*' within block comment";
                        column += yyleng; 
                    }
<comment>.  {column += yyleng;}

"void"              { printfVerification(); std::cout << "VOID"; column += yyleng; }
"int"               { printfVerification(); std::cout << "INT"; column += yyleng; }
"char"              { printfVerification(); std::cout << "CHAR"; column += yyleng; }
"return"            { printfVerification(); std::cout << "RETURN"; column += yyleng; }
"break"             { printfVerification(); std::cout << "BREAK"; column += yyleng; }
"switch"            { printfVerification(); std::cout << "SWITCH"; column += yyleng; }
"case"              { printfVerification(); std::cout << "CASE"; column += yyleng; }
"default"           { printfVerification(); std::cout << "DEFAULT"; column += yyleng; }
"do"                { printfVerification(); std::cout << "DO"; column += yyleng; }
"while"             { printfVerification(); std::cout << "WHILE"; column += yyleng; }
"for"               { printfVerification(); std::cout << "FOR"; column += yyleng; }
"if"                { printfVerification(); std::cout << "IF"; column += yyleng; }
"else"              { printfVerification(); std::cout << "ELSE"; column += yyleng; }
"typedef"           { printfVerification(); std::cout << "TYPEDEF"; column += yyleng; }
"struct"            { printfVerification(); std::cout << "STRUCT"; column += yyleng; }
"+"                 { printfVerification(); std::cout << "PLUS"; column += yyleng; }
"-"                 { printfVerification(); std::cout << "MINUS"; column += yyleng; }
"*"                 { printfVerification(); std::cout << "MULTIPLY"; column += yyleng; }
"/"                 { printfVerification(); std::cout << "DIV"; column += yyleng; }
"%"                 { printfVerification(); std::cout << "REMAINDER"; column += yyleng; }
"++"                { printfVerification(); std::cout << "INC"; column += yyleng; }
"--"                { printfVerification(); std::cout << "DEC"; column += yyleng; }
"&"                 { printfVerification(); std::cout << "BITWISE_AND"; column += yyleng; }
"|"                 { printfVerification(); std::cout << "BITWISE_OR"; column += yyleng; }
"~"                 { printfVerification(); std::cout << "BITWISE_NOT"; column += yyleng; }
"^"                 { printfVerification(); std::cout << "BITWISE_XOR"; column += yyleng; }
"!"                 { printfVerification(); std::cout << "NOT"; column += yyleng; }
"&&"                { printfVerification(); std::cout << "LOGICAL_AND"; column += yyleng; }
"||"                { printfVerification(); std::cout << "LOGICAL_OR"; column += yyleng; }
"=="                { printfVerification(); std::cout << "EQUAL"; column += yyleng; }
"!="                { printfVerification(); std::cout << "NOT_EQUAL"; column += yyleng; }
"<"                 { printfVerification(); std::cout << "LESS_THAN"; column += yyleng; }
">"                 { printfVerification(); std::cout << "GREATER_THAN"; column += yyleng; }
"<="                { printfVerification(); std::cout << "LESS_EQUAL"; column += yyleng; }
">="                { printfVerification(); std::cout << "GREATER_EQUAL"; column += yyleng; }
">>"                { printfVerification(); std::cout << "R_SHIFT"; column += yyleng; }
"<<"                { printfVerification(); std::cout << "L_SHIFT"; column += yyleng; }
"="                 { printfVerification(); std::cout << "ASSIGN"; column += yyleng; }
"+="                { printfVerification(); std::cout << "ADD_ASSIGN"; column += yyleng; }
"-="                { printfVerification(); std::cout << "MINUS_ASSIGN"; column += yyleng; }
";"                 { printfVerification(); std::cout << "SEMICOLON"; column += yyleng; }
","                 { printfVerification(); std::cout << "COMMA"; column += yyleng; }
":"                 { printfVerification(); std::cout << "COLON"; column += yyleng; }
"("                 { printfVerification(); std::cout << "L_PAREN"; column += yyleng; }
")"                 { printfVerification(); std::cout << "R_PAREN"; column += yyleng; }
"{"                 { printfVerification(); std::cout << "L_CURLY_BRACKET"; column += yyleng; }
"}"                 { printfVerification(); std::cout << "R_CURLY_BRACKET"; column += yyleng; }
"["                 { printfVerification(); std::cout << "L_SQUARE_BRACKET"; column += yyleng; }
"]"                 { printfVerification(); std::cout << "R_SQUARE_BRACKET"; column += yyleng; }
"?"                 { printfVerification(); std::cout << "TERNARY_CONDITIONAL"; column += yyleng; }
"#"                 { printfVerification(); std::cout << "NUMBER_SIGN"; column += yyleng; }
"->"                { printfVerification(); std::cout << "POINTER"; column += yyleng; }
"printf"            { printfVerification(); std::cout << "PRINTF"; column += yyleng; }
"scanf"             { printfVerification(); std::cout << "SCANF"; column += yyleng; }
"define"            { printfVerification(); std::cout << "DEFINE"; column += yyleng; }
"exit"              { printfVerification(); std::cout << "EXIT"; column += yyleng; }

[\\][abfnrtv\\'\"?0]    { printfVerification(); std::cout << "CHARACTER(" << yytext << ")"; column += yyleng; }
[a-zA-Z_]+[a-zA-Z0-9_]*  { 
                            if (yyleng>255)
                                std::cout << "\nerror:lexical:" << line << ":" << column << ": identifier too long"; 
                            else{
                                printfVerification(); 
                                std::cout << "IDENTIFIER(" << yytext << ")"; column += yyleng;
                                }
                        }
\"(\\.|[^"\\])*\"       { printfVerification(); std::cout << "STRING"; printString_Character(yytext); column += yyleng; }
"'"(\\.|[^\\']){1}"'"   { printfVerification(); std::cout << "CHARACTER"; printString_Character(yytext); column += yyleng; }

0[xX][0-9a-fA-F]+   { printfVerification(); std::cout << "NUM_HEXA(" << yytext << ")"; column += yyleng; }
0[1-7][0-7]*        { printfVerification(); std::cout << "NUM_OCTAL(" << yytext << ")"; column += yyleng; }
[0-9]+              { printfVerification(); std::cout << "NUM_INTEGER(" << yytext << ")"; column += yyleng; }

.                   { printfVerification(); std::cout << "error:lexical:" << line << ":" << column << ": " << yytext; column += yyleng; }

%%

int main(int argc, char **argv) {
    yylex();
    return 0;
}
