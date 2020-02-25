#Общие типы и макроопределения
MAX_TEXT = 10000		# Максимальная длина текста
MAX_LEX = 100			# Максимальная длина лексемы
MAX_KEYW = 5			# Число ключевых слов
MAX_CONSTINT = 20		# Максимальная длина целочисленной константы

DOUBLE = 1
CHAR = 2
WHILE = 3
MAIN = 4
RETURN = 5
FUNCTION = 6

ID = 10

CONSTINT = 20
CONSTCHAR = 21
CONSTSTRING = 22

COMMA = 31
SEMICOLON = 32
LBRACKET = 33
RBRACKET = 34
LBRACE = 35
RBRACE = 36
LSBRACKET = 37
RSBRACKET = 38

LT = 40
LE = 41
GT = 42
GE = 43
EQ = 44
NEQ = 45
PLUSEQ = 46
MINUSEQ = 47
DIVEQ = 48
MODEQ = 49
MULTEQ = 50
PLUSPLUS = 51
MINUSMINUS = 52
PLUS = 53
MINUS = 54
MULT = 55
DIV = 56
MOD = 57
SAVE = 58

END = 60
ERROR = 61 

IDENTITY = {1: 'double', 2: 'char', 6: 'function'}

UNKNOWN = 80
'''
FOR_PRINT = {1: 'INT', 2: '_INT64', 3: 'FOR', 4: 'VOID', 10: 'ID', 20: 'CONSTINT', 21: 'CONSTINT16', 
			30: 'POINT', 31: 'COMMA', 32: 'SEMICOLON', 33: 'LBRACKET', 34: 'RBRACKET', 35: 'LBRACE', 
			36: 'RBRACE', 37: 'LSBRACKET', 38: 'RSBRACKET', 40: 'LT', 41: 'LE', 42: 'GT', 43: 'GE', 
			44: 'EQ', 45: 'NEQ', 46: 'PLUSEQ', 47: 'MINUSEQ', 48: 'DIVEQ', 49: 'MODEQ', 50: 'MULTEQ', 
			51: 'PLUSPLUS', 52: 'MINUSMINUS', 53: 'PLUS', 54: 'MINUS', 55: 'MULT', 56: 'DIV', 57: 'MOD',
			58: 'RMOVE', 59: 'LMOVE', 60: 'SAVE', 70: 'END', 71: 'ERROR'}

IDENTITY = {1: 'int', 2: '_int64', 4: 'void'}'''