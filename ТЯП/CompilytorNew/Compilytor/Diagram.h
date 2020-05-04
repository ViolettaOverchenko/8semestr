#pragma once
#include "Scaner.h"
#include "Tree.h"
class Diagram
{
private:
	TScaner* scaner;
	Tree* tree = new Tree();
	bool flagInterpret = true;
	TData RetValue;
public:
	Diagram(TScaner* s) { scaner = s; }
	~Diagram() {}
	void SetInterpret(bool flag) { this->flagInterpret = flag; }
	bool GetInterpret() { return flagInterpret; }
	void S(); // описания
	void T(); // одно описание
	bool FOrW();	// функция или данные
	void W();	// данные
	void F();	// функция
	void Main();	// главная функция
	void D(DataType type);	// список
	void Z(DataType type);	// переменая, массив
	void A(TData* data);	// выражение
	void Q();	// составной оператор
	void O();	// операторы и описания
	void K();	// оператор и вызов функции
	void H();	// while
	void U();	// 
	void B(TData* data);	// слагаемое
	void P(TData* data);
	void E(TData* data);	// множитель
	void X(TData* data);	// элементарное выражение
	void FC(TData* data);	// вызов функции
	TData CallFunc(Tree* func);		// вызов функции 2
	void V(Tree* var, TData* data); //переменная, элемент массива
	void RET();
	void printTree();
};


