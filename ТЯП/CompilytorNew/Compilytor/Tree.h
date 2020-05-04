#pragma once
#include "Scaner.h"
#include <iostream>
#define EMPTY -1

using namespace std;
enum TypeObject {
	ObjTypeUnknown = 1,
	ObjTypeArray,
	ObjTypeVar,
	ObjFunction,	// �������
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

struct Node // ���������� � ������� ������
{
	LEX id;							// �������������� �������
	TypeObject typeObject;			// ��� �������
	TData Data;						// ��������
	bool flagInit;					// ������� �������������
	int funcStart;					// ������ �������
	int arrSize;					// ������ �������

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
	Node* n;	// ������ ������� (������)
	Tree* Up, * Left, * Right;
public:
	static Tree* Cur; // ������� ������� ������
	static TScaner* sc;
	Node* GetNode();
	void SetNode(Node* n);
	// ������� ��������� ��������� ������
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

	// ������������� ������������
	// ���������� ������� ���� ������
	void SetCur(Tree* a);

	// �������� �������� �������� ���� ������
	Tree* GetCur(void);

	// ��������� �������������� a � ������� � ����� t
	Tree* SemInclude(LEX a, TypeObject t);

	// ���������� ��� t ��� ���������� �� ������ Addr
	void SemSetType(Tree* Addr, TypeObject t);

	// ����� � ������� ���������� � ������ a
	// � ������� ������ �� ��������������� ������� ������
	Tree* SemGetType(LEX a);

	// ����� � ������� ������� � ������ a
	// � ������� ������ �� ��������������� ������� ������
	Tree* SemGetFunct(LEX a);

	// �������� �������������� � �� ��������� �������� ������ �����
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

