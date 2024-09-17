%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sintatico.tab.h"

#define ERROR_LINE_DISPLAY_SIZE 4096

char error_line[ERROR_LINE_DISPLAY_SIZE],
     prev_line[ERROR_LINE_DISPLAY_SIZE];

char* error_line_ptr = error_line,
    * prev_line_ptr = prev_line;

unsigned long count = 0,
              line = 1,
              col = 1,
              prev_line_num = 1,
              prev_col = 1;

static void comment();

%}

%%
static void comment(int start_line, int start_col){
    int ch,
        prev = '*';
    
    while( (ch = input()) > 0){
        strncat(error_line, &ch, 1);
        col++;
        switch(ch){

            case '*':
                if( (ch = input()) == '/'){
                    col += 1;
                    strncat(error_line, &ch, 1);
                    return;
                }
                unput(ch);
                ch = '*';

                if(prev == '/'){
                    if(count > 0)
                        putchar('\n');
                    printf("warning:%d:%d: \'/*\' within block comment"
                        , line, col - 2);
                    ++count;
                }
                break;

            case '\n':
                line++;
                col = 1;
                prev_line_num = line; prev_col = col;
                strcpy(prev_line, error_line);
                strcpy(error_line, "");
                break;

            default:
                break;
        }
        prev = ch;
    }

    ++count;

    printf("error:lexical:%d:%d: unterminated comment", 
        start_line, start_col);
    exit(EXIT_FAILURE);
}
      
"void"      { strncat(error_line, yytext, yyleng); col += yyleng; return VOID; }
"int"       { strncat(error_line, yytext, yyleng); col += yyleng; return INT; }
"char"      { strncat(error_line, yytext, yyleng); col += yyleng; return CHAR; }
"return"    { strncat(error_line, yytext, yyleng); col += yyleng; return RETURN; }
"break"     { strncat(error_line, yytext, yyleng); col += yyleng; return BREAK; }
"switch"    { strncat(error_line, yytext, yyleng); col += yyleng; return SWITCH; }
"case"      { strncat(error_line, yytext, yyleng); col += yyleng; return CASE; }
"default"   { strncat(error_line, yytext, yyleng); col += yyleng; return DEFAULT; }
"do"        { strncat(error_line, yytext, yyleng); col += yyleng; return DO; }
"while"     { strncat(error_line, yytext, yyleng); col += yyleng; return WHILE; }
"for"       { strncat(error_line, yytext, yyleng); col += yyleng; return FOR; }
"if"        { strncat(error_line, yytext, yyleng); col += yyleng; return IF; }
"else"      { strncat(error_line, yytext, yyleng); col += yyleng; return ELSE; }
"typedef"   { strncat(error_line, yytext, yyleng); col += yyleng; return TYPEDEF; }
"struct"    { strncat(error_line, yytext, yyleng); col += yyleng; return STRUCT; }
"/*"        { strncat(error_line, yytext, yyleng); col += 2; comment(line, col - 2); }
"//"[^\n]*  { strncat(error_line, yytext, yyleng); }
"++"        { strncat(error_line, yytext, yyleng); col += yyleng; return INC; }
"+"         { strncat(error_line, yytext, yyleng); col += yyleng; return PLUS; }
"--"        { strncat(error_line, yytext, yyleng); col += yyleng; return DEC; }
"-"         { strncat(error_line, yytext, yyleng); col += yyleng; return MINUS; }
"->"        { strncat(error_line, yytext, yyleng); col += yyleng; return POINTER; }
"+="        { strncat(error_line, yytext, yyleng); col += yyleng; return ADD_ASSIGN; }
"-="        { strncat(error_line, yytext, yyleng); col += yyleng; return MINUS_ASSIGN; }
"*"         { strncat(error_line, yytext, yyleng); col += yyleng; return MULTIPLY; }
"/"         { strncat(error_line, yytext, yyleng); col += yyleng; return DIV; }
"%"         { strncat(error_line, yytext, yyleng); col += yyleng; return REMAINDER; }
"&&"        { strncat(error_line, yytext, yyleng); col += yyleng; return LOGICAL_AND; }
"&"         { strncat(error_line, yytext, yyleng); col += yyleng; return BITWISE_AND; }
"||"        { strncat(error_line, yytext, yyleng); col += yyleng; return LOGICAL_OR; }
"|"         { strncat(error_line, yytext, yyleng); col += yyleng; return BITWISE_OR; }
"=="        { strncat(error_line, yytext, yyleng); col += yyleng; return EQUAL; }
"="         { strncat(error_line, yytext, yyleng); col += yyleng; return ASSIGN; }
">>"        { strncat(error_line, yytext, yyleng); col += yyleng; return R_SHIFT; }
"<<"        { strncat(error_line, yytext, yyleng); col += yyleng; return L_SHIFT; }
"~"         { strncat(error_line, yytext, yyleng); col += yyleng; return BITWISE_NOT; }
"^"         { strncat(error_line, yytext, yyleng); col += yyleng; return BITWISE_XOR; }
"!="        { strncat(error_line, yytext, yyleng); col += yyleng; return NOT_EQUAL; }
"<="        { strncat(error_line, yytext, yyleng); col += yyleng; return LESS_EQUAL; }
">="        { strncat(error_line, yytext, yyleng); col += yyleng; return GREATER_EQUAL; }
"!"         { strncat(error_line, yytext, yyleng); col += yyleng; return NOT; }
"<"         { strncat(error_line, yytext, yyleng); col += yyleng; return LESS_THAN; }
">"         { strncat(error_line, yytext, yyleng); col += yyleng; return GREATER_THAN; }
";"         { strncat(error_line, yytext, yyleng); col += yyleng; return SEMICOLON; }
","         { strncat(error_line, yytext, yyleng); col += yyleng; return COMMA; }
":"         { strncat(error_line, yytext, yyleng); col += yyleng; return COLON; }
"("         { strncat(error_line, yytext, yyleng); col += yyleng; return L_PAREN; }
")"         { strncat(error_line, yytext, yyleng); col += yyleng; return R_PAREN; }
"{"         { strncat(error_line, yytext, yyleng); col += yyleng; return L_CURLY_BRACKET; }
"}"         { strncat(error_line, yytext, yyleng); col += yyleng; return R_CURLY_BRACKET; }
"["         { strncat(error_line, yytext, yyleng); col += yyleng; return L_SQUARE_BRACKET; }
"]"         { strncat(error_line, yytext, yyleng); col += yyleng; return R_SQUARE_BRACKET; }
"?"	        { strncat(error_line, yytext, yyleng); col += yyleng; return TERNARY_CONDITIONAL; }
"#"         { strncat(error_line, yytext, yyleng); col += yyleng; return NUMBER_SIGN; }
"printf"    { strncat(error_line, yytext, yyleng); col += yyleng; return PRINTF; }
"scanf"     { strncat(error_line, yytext, yyleng); col += yyleng; return SCANF; }
"define"    { strncat(error_line, yytext, yyleng); col += yyleng; return DEFINE; }
"exit"      { strncat(error_line, yytext, yyleng); col += yyleng; return EXIT; }

[_a-zA-Z][_a-zA-Z0-9]* {
    if(yyleng > 255){
        if(count > 0)
            putchar('\n');
        printf("error:lexical:%d:%d: identifier too long", line, 
            col);
    }
    else{
        strncat(error_line, yytext, yyleng); col += yyleng;
        return IDENTIFIER;
    }
}

"0"[xX][a-fA-F0-9]+ { strncat(error_line, yytext, yyleng); col += yyleng; return NUM_HEXA; }
"0"[1-7][0-7]*      { strncat(error_line, yytext, yyleng); col += yyleng; return NUM_OCTAL; }
[0-9][0-9]*         { strncat(error_line, yytext, yyleng); col += yyleng; return NUM_INTEGER; }
["]([^"\\\n]|\\.|\\\n)*["] { strncat(error_line, yytext, yyleng); col += yyleng; return STRING; }
'([^'\\\n]|\\.)'    { strncat(error_line, yytext, yyleng); col += yyleng; return CHARACTER; }
\n+                 { prev_line_num = line; prev_col = col;
                      line += yyleng; col = 1;
                      strcpy(prev_line, error_line);
                      strcpy(error_line, ""); 
                    }
[ \t]               { strncat(error_line, yytext, yyleng); col += yyleng; }
[\r\v\f\b\a\0]+     /* white space */
<<EOF>>             { return END_OF_FILE;}
. { 
    printf("error:lexical:%d:%d: %s", line, col, yytext);
    ++col;
    exit(EXIT_FAILURE);
}

%%

void get_remaining_line(){
    char ch;
    
    while( (ch = input()) != EOF && ch != '\n' && 
        strlen(error_line) < ERROR_LINE_DISPLAY_SIZE){
        strncat(error_line, &ch, 1);
    }
}