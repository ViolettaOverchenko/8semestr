from defs import *
from scaner import Scaner
from semantica import *

class Diagram():
	def __init__(self, text):
		self.scaner = Scaner(text) # Инициализация сканера
		self.__tree = Tree()  # инициализация семантического дерева
		self.curType = '' # текущий тип идентификатора для синтаксического дерева
		self.flagInterpret = True	# флаг интерпретации, если True, то семантика включена, иначе семантику пропускаем

	def setFlagInterpret(self):
		f = int(input("Введите значение флага интерпретации (0 - семантика выключена, 1 - включена): "));
		if f == 0:
			self.flagInterpret = False;

	# Описания
	def S(self):
		_type = '' # Тип лексемы

		c_p = self.scaner.get_uk() # Запомнить текущую позицию
		_type = self.scaner.scan() # Получить текущую лексему

		#if ( _type != DOUBLE and _type != CHAR ):
		#	self.scaner.printError("ERROR! Expected double or char.")
		self.scaner.set_uk(c_p) # Вернуть старую позицию

		while ( _type == DOUBLE or _type == CHAR ):
			self.T()
			c_p = self.scaner.get_uk()
			_type = self.scaner.scan()
			self.scaner.set_uk(c_p)

		#if ( _type != DOUBLE and _type != CHAR and _type != END ):
			#self.scaner.printError("ERROR! Expected double or char or end.")

	# Одно описание
	def T(self):
		_type = '' # Тип лексемы

		c_p = self.scaner.get_uk() # Запомнить текущую позицию
		_type = self.scaner.scan() # Получить текущую лексему
		self.scaner.set_uk(c_p) # Вернуть старую позицию

		if ( self.FOrW() ):
			self.F()
		else:
			self.W()


	#Функция или данные
	def FOrW(self):
		c_p = self.scaner.get_uk() # Запомнить текущую позицию
		_type = self.scaner.scan() # Получить текущую лексему
		
		if ( _type == DOUBLE or _type == CHAR ):
			_type = self.scaner.scan() # Получить текущую лексему
			if ( _type == MAIN ):
				self.scaner.set_uk(c_p) # Вернуть старую позицию
				return True
			elif ( _type == ID ):
				
				_type = self.scaner.scan() # Получить текущую лексему
				#self.scaner.set_uk(c_p) # Вернуть старую позицию
				if (_type == LBRACKET):
					self.scaner.set_uk(c_p) # Вернуть старую позицию
					return True

		self.scaner.set_uk(c_p) # Вернуть старую позицию

		return False

	#Данные
	def W(self):
		_type = self.scaner.scan() #Получить текущую лексему
		
		if ( _type != DOUBLE and _type != CHAR ):
			self.scaner.printError("ERROR! Expected double or char.")

		self.curType = IDENTITY[_type]

		self.D();

		_type = self.scaner.scan() #Получить текущую лексему

		if ( _type != SEMICOLON ):
			self.scaner.printError("ERROR! Expected semicolon (;).")

	#Список
	def D(self):
		_type = '' #Тип лексемы

		self.Z()

		c_p = self.scaner.get_uk() #Запомнить текущую позицию
		_type = self.scaner.scan() #Получить текущую лексему

		while ( _type == COMMA ):
			self.Z()
			c_p = self.scaner.get_uk() #Запомнить текущую позицию
			_type = self.scaner.scan() #Получить текущую лексему

		self.scaner.set_uk(c_p) #Вернуть старую позицию

	#Переменная, массив
	def Z(self):
		c_p = self.scaner.get_uk() #Запомнить текущую позицию
		_type = self.scaner.scan() #Получить текущую лексему

		if ( _type != ID ):
			self.scaner.printError("ERROR! Expected identifier.")

		_type = self.scaner.scan() #Получить текущую лексему
		self.scaner.set_uk(c_p) #Вернуть старую позицию
		if ( _type == LSBRACKET ):
			_type = self.scaner.scan() #Получить текущую лексему
			# Занесение идентификатора массива в таблицу с типом curType

			# добавили флаг интерпретации

			if (self.flagInterpret):
				v = self.__tree.semInclude(''.join(self.scaner.get_lex()), self.curType + str('[]'), c_p)
				if ( type(v) == str ):
					self.scaner.printError(v)
		else:
			_type = self.scaner.scan() #Получить текущую лексему
			# Занесение идентификатора в таблицу с типом curType
			if (self.flagInterpret):
				v = self.__tree.semInclude(''.join(self.scaner.get_lex()), self.curType, c_p)
				if ( type(v) == str ):
					self.scaner.printError(v)

		c_p = self.scaner.get_uk() #Запомнить текущую позицию
		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type == SAVE ):
			self.A()
		elif ( _type == LSBRACKET ):
			c_p = self.scaner.get_uk() #Запомнить текущую позицию
			_type = self.scaner.scan() #Получить текущую лексему
			if ( _type != RSBRACKET ):
				self.scaner.set_uk(c_p) #Вернуть старую позицию
				self.A()
				#Проверим закрывается ли скобка
				c_p = self.scaner.get_uk() #Запомнить текущую позицию
				_type = self.scaner.scan() #Получить текущую лексему
				if ( _type != RSBRACKET ):
					self.scaner.printError("ERROR! Expected right square bracket.")
				c_p = self.scaner.get_uk() #Запомнить текущую позицию
				_type = self.scaner.scan() #Получить текущую лексему
				if ( _type == SAVE ):
					self.A()
				else:
					self.scaner.set_uk(c_p) #Вернуть старую позицию
		else:
			self.scaner.set_uk(c_p) #Вернуть старую позицию
	
	#Функция
	def F(self):
		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type != DOUBLE and _type != CHAR ):
			self.scaner.printError("ERROR! Expected DOUBLE or CHAR.")

		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type != ID and _type != MAIN ):
			self.scaner.printError("ERROR! Expected identifier or main.")

		c_p = self.scaner.get_uk() #Запомнить текущую лексему

		# Занесение имя функции в таблицу
		if (self.flagInterpret):
			v = self.__tree.semInclude(''.join(self.scaner.get_lex()), IDENTITY[FUNCTION], c_p)
			if ( type(v) == str ):
				self.scaner.printError(v)

		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type != LBRACKET ):
			self.scaner.printError("ERROR! Expected left bracket.")

		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type != RBRACKET ):
			self.scaner.printError("ERROR! Expected right bracket.")

		self.Q()

	#Составной оператор
	def Q(self):
		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type != LBRACE ):
			self.scaner.printError("ERROR! Expected left brace.")
		if (self.flagInterpret):
			self.__tree.nextLavel()
		self.O()
		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type != RBRACE ):
			self.scaner.printError("ERROR! Expected right brace.")
		if (self.flagInterpret):
			self.__tree.prevLavel()

	#Операторы и описания
	def O(self):
		c_p = self.scaner.get_uk() #Запомнить текущую позицию
		_type = self.scaner.scan() #Получить текущую лексему
		self.scaner.set_uk(c_p) #Вернуть старую позицию

		while ( _type != RBRACE ):
			if ( _type == DOUBLE or _type == CHAR ):
				self.W()
			else:
				self.K()
			c_p = self.scaner.get_uk() #Запомнить текущую позицию
			_type = self.scaner.scan() #Получить текущую лексему
			self.scaner.set_uk(c_p) #Вернуть старую позицию

	#Оператор и вызов функции
	def K(self):
		c_p = self.scaner.get_uk() #Запомнить текущую позицию
		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type == LBRACE ):
			self.scaner.set_uk(c_p) #Вернуть старую позицию
			self.Q()
		elif ( _type == WHILE ):
			self.scaner.set_uk(c_p) #Вернуть старую позицию+
			self.H()
		elif ( _type == SEMICOLON ):
			return #пустой оператор
		elif ( _type == ID ):
			# Поиск имени функции и переменной в таблице
			if (self.flagInterpret):
				v1 = self.__tree.semGetType(''.join(self.scaner.get_lex()))
				v = self.__tree.semGetFunct(''.join(self.scaner.get_lex()))
				if ( type(v) == str and type(v1) == str ):
					_type = self.scaner.scan() #Получить текущую лексему
					if ( _type == LBRACKET ):
						self.scaner.printError(v)
					else:
						self.scaner.printError(v1)

			_type = self.scaner.scan() #Получить текущую лексему
			if ( _type == LBRACKET ):
				_type = self.scaner.scan() #Получить текущую лексему
				if ( _type != RBRACKET ):
					self.scaner.printError("ERROR! Expected right bracket.")
			elif ( _type == LSBRACKET ):	
				self.A()
				_type = self.scaner.scan() #Получить текущую лексему
				if ( _type != RSBRACKET ):
					self.scaner.printError("ERROR! Expected right square bracket.")
				self.scaner.set_uk(c_p) #Вернуть старую позицию
				self.U()
			else:
				self.scaner.set_uk(c_p) #Вернуть старую позицию
				self.U()
		else:
			self.scaner.set_uk(c_p) #Вернуть старую позицию
			self.U()

	#WHILE
	def H(self):
		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type != WHILE ):
			self.scaner.printError("ERROR! Expected WHILE.")

		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type != LBRACKET ):
			self.scaner.printError("ERROR! Expected left bracket.")

		self.A()

		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type != RBRACKET ):
			self.scaner.printError("ERROR! Expected right bracket.")

		self.K()

	#Присваивание, бинарное присваивание и инкрементирование и декрементирование
	def U(self):
		_type = self.scaner.scan() #Получить текущую лексему

		if ( _type != ID and _type != PLUSPLUS and _type != MINUSMINUS ):
			self.scaner.printError("ERROR! Expected assignment (identifier, ++ or --).")

		if ( _type == ID ):
			# Поиск имени идентификатора в таблице
			if (self.flagInterpret):
				v = self.__tree.semGetType(''.join(self.scaner.get_lex()))
				if ( type(v) == str ):
					self.scaner.printError(v)

			c_p = self.scaner.get_uk() #Запомнить текущую позицию
			_type = self.scaner.scan() #Получить текущую лексему

			if (_type == LSBRACKET):
				self.A()

				_type = self.scaner.scan() #Получить текущую лексему
				if ( _type == RSBRACKET ):
					_type = self.scaner.scan() #Получить текущую лексему
			else:
				self.scaner.set_uk(c_p) #Вернуть старую позицию
				_type = self.scaner.scan() #Получить текущую лексему

			if ( _type != SAVE and _type != PLUSEQ and _type != MINUSEQ and _type != MULTEQ 
				and _type != DIVEQ and _type != MODEQ and _type != PLUSPLUS and _type != MINUSMINUS ):
				self.scaner.printError("ERROR! Expected assignment (=, +=, -=, *=. %=, /=, ++ or --).")

			if ( _type == SAVE or _type == PLUSEQ or _type == MINUSEQ or _type == MULTEQ 
				or _type == DIVEQ or _type == MODEQ ):
				self.A()
			elif ( _type == PLUSPLUS or _type == MINUSMINUS ):
				return

		elif ( _type == PLUSPLUS or _type == MINUSMINUS ):
			_type = self.scaner.scan() #Получить текущую лексему
			if ( _type != ID ):
				self.scaner.printError("ERROR! Expected identifier.")

			# Поиск имени идентификатора в таблице
			if (self.flagInterpret):
				v = self.__tree.semGetType(''.join(self.scaner.get_lex()))
				if ( type(v) == str ):
					self.scaner.printError(v)

	#Выражение
	def A(self):
		c_p = self.scaner.get_uk() #Запомнить текущую позицию
		_type = self.scaner.scan() #Получить текущую лексему
		if ( _type != PLUS and _type != MINUS ):
			self.scaner.set_uk(c_p) #Вернуть старую позицию

		if ( _type == PLUSPLUS or _type == MINUSMINUS ):
			c_p = self.scaner.get_uk() #Запомнить текущую позицию
			_type = self.scaner.scan() #Получить текущую лексему


		self.B()
		c_p = self.scaner.get_uk() #Запомнить текущую позицию
		_type = self.scaner.scan() #Получить текущую лексему

		if ( _type == PLUSPLUS or _type == MINUSMINUS ):
			return

		while ( _type >= LT and _type <= NEQ ):
			self.B()
			c_p = self.scaner.get_uk() #Запомнить текущую позицию
			_type = self.scaner.scan() #Получить текущую лексему
		self.scaner.set_uk(c_p) #Вернуть старую позицию

	#Слагаемое
	def B(self):
		self.E()

		c_p = self.scaner.get_uk() #Запомнить текущую позицию
		_type = self.scaner.scan() #Получить текущую лексему
		while ( _type == PLUS or _type == MINUS ):
			self.E()
			c_p = self.scaner.get_uk() #Запомнить текущую позицию
			_type = self.scaner.scan() #Получить текущую лексему
		self.scaner.set_uk(c_p) #Вернуть старую позицию

	#Множитель
	def E(self):
		self.X()

		c_p = self.scaner.get_uk() #Запомнить текущую позицию
		_type = self.scaner.scan() #Получить текущую лексему
		while ( _type == DIV or _type == MOD or _type == MULT ):
			self.X()
			c_p = self.scaner.get_uk() #Запомнить текущую позицию
			_type = self.scaner.scan() #Получить текущую лексему
		self.scaner.set_uk(c_p) #Вернуть старую позицию

	#Элементарное выражение
	def X(self):
		_type = self.scaner.scan() #Получить текущую лексему

		if ( _type != ID and _type != LBRACKET and _type != CONSTCHAR and _type != CONSTSTRING and _type != CONSTINT ):
			self.scaner.printError("ERROR! Expected identifier, left bracket or constant char or string or int.")

		if ( _type == ID ):
			# Поиск имени идентификатора в таблице
			if (self.flagInterpret):
				v = self.__tree.semGetType(''.join(self.scaner.get_lex()))
				if ( type(v) == str ):
					self.scaner.printError(v)

			c_p = self.scaner.get_uk() #Запомнить текущую позицию
			_type = self.scaner.scan() #Получить текущую лексему
			if ( _type != LSBRACKET ):
				self.scaner.set_uk(c_p) #Вернуть старую позицию
			else:
				self.A()
				_type = self.scaner.scan() #Получить текущую лексему
				if ( _type != RSBRACKET ):
					self.scaner.printError("ERROR! Expected right square bracket.")

		elif ( _type == LBRACKET ):
			self.A()

			_type = self.scaner.scan() #Получить текущую лексему
			if ( _type != RBRACKET ):
				self.scaner.printError("ERROR! Expected right bracket.")
		elif ( _type == CONSTCHAR or _type == CONSTINT or _type == CONSTSTRING ):
			return

	def printTree(self):
		self.__tree.printTree()

	def getTree(self):
		return self.__tree