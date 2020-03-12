#pragma once
#include "Scaner.h"
#include <iostream>
#define EMPTY -1

enum TypeObject {
	ObjTypeArray,
	ObjTypeVarChar,
	ObjTypeVarInt,
	ObjTypeVarDouble,
	ObjFunction,	// функция
	ObjVar,
	ObjWhile
};

struct Node		// Вершина дерева
{
	LEX id;						// идентификатор объекта
	TypeObject typeObject;		// тип объекта	
	char* Data;					// ссылка на значение или NULL
};

/*
enum DataType {
	UNKNOWN,
	CHAR_,
	DOUBLE_
};
/*
union TDataValue {
	double DataAsDouble;
	char DataAsChar;
};

struct TData {
	DataType		DataType = DOUBLE;
	TDataValue 		DataValue;
};*/

class Tree
{
	Node* n;	// данные таблицы (дерева)
	Tree* Up, * Left, * Right;
public:
	static Tree* Cur; // текущий элемент дерева
	static TScaner* sc;
	Node* GetNode();
	void SetNode(Node* n);
	// ФУНКЦИИ ОБРАБОТКИ БИНАРНОГО ДЕРЕВА
	Tree(Tree* l, Tree* r, Tree* u, Node* Data);
	Tree();
	Tree(Node Data);
	~Tree();
	void SetLeft(Node* Data);
	void SetRight(Node* Data);
	Tree* FindUp(Tree* From, LEX id);
	Tree* FindUpOneLevel(Tree* From, LEX id);
	Tree* FindUp(LEX id);
	void Print(void);

	// СЕМАНТИЧЕСКИЕ ПОДПРОГРАММЫ
	// установить текущий узел дерева
	void SetCur(Tree* a);

	// получить значение текущего узла дерева
	Tree* GetCur(void);

	// занесение идентификатора a в таблицу с типом t
	Tree* SemInclude(LEX a, TypeObject t);

	// установить тип t для переменной по адресу Addr
	void SemSetType(Tree* Addr, TypeObject t);

	// найти в таблице переменную с именем a
	// и вернуть ссылку на соответствующий элемент дерева
	Tree* SemGetType(LEX a);

	// найти в таблице функцию с именем a
	// и вернуть ссылку на соответствующий элемент дерева
	Tree* SemGetFunct(LEX a);

	// проверка идентификатора а на повторное описание внутри блока
	int DupControl(Tree* Addr, LEX a);
};

