#pragma once
#include "Scaner.h"
#include "Diagram.h"
#include <iostream>

using namespace std;

// ��������
void Diagram::S() {
	LEX l;

	tree->sc = scaner;
	tree->SetCur(tree);

	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������

	if (_type != DOUBLE and _type != CHAR)
		scaner->PrintError("������! ��������� double ��� char.");
	scaner->SetUK(uk1);			// ������� ������ �������

	while (_type == DOUBLE or _type == CHAR)
	{
		T();
		uk1 = scaner->GetUK();
		_type = scaner->Scaner(l);
		scaner->SetUK(uk1);
	}
}

// ���� ��������
void Diagram::T() {
	LEX l;
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������
	scaner->SetUK(uk1);			// ������� ������ �������

	if (FOrW())
		F();
	else
		W();
}

// ������� ��� ������
bool Diagram::FOrW() {
	LEX l;
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������

	if (_type == DOUBLE or _type == CHAR)
	{
		_type = scaner->Scaner(l); // �������� ������� �������
		if (_type == MAIN)
			scaner->SetUK(uk1);
		else if (_type == ID)
		{
			_type = scaner->Scaner(l);
			if (_type == LBRACKET)
			{
				scaner->SetUK(uk1);
				return true;
			}
		}
	}
	scaner->SetUK(uk1);			// ������� ������ �������
	return false;
}

// ������
void Diagram::W() {
	LEX l;
	int _type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != DOUBLE && _type != CHAR)
		scaner->PrintError("������! �������� double ��� char");
	D();
	_type = scaner->Scaner(l);
	if (_type != SEMICOLON)
		scaner->PrintError("������! �������� ������ ';'");
}

// ������
void Diagram::D() {
	LEX l;
	Z();
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������

	while (_type == COMMA)
	{
		Z();
		uk1 = scaner->GetUK();
		_type = scaner->Scaner(l);
	}
	scaner->SetUK(uk1);			// ������� ������ �������
}

// ����������, ������
void Diagram::Z() {
	LEX l;
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������

	if (_type != ID)
		scaner->PrintError("������! �������� �������������.");

	_type = scaner->Scaner(l);	// �������� ������� �������
	scaner->SetUK(uk1);			// ������� ������ �������
	if (_type == LSBRACKET)
	{
		_type = scaner->Scaner(l);	// �������� ������� �������
		// ��������� �������������� ������� � ������� � ����� curType
		Tree* v = tree->SemInclude(l, ObjTypeArray);
	}
	else
	{
		_type = scaner->Scaner(l);	// �������� ������� �������
		// ��������� �������������� � ������� � ����� curType
		Tree* v = tree->SemInclude(l, ObjVar);
	}

	uk1 = scaner->GetUK();	// ��������� ������� �������
	_type = scaner->Scaner(l);	// �������� ������� �������
	if (_type == SAVE)
		A();
	else if (_type == LSBRACKET)
	{
		uk1 = scaner->GetUK();
		_type = scaner->Scaner(l);
		if (_type != RSBRACKET)
		{
			scaner->SetUK(uk1);
			A();
			// �������� ����������� �� ������
			uk1 = scaner->GetUK();
			_type = scaner->Scaner(l);
			if (_type != RSBRACKET)
				scaner->PrintError("������! ��������� ������ ���������� ������.");
			uk1 = scaner->GetUK();
			_type = scaner->Scaner(l);
			if (_type == SAVE)
				A();
			else scaner->SetUK(uk1);
		}
	}
	else scaner->SetUK(uk1);
}

// �������
void Diagram::F() {
	LEX l;
	int _type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != DOUBLE && _type != CHAR)
		scaner->PrintError("������! �������� double ��� char.");
	_type = scaner->Scaner(l);
	if (_type != ID && _type != MAIN)
		scaner->PrintError("������! �������� ������������� ��� main.");

	int uk1 = scaner->GetUK();
	// ��������� ��� ������� � �������
	Tree* v = tree->SemInclude(l, ObjFunction);

	_type = scaner->Scaner(l);
	if (_type != LBRACKET)
		scaner->PrintError("������! ��������� ����� ������� ������.");
	_type = scaner->Scaner(l);
	if (_type != RBRACKET)
		scaner->PrintError("������! ��������� ������� ������� ������.");

	Q();
}

// ��������� ��������
void Diagram::Q() {
	LEX l;
	int _type = scaner->Scaner(l);	// �������� ������� �������
	LEX l1 = "-";
	Tree* block = tree->SemInclude(l1, ObjFunction);
	if (_type != LBRACE)
		scaner->PrintError("������! ��������� ����� �������� ������.");
	O();
	_type = scaner->Scaner(l);
	if (_type != RBRACE)
		scaner->PrintError("������! ��������� ������ �������� ������.");
}

// ��������� � ��������
void Diagram::O() {
	LEX l;
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������
	scaner->SetUK(uk1);			// ������� ������ �������
	while (_type != RBRACE)
	{
		if (_type == DOUBLE || _type == CHAR)
			W();
		else K();
		uk1 = scaner->GetUK();	// ��������� ������� �������
		_type = scaner->Scaner(l);	// �������� ������� �������
		scaner->SetUK(uk1);			// ������� ������ �������
	}
}

// �������� � ����� �������
void Diagram::K() {
	LEX l;
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������
	if (_type == LBRACE)
	{
		scaner->SetUK(uk1);			// ������� ������ �������
		Q();
	}
	else if (_type == WHILE)
	{
		scaner->SetUK(uk1);			// ������� ������ �������
		H();
	}
	else if (_type == SEMICOLON) return; // ������ ��������
	else if (_type == ID)
	{
		// ����� ����� ������� � ���������� � �������
		Tree* v1 = tree->SemGetType(l);
		Tree* v = tree->SemGetFunct(l);


		_type = scaner->Scaner(l);	// �������� ������� �������
		if (_type == LBRACKET)
		{
			_type = scaner->Scaner(l);
			if (_type != RBRACKET)
				scaner->PrintError("������! ��������� ������ ������� ������.");
		}
		else if (_type == LSBRACKET)
		{
			A();
			_type = scaner->Scaner(l);
			if(_type != RSBRACKET)
				scaner->PrintError("������! ��������� ������ ���������� ������.");
			scaner->SetUK(uk1);			// ������� ������ �������
			U();
		}
		else
		{
			scaner->SetUK(uk1);			// ������� ������ �������
			U();
		}
	}
	else
	{
		scaner->SetUK(uk1);			// ������� ������ �������
		U();
	}

}

// while
void Diagram::H() {
	LEX l;
	int _type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != WHILE)
		scaner->PrintError("������! �������� while");
	_type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != LBRACKET)
		scaner->PrintError("������! ��������� ����� ������� ������");
	A();
	_type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != RBRACKET)
		scaner->PrintError("������! ��������� ������ ������� ������");
	K();
}

// ������������, �������� ������������ � ����������������� � �����������������
void Diagram::U() {
	LEX l;
	int uk1;
	int _type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != ID and _type != PLUSPLUS and _type != MINUSMINUS)
		scaner->PrintError("������! ��������� (�������������, ++ ��� --).");
	if (_type == ID)
	{
		// ����� ����� �������������� � �������
		Tree* v1 = tree->SemGetType(l);

		uk1 = scaner->GetUK();	// ��������� ������� �������
		_type = scaner->Scaner(l);	// �������� ������� �������
		if (_type == LSBRACKET)
		{
			A();
			_type = scaner->Scaner(l);	// �������� ������� �������
			if (_type == RSBRACKET)
				_type = scaner->Scaner(l);	// �������� ������� �������
		}
		else
		{
			scaner->SetUK(uk1);			// ������� ������ �������
			_type = scaner->Scaner(l);	// �������� ������� �������
		}

		if (_type != SAVE and _type != PLUSEQ and _type != MINUSEQ and _type != MULTEQ
			and _type != DIVEQ and _type != MODEQ and _type != PLUSPLUS and _type != MINUSMINUS)
			scaner->PrintError("������! ��������� (=, +=, -=, *=. %=, /=, ++ ��� --).");

		if (_type == SAVE or _type == PLUSEQ or _type == MINUSEQ or _type == MULTEQ
			or _type == DIVEQ or _type == MODEQ)
			A();
		else if (_type == PLUSPLUS or _type == MINUSMINUS)
			return;
	}
	else if (_type == PLUSPLUS or _type == MINUSMINUS)
	{
		_type = scaner->Scaner(l); // �������� ������� �������
		if (_type != ID) 
			scaner->PrintError("������! �������� �������������.");

		// ����� ����� �������������� � �������
		Tree* v1 = tree->SemGetType(l);
	}
}

// ���������
void Diagram::A() {
	LEX l;
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != PLUS and _type != MINUS)
		scaner->SetUK(uk1);  //������� ������ �������

	if (_type == PLUSPLUS or _type == MINUSMINUS)
	{
		uk1 = scaner->GetUK(); // ��������� ������� �������
		_type = scaner->Scaner(l); // �������� ������� �������
	}
	B();
	uk1 = scaner->GetUK(); // ��������� ������� �������
	_type = scaner->Scaner(l); // �������� ������� �������

	if (_type == PLUSPLUS or _type == MINUSMINUS)
		return;

	while (_type >= LT and _type <= NEQ)
	{
		B();
		uk1 = scaner->GetUK(); //��������� ������� �������
		_type = scaner->Scaner(l); //�������� ������� �������
	}
		
	scaner->SetUK(uk1);  // ������� ������ �������
}

// ���������
void Diagram::B() {
	E();
	LEX l;
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������
	while (_type == PLUS or _type == MINUS)
	{
		E();
		uk1 = scaner->GetUK(); // ��������� ������� �������
		_type = scaner->Scaner(l); // �������� ������� �������
	}
	scaner->SetUK(uk1);  // ������� ������ �������
}

// ���������
void Diagram::E() {
	X();
	LEX l;
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������
	while (_type == DIV or _type == MOD or _type == MULT)
	{
		X();
		uk1 = scaner->GetUK(); // ��������� ������� �������
		_type = scaner->Scaner(l); // �������� ������� �������
	}
	scaner->SetUK(uk1);  // ������� ������ �������
}

// ������������ ���������
void Diagram::X() {
	LEX l;
	int uk1;
	int _type = scaner->Scaner(l); // �������� ������� �������

	if (_type != ID and _type != LBRACKET and _type != CONSTCHAR and _type != CONSTSTRING and _type != CONSTINT)
		scaner->PrintError("������! �������� �������������, ����� ������ ��� ���������� char, string, int.");

	if (_type == ID)
	{
		// ����� ����� �������������� � �������
		Tree* v1 = tree->SemGetType(l);

		uk1 = scaner->GetUK(); // ��������� ������� �������
		_type = scaner->Scaner(l); // �������� ������� �������
		if (_type != LSBRACKET)
			scaner->SetUK(uk1);  // ������� ������ �������
		else
		{
			A();
			_type = scaner->Scaner(l); // �������� ������� �������
			if (_type != RSBRACKET)
				scaner->PrintError("������! ��������� ������ ���������� ������.");

		}
	}
	else if (_type == LBRACKET)
	{
		A();
		_type = scaner->Scaner(l); // �������� ������� �������
		if (_type != RBRACKET) 
			scaner->PrintError("������! ��������� ������ ������.");
	}
	else if (_type == CONSTCHAR or _type == CONSTINT or _type == CONSTSTRING)
		return;
}


void Diagram::printTree()
{
	tree->Print();
}