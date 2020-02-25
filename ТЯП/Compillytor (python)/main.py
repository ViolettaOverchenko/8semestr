from defs import *
from scaner import Scaner
from diagram import Diagram

def main():
	_type = '' #Тип лексемы

	#Ввод файла в программу1
	original_file = open('input.txt')
	text = original_file.read(MAX_TEXT)
	text = text + '\0' #добавим концевой ноль в конец исходного файла
	#print(text)
	original_file.close()

	scaner = Scaner(text) #Инициализация сканера

	'''print ("\nScaner: ")
	#Вывод всех лексем (реализация сканера)
	while _type != END:
		_type = scaner.scan()
		print(_type, '-->', ''.join(scaner.get_lex()))'''
	
	# Синтаксический анализатор
	dg = Diagram(text)
	dg.setFlagInterpret()
	dg.S()

	print('\nTree: ')
	dg.printTree()

if __name__ == "__main__":
	main()
