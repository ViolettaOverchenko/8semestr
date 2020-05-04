#pragma once

// Общие типы и макроопределения
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_TEXT 10000		// Максимальная длина текста
#define MAX_LEX 100			// Максимальная длина лексемы
#define MAX_KEYW 5			// Число ключевых слов
#define MAX_CONSTINT 20		// Максимальная длина целочисленной константы



#define LINE_INC if (text[uk] == '\n' && uk >= max){ max = uk; line++; pos = 0;}
#define POS_INC if (uk > max){ pos++; max = uk;}

typedef char LEX[MAX_LEX];
typedef char TypeMod[MAX_TEXT];

#define DOUBLE 1
#define CHAR 2
#define WHILE 3
#define MAIN 4
#define RETURN 5
#define FUNCTION 6

#define ID 10

#define CONSTINT 20
#define CONSTCHAR 21
#define CONSTSTRING 22

#define COMMA 31
#define SEMICOLON 32
#define LBRACKET 33
#define RBRACKET 34
#define LBRACE 35
#define RBRACE 36
#define LSBRACKET 37
#define RSBRACKET 38

#define LT 40
#define LE 41
#define GT 42
#define GE 43
#define EQ 44
#define NEQ 45
#define PLUSEQ 46
#define MINUSEQ 47
#define DIVEQ 48
#define MODEQ 49
#define MULTEQ 50
#define PLUSPLUS 51
#define MINUSMINUS 52
#define PLUS 53
#define MINUS 54
#define MULT 55
#define DIV 56
#define MOD 57
#define SAVE 58

#define END 60
#define ERROR 61 

