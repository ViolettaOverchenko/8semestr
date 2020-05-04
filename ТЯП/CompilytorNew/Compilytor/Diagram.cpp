#pragma once
#include "Scaner.h"
#include "Diagram.h"
#include <iostream>
void setValue(TData* data, TData* sdata, int exp);

using namespace std;

// ��������
void Diagram::S() {
	LEX l;

	tree->sc = scaner;
	tree->SetCur(tree);

	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������

	if (_type != DOUBLE and _type != CHAR)
		scaner->PrintError("������! ��������� double ��� char.", NULL);
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
		if (_type == MAIN) {
			scaner->SetUK(uk1);
			return true;
		}
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
		scaner->PrintError("������! �������� double ��� char", NULL);
	D((DataType)_type);
	_type = scaner->Scaner(l);
	if (_type != SEMICOLON)
		scaner->PrintError("������! �������� ������ ';'", NULL);
}

// ������
void Diagram::D(DataType type) {
	LEX l;
	Z(type);
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������

	while (_type == COMMA)
	{
		Z(type);
		uk1 = scaner->GetUK();
		_type = scaner->Scaner(l);
	}
	scaner->SetUK(uk1);			// ������� ������ �������
}

// ����������, ������
void Diagram::Z(DataType type) {
	LEX l, id; TData data;
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(id);	// �������� ������� �������

	if (_type != ID)
		scaner->PrintError("������! �������� �������������.", NULL);

	_type = scaner->Scaner(l);	// �������� ������� �������
	scaner->SetUK(uk1);			// ������� ������ �������
	if (_type == LSBRACKET)
	{
		_type = scaner->Scaner(l);	// �������� ������� �������
		// ��������� �������������� ������� � ������� � ����� curType
		Tree* v = NULL;
		if (flagInterpret) v = tree->SemInclude(id, ObjTypeArray);
		_type = scaner->Scaner(l);
		A(&data);
		if (flagInterpret) {
			v->GetNode()->Data.DataType = type;
			v->GetNode()->Data.DataValue.DataAsArray = new TDataValue[(int)data.DataValue.DataAsDouble];
			v->GetNode()->arrSize = (int)data.DataValue.DataAsDouble;
		}
		_type = scaner->Scaner(l);
		if (_type != RSBRACKET)
			scaner->PrintError("������! ��������� ������ ���������� ������.", NULL);
	}
	else
	{
		Tree* var = NULL;
		if (flagInterpret) {
			var = tree->SemInclude(id, ObjTypeVar);
			var->GetNode()->Data.DataType = type;
		}
		V(flagInterpret ? var : NULL, &data);
	}
}

void Diagram::Main() {
	LEX l; int t; LEX main = "main";
	if (flagInterpret) tree->SemInclude(main, ObjFunction);
	t = scaner->Scaner(l);
	if (t != LBRACKET) scaner->PrintError("�������� ������ '('", l);
	t = scaner->Scaner(l);
	if (t != RBRACKET) scaner->PrintError("�������� ������ ')'", l);
	Q();
}

// �������
void Diagram::F() {
	LEX l; int _type; Tree* func = NULL;
	int retType = _type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != DOUBLE && _type != CHAR)
		scaner->PrintError("������! �������� double ��� char.", NULL);
	_type = scaner->Scaner(l);

	if (_type == MAIN)
	{
		Main();
		return;
	}
	else if (_type != ID)
		scaner->PrintError("������! �������� ������������� ��� main.", NULL);

	if (flagInterpret) {
		func = tree->SemInclude(l, ObjFunction);
		switch (retType)
		{
		case DOUBLE:
			func->GetNode()->Data.DataType = _DOUBLE;
			break;
		case CHAR:
			func->GetNode()->Data.DataType = _CHAR;
			break;
		default:
			func->GetNode()->Data.DataType = _UNKNOWN;
			break;
		}
	}

	int uk1 = scaner->GetUK();
	// ��������� ��� ������� � �������

	_type = scaner->Scaner(l);
	if (_type != LBRACKET)
		scaner->PrintError("������! ��������� ����� ������� ������.", NULL);
	_type = scaner->Scaner(l);
	if (_type != RBRACKET)
		scaner->PrintError("������! ��������� ������� ������� ������.", NULL);
	if (flagInterpret) func->SetFuncStart(scaner->GetUK());
	bool flag = flagInterpret;

	flagInterpret = false;
	Q();
	flagInterpret = flag;

	if (flagInterpret) {
		tree->SetCur(func);
	}
}

// ��������� ��������
void Diagram::Q() {
	LEX l;
	int _type = scaner->Scaner(l);	// �������� ������� �������
	LEX a = "";
	Tree* block = NULL;
	if (flagInterpret) block = tree->SemInclude(a, ObjFunction);
	if (_type != LBRACE)
		scaner->PrintError("������! ��������� ����� �������� ������.", NULL);
	O();
	_type = scaner->Scaner(l);
	if (_type != RBRACE)
		scaner->PrintError("������! ��������� ������ �������� ������.", NULL);
	if (flagInterpret) tree->SetCur(block); // ������������ �������� ������� � ������
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
		else
			K();
		uk1 = scaner->GetUK();	// ��������� ������� �������
		_type = scaner->Scaner(l);	// �������� ������� �������
		scaner->SetUK(uk1);			// ������� ������ �������
	}
}

// �������� � ����� �������
void Diagram::K() {
	LEX l; TData data;
	int uk1 = scaner->GetUK();	// ��������� ������� �������
	int _type = scaner->Scaner(l);	// �������� ������� �������
	if (_type == LBRACE)
	{
		scaner->SetUK(uk1);			// ������� ������ �������
		Q();
		return;
	}
	else if (_type == WHILE)
	{
		scaner->SetUK(uk1);			// ������� ������ �������
		H();
		return;
	}
	else if (_type == RETURN)
	{
		scaner->SetUK(uk1);			// ������� ������ �������
		RET();
		return;
	}
	else if (_type == SEMICOLON) return; // ������ ��������
	else if (_type == ID)
	{
		_type = scaner->Scaner(l);	// �������� ������� �������
		if (_type == LBRACKET)
		{
			scaner->SetUK(uk1);
			FC(&data);
			return;
		}
		else if (_type == LSBRACKET)
		{
			A(&data);
			_type = scaner->Scaner(l);
			if (_type != RSBRACKET)
				scaner->PrintError("������! ��������� ������ ���������� ������.", NULL);
		}
	}
	scaner->SetUK(uk1);			// ������� ������ �������
	U();

}

// while
void Diagram::H() {
	LEX l; TData condition; LEX a = "";
	Tree* block = NULL;
	condition.DataValue.DataAsChar = false;
	if (flagInterpret) block = tree->SemInclude(a, ObjFunction);
	int _type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != WHILE)
		scaner->PrintError("������! �������� while", NULL);
	_type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != LBRACKET)
		scaner->PrintError("������! ��������� ����� ������� ������", NULL);
	int exp = scaner->GetUK();
	A(&condition);
	_type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != RBRACKET)
		scaner->PrintError("������! ��������� ������ ������� ������", NULL);
	int body = scaner->GetUK();
	bool flag = flagInterpret;
cycle:
	flagInterpret = condition.DataValue.DataAsChar != 0;
	K();

	if (flagInterpret) {
		scaner->SetUK(exp);
		A(&condition);
		scaner->SetUK(body);
		goto cycle;
	}
	else {
		flagInterpret = flag;
		if (!flagInterpret) return;
		tree->SetCur(block);
		block->DeleteChilds();
	}
}

// ������������, �������� ������������
void Diagram::U() {
	LEX l; TData data;
	int uk1;
	int _type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != ID)
		scaner->PrintError("������! �������� ��������������.", l);

	// ����� ����� �������������� � �������
	Tree* var = NULL;
	if (flagInterpret) var = tree->SemGetType(l);
	//if(ObjType!= ObjTypeArray && ObjType!=ObjTypeVar)
	int index;

	uk1 = scaner->GetUK();	// ��������� ������� �������
	_type = scaner->Scaner(l);	// �������� ������� �������
	if (_type == LSBRACKET)
	{
		TData value;
		A(&data);
		value.DataType = _DOUBLE;
		setValue(&value, &data, SAVE);
		index = value.DataValue.DataAsDouble;
		_type = scaner->Scaner(l);	// �������� ������� �������
		if (_type != RSBRACKET)
			scaner->PrintError("������! ��������� ������ ���������� ������!", NULL);
		if (flagInterpret) {
			if (var->GetNode()->typeObject != ObjTypeArray)
				scaner->PrintError("������! ����� ����� ��������� �� �������� ��������� �������!", NULL);
			if (!(0 <= index && index <= var->GetNode()->arrSize))
				scaner->PrintError("������! ������ �������� ������� ��� ���������!", NULL);
		}
	}
	else
	{
		if (flagInterpret && var->GetNode()->typeObject != ObjTypeVar)
			scaner->PrintError("������! ����� ����� ��������� �� �������� ����������!", NULL);
		scaner->SetUK(uk1);			// ������� ������ �������
		//_type = scaner->Scaner(l);	// �������� ������� �������
	}

	_type = scaner->Scaner(l);	// �������� ������� �������
	if (_type != SAVE and _type != PLUSEQ and _type != MINUSEQ and _type != MULTEQ
		and _type != DIVEQ and _type != MODEQ and _type != PLUSPLUS and _type != MINUSMINUS)
		scaner->PrintError("������! ��������� (=, +=, -=, *=. %=, /=).", NULL);
	else
	{
		A(&data);
		if (flagInterpret) {
			if (var->GetNode()->typeObject == ObjTypeArray) {
				TData setVal;
				setVal.DataType = var->GetNode()->Data.DataType;
				setVal.DataValue = var->GetNode()->Data.DataValue.DataAsArray[index];
				setValue(&setVal, &data, _type);
				var->GetNode()->Data.DataValue.DataAsArray[index] = setVal.DataValue;
				var->GetNode()->DisplayVar(index);
			}
			else
			{
				setValue(&var->GetNode()->Data, &data, _type);
				var->GetNode()->DisplayVar();
			}
		}
	}
}

// ���������
void Diagram::A(TData* data) {
	LEX l; int t, uk1; TData sdata;
	B(data);
	uk1 = scaner->GetUK();
	t = scaner->Scaner(l);

	while (LT <= t and t <= NEQ)
	{
		B(&sdata);

		if (flagInterpret) {
			switch (data->DataType) {
			case _DOUBLE:
				data->DataType = _CHAR;
				switch (sdata.DataType) {
				case _DOUBLE:
					switch (t)
					{
					case LT: data->DataValue.DataAsChar = data->DataValue.DataAsDouble < sdata.DataValue.DataAsDouble; break;
					case LE: data->DataValue.DataAsChar = data->DataValue.DataAsDouble <= sdata.DataValue.DataAsDouble; break;
					case GT: data->DataValue.DataAsChar = data->DataValue.DataAsDouble > sdata.DataValue.DataAsDouble; break;
					case GE: data->DataValue.DataAsChar = data->DataValue.DataAsDouble >= sdata.DataValue.DataAsDouble; break;
					case EQ: data->DataValue.DataAsChar = data->DataValue.DataAsDouble == sdata.DataValue.DataAsDouble; break;
					case NEQ: data->DataValue.DataAsChar = data->DataValue.DataAsDouble != sdata.DataValue.DataAsDouble; break;
					default: break;
					}
					break;
				case _CHAR:
					switch (t)
					{
					case LT: data->DataValue.DataAsChar = data->DataValue.DataAsDouble < sdata.DataValue.DataAsChar; break;
					case LE: data->DataValue.DataAsChar = data->DataValue.DataAsDouble <= sdata.DataValue.DataAsChar; break;
					case GT: data->DataValue.DataAsChar = data->DataValue.DataAsDouble > sdata.DataValue.DataAsChar; break;
					case GE: data->DataValue.DataAsChar = data->DataValue.DataAsDouble >= sdata.DataValue.DataAsChar; break;
					case EQ: data->DataValue.DataAsChar = data->DataValue.DataAsDouble == sdata.DataValue.DataAsChar; break;
					case NEQ: data->DataValue.DataAsChar = data->DataValue.DataAsDouble != sdata.DataValue.DataAsChar; break;
					default: break;
					}
				}
				break;
			case _CHAR:
				switch (sdata.DataType) {
				case _DOUBLE:
					switch (t)
					{
					case LT: data->DataValue.DataAsChar = data->DataValue.DataAsChar < sdata.DataValue.DataAsDouble; break;
					case LE: data->DataValue.DataAsChar = data->DataValue.DataAsChar <= sdata.DataValue.DataAsDouble; break;
					case GT: data->DataValue.DataAsChar = data->DataValue.DataAsChar > sdata.DataValue.DataAsDouble; break;
					case GE: data->DataValue.DataAsChar = data->DataValue.DataAsChar >= sdata.DataValue.DataAsDouble; break;
					case EQ: data->DataValue.DataAsChar = data->DataValue.DataAsChar == sdata.DataValue.DataAsDouble; break;
					case NEQ: data->DataValue.DataAsChar = data->DataValue.DataAsChar != sdata.DataValue.DataAsDouble; break;
					default: break;
					}
					break;
				case _CHAR:
					switch (t)
					{
					case LT: data->DataValue.DataAsChar = data->DataValue.DataAsChar < sdata.DataValue.DataAsChar; break;
					case LE: data->DataValue.DataAsChar = data->DataValue.DataAsChar <= sdata.DataValue.DataAsChar; break;
					case GT: data->DataValue.DataAsChar = data->DataValue.DataAsChar > sdata.DataValue.DataAsChar; break;
					case GE: data->DataValue.DataAsChar = data->DataValue.DataAsChar >= sdata.DataValue.DataAsChar; break;
					case EQ: data->DataValue.DataAsChar = data->DataValue.DataAsChar == sdata.DataValue.DataAsChar; break;
					case NEQ: data->DataValue.DataAsChar = data->DataValue.DataAsChar != sdata.DataValue.DataAsChar; break;
					default: break;
					}
					break;
				}
				break;
			}
		}
		uk1 = scaner->GetUK(); //��������� ������� �������
		t = scaner->Scaner(l); //�������� ������� �������
	}

	scaner->SetUK(uk1);  // ������� ������ �������
}

// ���������
void Diagram::B(TData* data) {
	LEX l; int t, uk1; TData sdata;
	E(data);
	uk1 = scaner->GetUK();	// ��������� ������� �������
	t = scaner->Scaner(l);	// �������� ������� �������
	while (t == PLUS or t == MINUS)
	{
		E(&sdata);

		if (flagInterpret) {
			switch (data->DataType) {
			case _DOUBLE:
				switch (sdata.DataType) {
				case _DOUBLE:
					if (t == PLUS)
						data->DataValue.DataAsDouble += sdata.DataValue.DataAsDouble;
					else
						data->DataValue.DataAsDouble -= sdata.DataValue.DataAsDouble;
					break;
				case _CHAR:
					if (t == PLUS)
						data->DataValue.DataAsDouble += sdata.DataValue.DataAsChar;
					else
						data->DataValue.DataAsDouble -= sdata.DataValue.DataAsChar;
					break;
				}
				break;
			case _CHAR:
				switch (sdata.DataType) {
				case _DOUBLE:
					data->DataType = _DOUBLE;
					if (t == PLUS)
						data->DataValue.DataAsDouble = data->DataValue.DataAsChar + sdata.DataValue.DataAsDouble;
					else
						data->DataValue.DataAsDouble = data->DataValue.DataAsChar - sdata.DataValue.DataAsDouble;
					break;
				case _CHAR:
					if (t == PLUS)
						data->DataValue.DataAsChar += sdata.DataValue.DataAsChar;
					else
						data->DataValue.DataAsChar -= sdata.DataValue.DataAsChar;
					break;
				}
				break;
			}
		}
		uk1 = scaner->GetUK(); // ��������� ������� �������
		t = scaner->Scaner(l); // �������� ������� �������
	}
	scaner->SetUK(uk1);  // ������� ������ �������
}

// ���������
void Diagram::E(TData* data) {
	LEX l; int t, uk1;
	P(data);
	TData sdata;
	uk1 = scaner->GetUK();	// ��������� ������� �������
	t = scaner->Scaner(l);	// �������� ������� �������
	while (t == DIV or t == MULT)
	{
		P(&sdata);
		if (flagInterpret) {
			switch (data->DataType) {
			case _DOUBLE:
				switch (sdata.DataType) {
				case _DOUBLE:
					if (t == MULT)
						data->DataValue.DataAsDouble *= sdata.DataValue.DataAsDouble;
					else
						data->DataValue.DataAsDouble /= sdata.DataValue.DataAsDouble;
					break;
				case _CHAR:
					if (t == MULT)
						data->DataValue.DataAsDouble *= sdata.DataValue.DataAsChar;
					else
						data->DataValue.DataAsDouble /= sdata.DataValue.DataAsChar;
					break;
				}
				break;
			case _CHAR:
				switch (sdata.DataType) {
				case _DOUBLE:
					data->DataType = _DOUBLE;
					if (t == MULT)
						data->DataValue.DataAsDouble = data->DataValue.DataAsChar * sdata.DataValue.DataAsDouble;
					else
						data->DataValue.DataAsDouble = data->DataValue.DataAsChar * sdata.DataValue.DataAsDouble;
					break;
				case _CHAR:
					if (t == MULT)
						data->DataValue.DataAsChar *= sdata.DataValue.DataAsChar;
					else
						data->DataValue.DataAsChar /= sdata.DataValue.DataAsChar;
					break;
				}
				break;
			}
		}
		uk1 = scaner->GetUK(); // ��������� ������� �������
		t = scaner->Scaner(l); // �������� ������� �������
	}
	scaner->SetUK(uk1);  // ������� ������ �������
}

void Diagram::P(TData* data) {
	LEX l; int t, uk1;
	uk1 = scaner->GetUK(); t = scaner->Scaner(l);
	if (t != PLUS && t != MINUS) scaner->SetUK(uk1);
	X(data);

	if (flagInterpret) {
		switch (t)
		{
		case MINUS:
			switch (data->DataType) {
			case _CHAR: data->DataValue.DataAsChar *= -1; break;
			case _DOUBLE: data->DataValue.DataAsDouble *= -1; break;
			}
		}
	}
}

// ������������ ���������
void Diagram::X(TData* data) {
	LEX l, l1;
	int uk1 = scaner->GetUK(); // ��������� ������� �������
	int _type = scaner->Scaner(l1); // �������� ������� �������

	if (_type == ID)
	{
		_type = scaner->Scaner(l); // �������� ������� �������
		scaner->SetUK(uk1); // ������� ������ �������
		if (_type == LBRACKET)
			FC(data);
		else
			V(flagInterpret ? tree->SemGetType(l1) : NULL, data);
	}
	else if (_type == LBRACKET)
	{
		A(data);
		_type = scaner->Scaner(l); // �������� ������� �������
		if (_type != RBRACKET)
			scaner->PrintError("������! ��������� ������ ������.", NULL);
	}
	else if (_type == CONSTINT)
	{
		if (!flagInterpret) return;
		double val = atof(l1);
		data->DataType = _DOUBLE;
		data->DataValue.DataAsDouble = val;
	}
	else if (_type == CONSTCHAR)
	{
		if (!flagInterpret) return;
		char val;
		if (l1[0] == '\\') {
			switch (l1[1]) {
			case 'n': val = '\n'; break;
			case 't': val = '\t'; break;
			case '\\': val = '\\'; break;
			case '\'': val = '\''; break;
			default: val = l1[1];
			}
		}
		else val = l1[0];
		data->DataType = _CHAR;
		data->DataValue.DataAsChar = val;
	}
	else if (_type != CONSTSTRING)
		scaner->PrintError("�������� ������������ ���������!", l1);
}

void Diagram::FC(TData* data)
{
	LEX l;
	int _type = scaner->Scaner(l);
	if (_type != ID)
		scaner->PrintError("������! �������� ��������������.", NULL);

	Tree* func = NULL;
	if (flagInterpret) func = tree->SemGetFunct(l);

	_type = scaner->Scaner(l);
	if (_type != LBRACKET)
		scaner->PrintError("������! ��������� ����� ������� ������.", NULL);
	_type = scaner->Scaner(l);
	if (_type != RBRACKET)
		scaner->PrintError("������! ��������� ������ ������� ������.", NULL);

	if (flagInterpret) {
		TData ret = CallFunc(func);
		data->DataType = ret.DataType;
		data->DataValue = ret.DataValue;
	}
}

TData Diagram::CallFunc(Tree* func) {
	int uk = scaner->GetUK();
	scaner->SetUK(func->GetFuncStart());
	Tree* cur = tree->Cur;
	func->CopyFunc();
	bool flag = flagInterpret;
	RetValue.DataType = func->GetNode()->Data.DataType;
	Q();
	flagInterpret = flag;
	tree->SetCur(cur);
	func->RemoveCopyiedFunc();
	scaner->SetUK(uk);
	return RetValue;
}

void setValue(TData* data, TData* sdata, int exp) {
	switch (data->DataType) {
	case _DOUBLE:
		switch (sdata->DataType) {
		case _DOUBLE:
			switch (exp)
			{
			case SAVE: data->DataValue.DataAsDouble = sdata->DataValue.DataAsDouble; break;
			case PLUSEQ: data->DataValue.DataAsDouble += sdata->DataValue.DataAsDouble; break;
			case MINUSEQ: data->DataValue.DataAsDouble -= sdata->DataValue.DataAsDouble; break;
			case DIVEQ: data->DataValue.DataAsDouble /= sdata->DataValue.DataAsDouble; break;
			case MULTEQ: data->DataValue.DataAsDouble *= sdata->DataValue.DataAsDouble; break;
			default: break;
			}

			break;
		case _CHAR:
			switch (exp)
			{
			case SAVE: data->DataValue.DataAsDouble = sdata->DataValue.DataAsChar; break;
			case PLUSEQ: data->DataValue.DataAsDouble += sdata->DataValue.DataAsChar; break;
			case MINUSEQ: data->DataValue.DataAsDouble -= sdata->DataValue.DataAsChar; break;
			case DIVEQ: data->DataValue.DataAsDouble /= sdata->DataValue.DataAsChar; break;
			case MULTEQ: data->DataValue.DataAsDouble *= sdata->DataValue.DataAsChar; break;
			default: break;
			}

			break;
		}
		break;
	case _CHAR:
		switch (sdata->DataType) {
		case _DOUBLE:
			switch (exp)
			{
			case SAVE: data->DataValue.DataAsChar = sdata->DataValue.DataAsDouble; break;
			case PLUSEQ: data->DataValue.DataAsChar += sdata->DataValue.DataAsDouble; break;
			case MINUSEQ: data->DataValue.DataAsChar -= sdata->DataValue.DataAsDouble; break;
			case DIVEQ: data->DataValue.DataAsChar /= sdata->DataValue.DataAsDouble; break;
			case MULTEQ: data->DataValue.DataAsChar *= sdata->DataValue.DataAsDouble; break;
			default: break;
			}

			break;
		case _CHAR:
			switch (exp)
			{
			case SAVE: data->DataValue.DataAsChar = sdata->DataValue.DataAsChar; break;
			case PLUSEQ: data->DataValue.DataAsChar += sdata->DataValue.DataAsChar; break;
			case MINUSEQ: data->DataValue.DataAsChar -= sdata->DataValue.DataAsChar; break;
			case DIVEQ: data->DataValue.DataAsChar /= sdata->DataValue.DataAsChar; break;
			case MULTEQ: data->DataValue.DataAsChar *= sdata->DataValue.DataAsChar; break;
			default: break;
			}

			break;
		}
		break;
	}
}

void Diagram::V(Tree* var, TData* data) {
	LEX l; int t, uk1;
	t = scaner->Scaner(l);
	if (t != ID) scaner->PrintError("�������� ��������������!", l);
	uk1 = scaner->GetUK(); int exp = t = scaner->Scaner(l);
	if (t == SAVE || t == PLUSEQ || t == MINUSEQ || t == DIVEQ || t == MULTEQ) {
		uk1 = scaner->GetUK(); t = scaner->Scaner(l);
		if (t == PLUS || t == MINUS || t == ID || t == CONSTCHAR || t == CONSTINT || t == CONSTSTRING) {
			scaner->SetUK(uk1);
			A(data);

			if (flagInterpret) {
				setValue(&var->GetNode()->Data, data, exp);
				var->GetNode()->DisplayVar();
			}
		}
		else scaner->PrintError("����� ����� '=' ��������� ���������!", l);
	}
	else if (t == LSBRACKET)
	{
		TData data1; TData value;
		A(&data1);
		value.DataType = _DOUBLE;
		setValue(&value, &data1, SAVE);
		int index = value.DataValue.DataAsDouble;

		t = scaner->Scaner(l);
		if (t != RSBRACKET) scaner->PrintError("��������� ���������� ������!", l);
		if (var->GetNode()->typeObject != ObjTypeArray)
			scaner->PrintError("������ ���������� �� �������� ��������!", var->GetNode()->id);
		if (!(0 <= index && index <= var->GetNode()->arrSize))
			scaner->PrintError("������! ������ �������� ������� ��� ���������!", NULL);
		exp = t = scaner->Scaner(l);
		if (t == SAVE || t == PLUSEQ || t == MINUSEQ || t == DIVEQ || t == MULTEQ)
		{
			A(data);
			if (flagInterpret)
			{
				TData setVal;
				setVal.DataType = var->GetNode()->Data.DataType;
				setValue(&setVal, data, exp);
				var->GetNode()->Data.DataValue.DataAsArray[index] = setVal.DataValue;
				var->GetNode()->DisplayVar(index);
			}
		}
		else
		{
			scaner->SetUK(uk1);
			if (flagInterpret)
			{
				data->DataType = var->GetNode()->Data.DataType;
				data->DataValue = var->GetNode()->Data.DataValue.DataAsArray[index];
			}
		}
	}
	else {
		scaner->SetUK(uk1);
		if (flagInterpret)
		{
			data->DataType = var->GetNode()->Data.DataType;
			data->DataValue = var->GetNode()->Data.DataValue;
		}
	}
}

void Diagram::RET() {
	LEX l; int t;
	t = scaner->Scaner(l);
	if (t != RETURN) scaner->PrintError("��������� �������� ����� return!", l);
	TData Value;
	A(&Value);
	setValue(&RetValue, &Value, SAVE);
	t = scaner->Scaner(l);
	if (t != SEMICOLON) scaner->PrintError("�������� ������ ';'!", l);
	flagInterpret = false;
}

void Diagram::printTree()
{
	tree->Print(0);
}