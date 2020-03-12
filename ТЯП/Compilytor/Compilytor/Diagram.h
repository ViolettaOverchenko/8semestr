#pragma once
#include "Scaner.h"
#include "Tree.h"
class Diagram
{
private:
	TScaner *scaner;
	Tree* tree = new Tree();
	//static string TypesStrings[2];

public:
	Diagram(TScaner* s) { scaner = s; }
	~Diagram() {}

	void S(); // описания
	void T(); // одно описание
	bool FOrW();	// функция или данные
	void W();	// данные
	void F();	// функция
	void D();	// список
	void Z();	// переменая, массив
	void A();	// выражение
	void Q();	// составной оператор
	void O();	// операторы и описания
	void K();	// оператор и вызов функции
	void H();	// while
	void U();	// 
	void B();	// слагаемое
	void E();	// множитель
	void X();	// элементарное выражение
	void printTree();

};


