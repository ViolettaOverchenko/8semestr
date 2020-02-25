from defs import *
#from goto import with_goto
import sys

class Scaner():
	def __init__(self, t):
		self.uk = 0 	# Указатель текущей позиции в исходном тексте
		self.lex = [] 				# Локальные переменные типа и изображения лексем

		self.Keyword = ("double", "char", "while", "main", "return")
		self.IndexKeyword = (DOUBLE, CHAR, WHILE, MAIN, RETURN)

		self.text = t

	def printErrorScaner(self, text):
		print(text)

	def printError(self, text):
		line = 1
		symbol = 1
		for i in range(self.uk):
			if ( self.text[i] == '\n' ):
				line += 1
				symbol = 1
			else:
				symbol += 1
		print('String: ' + str(line) + '; Symbol: ' + str(symbol) + '\n' )
		sys.exit(text)

	def endScaning(self):
		print('End of scaning! Thanks!') # Конец сканирования

	def get_lex(self):
		return self.lex

	def get_uk(self):
		return self.uk

	def set_uk(self, c_p):
		self.uk = c_p

	

	#Сканер
	def propusk(self):
			while (self.text[self.uk] == ' ' or self.text[self.uk] == '\t' 
				or self.text[self.uk] == '\n'):
				self.uk += 1

	def scan(self):

		self.lex = [] # Очищаем лексему

		self.propusk()
		"""
			Многострочные комментарии - их пропускаем. 
			Если комментарий начался, но не закончился весь код считаем ошибкой.
		"""
		if (self.text[self.uk] == '/' and self.text[self.uk + 1] == '*'):
			self.uk += 2
			#Если комментарий так и не закончится, вернём ошибку лексемы
			while (not (self.text[self.uk] == '*' and self.text[self.uk + 1] == '/')):
				self.uk += 1
				if self.text[self.uk + 1] == '\0':
					self.printErrorScaner('Error! Endless comment!')
					self.uk += 1
					return ERROR
			self.uk += 2
			self.propusk()
		#Пропуск однострочного комментария
		if (self.text[self.uk] == '/' and self.text[self.uk + 1] == '/'):
			self.uk += 3
			while self.text[self.uk] != '\n':
				self.uk += 1
			self.propusk()
				
		#Конец файла. Конец сканирования.
		if self.text[self.uk] == '\0':
			self.lex = self.text[self.uk]
			return END
		elif (self.text[self.uk] <= '9' and self.text[self.uk] >= '0'):
			self.lex.append(self.text[self.uk])
			self.uk += 1
			while (self.text[self.uk] <= '9' and self.text[self.uk] >= '0'):
				if len(self.lex) < MAX_CONSTINT - 1:
					self.lex.append(self.text[self.uk])
					self.uk += 1
				else:
					while (self.text[self.uk] <= '9' and self.text[self.uk] >= '0'):
						self.uk += 1
					self.printErrorScaner('Error! Constant too long!')
					return ERROR
			return CONSTINT
		elif ( ( self.text[self.uk] >= 'a' and self.text[self.uk] <= 'z' ) 
			or ( self.text[self.uk] >= 'A' and self.text[self.uk] <= 'Z' ) 
			or self.text[self.uk] == '_' ):
			self.lex.append(self.text[self.uk])
			self.uk += 1
			while ( ( self.text[self.uk] <= '9' and self.text[self.uk] >= '0' ) 
				or ( self.text[self.uk] >= 'a' and self.text[self.uk] <= 'z' ) 
				or ( self.text[self.uk] >= 'A' and self.text[self.uk] <= 'Z' ) 
				or self.text[self.uk] == '_' ):
				#Исключаем длинный идентификатор
				if len(self.lex) < MAX_LEX - 1:
					self.lex.append(self.text[self.uk])
					self.uk += 1
				else:
					self.uk += 1

			#Проверка на ключевое слово
			for i in range(len(self.Keyword)):
				if ''.join(self.lex) == self.Keyword[i]:
					return self.IndexKeyword[i]
			return ID

		elif (self.text[self.uk] == '\'' and self.text[self.uk + 2] == '\''):
			self.lex.append(self.text[self.uk + 1])		# добавляем только символ. константу без кавычек
			self.uk += 3
			return CONSTCHAR


		elif (self.text[self.uk] == '\''):
			self.uk += 1
			while (self.text[self.uk] != '\'' and self.text[self.uk] != '\n'):
				self.lex.append(self.text[self.uk])
				self.uk += 1
			if self.text[self.uk] != '\'':
				self.printErrorScaner('Error! Invalid string constant!')
				return ERROR
			self.uk += 1	# закрывающая кавычка
			return CONSTSTRING


		elif self.text[self.uk] == ',':
			self.lex.append(self.text[self.uk])
			self.uk += 1
			return COMMA
		elif self.text[self.uk] == ';':
			self.lex.append(self.text[self.uk])
			self.uk += 1
			return SEMICOLON
		elif self.text[self.uk] == '(':
			self.lex.append(self.text[self.uk])
			self.uk += 1
			return LBRACKET
		elif self.text[self.uk] == ')':
			self.lex.append(self.text[self.uk])
			self.uk += 1
			return RBRACKET
		elif self.text[self.uk] == '{':
			self.lex.append(self.text[self.uk])
			self.uk += 1
			return LBRACE
		elif self.text[self.uk] == '}':
			self.lex.append(self.text[self.uk])
			self.uk += 1
			return RBRACE
		elif self.text[self.uk] == '[':
			self.lex.append(self.text[self.uk])
			self.uk += 1
			return LSBRACKET
		elif self.text[self.uk] == ']':
			self.lex.append(self.text[self.uk])
			self.uk += 1
			return RSBRACKET

		elif self.text[self.uk] == '<':
			self.lex.append(self.text[self.uk])
			self.uk += 1
			if self.text[self.uk] == '=':
				self.lex.append(self.text[self.uk])
				self.uk += 1
				return LE
			return LT
		elif self.text[self.uk] == '>':
			self.lex.append(self.text[self.uk])
			self.uk += 1
			if self.text[self.uk] == '=':
				self.lex.append(self.text[self.uk])
				self.uk += 1
				return GE
			return GT
		elif self.text[self.uk] == '=':
			self.lex.append(self.text[self.uk])
			self.uk += 1
			if self.text[self.uk] == '=':
				self.lex.append(self.text[self.uk])
				self.uk += 1
				return EQ
			return SAVE
		elif (self.text[self.uk] == '!' and self.text[self.uk + 1] == '='):
			self.lex.append(self.text[self.uk])
			self.lex.append(self.text[self.uk + 1])
			self.uk += 2
			return NEQ
		elif ( self.text[self.uk] == '+' ):
			self.lex.append(self.text[self.uk])
			self.uk += 1
			#Плюс-равно
			if ( self.text[self.uk] == '=' ):
				self.lex.append(self.text[self.uk])
				self.uk += 1
				return PLUSEQ
			#Плюс-плюс
			elif ( self.text[self.uk] == '+' ):
				self.lex.append(self.text[self.uk])
				self.uk += 1
				return PLUSPLUS
			return PLUS
		elif ( self.text[self.uk] == '-' ):
			self.lex.append(self.text[self.uk])
			self.uk += 1
			#Минус-равно
			if ( self.text[self.uk] == '=' ):
				self.lex.append(self.text[self.uk])
				self.uk += 1
				return MINUSEQ
			#Минус-минус
			elif ( self.text[self.uk] == '-' ):
				self.lex.append(self.text[self.uk])
				self.uk += 1
				return MINUSMINUS
			return MINUS
		elif ( self.text[self.uk] == '/' ):
			self.lex.append(self.text[self.uk])
			self.uk += 1
			if ( self.text[self.uk] == '=' ):
				self.lex.append(self.text[self.uk])
				self.uk += 1
				return DIVEQ
			return DIV
		elif ( self.text[self.uk] == '*' ):
			self.lex.append(self.text[self.uk])
			self.uk += 1
			if ( self.text[self.uk] == '=' ):
				self.lex.append(self.text[self.uk])
				self.uk += 1
				return MULTEQ
			return MULT
		elif ( self.text[self.uk] == '%' ):
			self.lex.append(self.text[self.uk])
			self.uk += 1
			if ( self.text[self.uk] == '=' ):
				self.lex.append(self.text[self.uk])
				self.uk += 1
				return MODEQ
			return MOD
		else:
			self.printErrorScaner('Error! Unknown character.')
			self.lex.append(self.text[self.uk])
			self.uk += 1
			return ERROR









