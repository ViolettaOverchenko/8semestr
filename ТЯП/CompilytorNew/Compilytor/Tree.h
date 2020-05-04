#pragma once
#include "Scaner.h"
#include <iostream>
#define EMPTY -1

using namespace std;
enum TypeObject {
	ObjTypeUnknown = 1,
	ObjTypeArray,
	ObjTypeVar,
	ObjFunction,	// функция
};

enum DataType {
	_UNKNOWN,
	_DOUBLE,
	_CHAR
};

union TDataValue {
	char DataAsChar;
	double DataAsDouble;
	TDataValue* DataAsArray;
};

struct TData {
	DataType	DataType = _CHAR;
	TDataValue 	DataValue;
};

struct Node // информация в вершине дерева
{
	LEX id;							// индентефикатор объекта
	TypeObject typeObject;			// тип объекта
	TData Data;						// значение
	bool flagInit;					// признак инициализации
	int funcStart;					// начало функции
	int arrSize;					// размер массива

	void DisplayVar() {
		switch (Data.DataType) {
		case _CHAR:cout << id << " = " << Data.DataValue.DataAsChar << endl; break;
		case _DOUBLE:cout << id << " = " << Data.DataValue.DataAsDouble << endl; break;
		}
	}

	void DisplayVar(int index) {
		switch (Data.DataType) {
		case _CHAR:cout << id << "[" << index << "] = " << Data.DataValue.DataAsArray[index].DataAsChar << endl; break;
		case _DOUBLE:cout << id << "[" << index << "] = " << Data.DataValue.DataAsArray[index].DataAsDouble << endl; break;
		}
	}
	Node() {

	}

	Node(LEX id, TData data) {
		memcpy(this->id, id, strlen(id) + 1);
		this->Data = data;
	}
};

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
	Tree(Node* Data);
	~Tree();
	void SetLeft(Node* Data);
	void SetRight(Node* Data);
	Tree* FindUp(Tree* From, LEX id);
	Tree* FindUp(LEX id);
	Tree* FindUpOneLevel(Tree* From, LEX id);
	void Print(int k);

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
	Tree* GetChild(Tree* Addr);
	Tree* GetBrother(Tree* Addr);
	Tree* GetChild();
	Tree* GetBrother();
	void SetChild(Tree* tree);
	void SetBrother(Tree* tree);
	void SetBrotherUp(Tree* tree);
	Tree* GetBrotherUp();
	void SetFuncStart(int start);
	int GetFuncStart();
	void DeleteSubTree(Tree* tree);
	void DeleteChilds();
	Tree* CopyFunc();
	void RemoveCopyiedFunc();
	Tree(Node Data);
};

