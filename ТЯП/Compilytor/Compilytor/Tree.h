#pragma once
#include "Scaner.h"
#include <iostream>
#define EMPTY -1

enum TypeObject {
	ObjTypeArray,
	ObjTypeVarChar,
	ObjTypeVarInt,
	ObjTypeVarDouble,
	ObjFunction,	// �������
	ObjVar,
	ObjWhile
};

struct Node		// ������� ������
{
	LEX id;						// ������������� �������
	TypeObject typeObject;		// ��� �������	
	char* Data;					// ������ �� �������� ��� NULL
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
	Tree(Node Data);
	~Tree();
	void SetLeft(Node* Data);
	void SetRight(Node* Data);
	Tree* FindUp(Tree* From, LEX id);
	Tree* FindUpOneLevel(Tree* From, LEX id);
	Tree* FindUp(LEX id);
	void Print(void);

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
};

