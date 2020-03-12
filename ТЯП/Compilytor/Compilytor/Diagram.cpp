#pragma once
#include "Scaner.h"
#include "Diagram.h"
#include <iostream>

using namespace std;

// Описания
void Diagram::S() {
	LEX l;

	tree->sc = scaner;
	tree->SetCur(tree);

	int uk1 = scaner->GetUK();	// Запомнить текущую лексему
	int _type = scaner->Scaner(l);	// Получить текущую лексему

	if (_type != DOUBLE and _type != CHAR)
		scaner->PrintError("Ошибка! Ожидались double или char.");
	scaner->SetUK(uk1);			// Вернуть старую позицию

	while (_type == DOUBLE or _type == CHAR)
	{
		T();
		uk1 = scaner->GetUK();
		_type = scaner->Scaner(l);
		scaner->SetUK(uk1);
	}
}

// одно описание
void Diagram::T() {
	LEX l;
	int uk1 = scaner->GetUK();	// Запомнить текущую лексему
	int _type = scaner->Scaner(l);	// Получить текущую лексему
	scaner->SetUK(uk1);			// Вернуть старую позицию

	if (FOrW())
		F();
	else
		W();
}

// функция или данные
bool Diagram::FOrW() {
	LEX l;
	int uk1 = scaner->GetUK();	// Запомнить текущую лексему
	int _type = scaner->Scaner(l);	// Получить текущую лексему

	if (_type == DOUBLE or _type == CHAR)
	{
		_type = scaner->Scaner(l); // Получить текущую лексему
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
	scaner->SetUK(uk1);			// Вернуть старую позицию
	return false;
}

// Данные
void Diagram::W() {
	LEX l;
	int _type = scaner->Scaner(l);	// Получить текущую лексему
	if (_type != DOUBLE && _type != CHAR)
		scaner->PrintError("Ошибка! Ожидался double или char");
	D();
	_type = scaner->Scaner(l);
	if (_type != SEMICOLON)
		scaner->PrintError("Ошибка! Ожидался символ ';'");
}

// Список
void Diagram::D() {
	LEX l;
	Z();
	int uk1 = scaner->GetUK();	// Запомнить текущую лексему
	int _type = scaner->Scaner(l);	// Получить текущую лексему

	while (_type == COMMA)
	{
		Z();
		uk1 = scaner->GetUK();
		_type = scaner->Scaner(l);
	}
	scaner->SetUK(uk1);			// Вернуть старую позицию
}

// Переменная, массив
void Diagram::Z() {
	LEX l;
	int uk1 = scaner->GetUK();	// Запомнить текущую лексему
	int _type = scaner->Scaner(l);	// Получить текущую лексему

	if (_type != ID)
		scaner->PrintError("Ошибка! Ожидался идентификатор.");

	_type = scaner->Scaner(l);	// Получить текущую лексему
	scaner->SetUK(uk1);			// Вернуть старую позицию
	if (_type == LSBRACKET)
	{
		_type = scaner->Scaner(l);	// Получить текущую лексему
		// Занесение идентификатора массива в таблицу с типом curType
		Tree* v = tree->SemInclude(l, ObjTypeArray);
	}
	else
	{
		_type = scaner->Scaner(l);	// Получить текущую лексему
		// Занесение идентификатора в таблицу с типом curType
		Tree* v = tree->SemInclude(l, ObjVar);
	}

	uk1 = scaner->GetUK();	// Запомнить текущую лексему
	_type = scaner->Scaner(l);	// Получить текущую лексему
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
			// Проверим закрывается ли скобка
			uk1 = scaner->GetUK();
			_type = scaner->Scaner(l);
			if (_type != RSBRACKET)
				scaner->PrintError("Ошибка! Ожидалась правая квадратная скобка.");
			uk1 = scaner->GetUK();
			_type = scaner->Scaner(l);
			if (_type == SAVE)
				A();
			else scaner->SetUK(uk1);
		}
	}
	else scaner->SetUK(uk1);
}

// Функция
void Diagram::F() {
	LEX l;
	int _type = scaner->Scaner(l);	// Получить текущую лексему
	if (_type != DOUBLE && _type != CHAR)
		scaner->PrintError("Ошибка! Ожидался double или char.");
	_type = scaner->Scaner(l);
	if (_type != ID && _type != MAIN)
		scaner->PrintError("Ошибка! Ожидался идентификатор или main.");

	int uk1 = scaner->GetUK();
	// Занесение имя функции в таблицу
	Tree* v = tree->SemInclude(l, ObjFunction);

	_type = scaner->Scaner(l);
	if (_type != LBRACKET)
		scaner->PrintError("Ошибка! Ожидалась левая круглая скобка.");
	_type = scaner->Scaner(l);
	if (_type != RBRACKET)
		scaner->PrintError("Ошибка! Ожидалась Пправая круглая скобка.");

	Q();
}

// Составной оператор
void Diagram::Q() {
	LEX l;
	int _type = scaner->Scaner(l);	// Получить текущую лексему
	LEX l1 = "-";
	Tree* block = tree->SemInclude(l1, ObjFunction);
	if (_type != LBRACE)
		scaner->PrintError("Ошибка! Ожидалась левая фигурная скобка.");
	O();
	_type = scaner->Scaner(l);
	if (_type != RBRACE)
		scaner->PrintError("Ошибка! Ожидалась правая фигурная скобка.");
}

// Операторы и описания
void Diagram::O() {
	LEX l;
	int uk1 = scaner->GetUK();	// Запомнить текущую позицию
	int _type = scaner->Scaner(l);	// Получить текущую лексему
	scaner->SetUK(uk1);			// Вернуть старую позицию
	while (_type != RBRACE)
	{
		if (_type == DOUBLE || _type == CHAR)
			W();
		else K();
		uk1 = scaner->GetUK();	// Запомнить текущую позицию
		_type = scaner->Scaner(l);	// Получить текущую лексему
		scaner->SetUK(uk1);			// Вернуть старую позицию
	}
}

// Оператор и вызов функции
void Diagram::K() {
	LEX l;
	int uk1 = scaner->GetUK();	// Запомнить текущую позицию
	int _type = scaner->Scaner(l);	// Получить текущую лексему
	if (_type == LBRACE)
	{
		scaner->SetUK(uk1);			// Вернуть старую позицию
		Q();
	}
	else if (_type == WHILE)
	{
		scaner->SetUK(uk1);			// Вернуть старую позицию
		H();
	}
	else if (_type == SEMICOLON) return; // пустой оператор
	else if (_type == ID)
	{
		// Поиск имени функции и переменной в таблице
		Tree* v1 = tree->SemGetType(l);
		Tree* v = tree->SemGetFunct(l);


		_type = scaner->Scaner(l);	// Получить текущую лексему
		if (_type == LBRACKET)
		{
			_type = scaner->Scaner(l);
			if (_type != RBRACKET)
				scaner->PrintError("Ошибка! Ожидалась правая круглая скобка.");
		}
		else if (_type == LSBRACKET)
		{
			A();
			_type = scaner->Scaner(l);
			if(_type != RSBRACKET)
				scaner->PrintError("Ошибка! Ожидалась правая квадратная скобка.");
			scaner->SetUK(uk1);			// Вернуть старую позицию
			U();
		}
		else
		{
			scaner->SetUK(uk1);			// Вернуть старую позицию
			U();
		}
	}
	else
	{
		scaner->SetUK(uk1);			// Вернуть старую позицию
		U();
	}

}

// while
void Diagram::H() {
	LEX l;
	int _type = scaner->Scaner(l);	// Получить текущую лексему
	if (_type != WHILE)
		scaner->PrintError("Ошибка! Ожидался while");
	_type = scaner->Scaner(l);	// Получить текущую лексему
	if (_type != LBRACKET)
		scaner->PrintError("Ошибка! Ожидалась левая круглая скобка");
	A();
	_type = scaner->Scaner(l);	// Получить текущую лексему
	if (_type != RBRACKET)
		scaner->PrintError("Ошибка! Ожидалась правая круглая скобка");
	K();
}

// Присваивание, бинарное присваивание и инкрементирование и декрементирование
void Diagram::U() {
	LEX l;
	int uk1;
	int _type = scaner->Scaner(l);	// Получить текущую лексему
	if (_type != ID and _type != PLUSPLUS and _type != MINUSMINUS)
		scaner->PrintError("Ошибка! Ожидались (идентификатор, ++ или --).");
	if (_type == ID)
	{
		// Поиск имени идентификатора в таблице
		Tree* v1 = tree->SemGetType(l);

		uk1 = scaner->GetUK();	// Запомнить текущую позицию
		_type = scaner->Scaner(l);	// Получить текущую лексему
		if (_type == LSBRACKET)
		{
			A();
			_type = scaner->Scaner(l);	// Получить текущую лексему
			if (_type == RSBRACKET)
				_type = scaner->Scaner(l);	// Получить текущую лексему
		}
		else
		{
			scaner->SetUK(uk1);			// Вернуть старую позицию
			_type = scaner->Scaner(l);	// Получить текущую лексему
		}

		if (_type != SAVE and _type != PLUSEQ and _type != MINUSEQ and _type != MULTEQ
			and _type != DIVEQ and _type != MODEQ and _type != PLUSPLUS and _type != MINUSMINUS)
			scaner->PrintError("Ошибка! Ожидалось (=, +=, -=, *=. %=, /=, ++ или --).");

		if (_type == SAVE or _type == PLUSEQ or _type == MINUSEQ or _type == MULTEQ
			or _type == DIVEQ or _type == MODEQ)
			A();
		else if (_type == PLUSPLUS or _type == MINUSMINUS)
			return;
	}
	else if (_type == PLUSPLUS or _type == MINUSMINUS)
	{
		_type = scaner->Scaner(l); // Получить текущую лексему
		if (_type != ID) 
			scaner->PrintError("Ошибка! Ожидался идентификатор.");

		// Поиск имени идентификатора в таблице
		Tree* v1 = tree->SemGetType(l);
	}
}

// Выражение
void Diagram::A() {
	LEX l;
	int uk1 = scaner->GetUK();	// Запомнить текущую позицию
	int _type = scaner->Scaner(l);	// Получить текущую лексему
	if (_type != PLUS and _type != MINUS)
		scaner->SetUK(uk1);  //Вернуть старую позицию

	if (_type == PLUSPLUS or _type == MINUSMINUS)
	{
		uk1 = scaner->GetUK(); // Запомнить текущую позицию
		_type = scaner->Scaner(l); // Получить текущую лексему
	}
	B();
	uk1 = scaner->GetUK(); // Запомнить текущую позицию
	_type = scaner->Scaner(l); // Получить текущую лексему

	if (_type == PLUSPLUS or _type == MINUSMINUS)
		return;

	while (_type >= LT and _type <= NEQ)
	{
		B();
		uk1 = scaner->GetUK(); //Запомнить текущую позицию
		_type = scaner->Scaner(l); //Получить текущую лексему
	}
		
	scaner->SetUK(uk1);  // Вернуть старую позицию
}

// Слагаемое
void Diagram::B() {
	E();
	LEX l;
	int uk1 = scaner->GetUK();	// Запомнить текущую позицию
	int _type = scaner->Scaner(l);	// Получить текущую лексему
	while (_type == PLUS or _type == MINUS)
	{
		E();
		uk1 = scaner->GetUK(); // Запомнить текущую позицию
		_type = scaner->Scaner(l); // Получить текущую лексему
	}
	scaner->SetUK(uk1);  // Вернуть старую позицию
}

// Множитель
void Diagram::E() {
	X();
	LEX l;
	int uk1 = scaner->GetUK();	// Запомнить текущую позицию
	int _type = scaner->Scaner(l);	// Получить текущую лексему
	while (_type == DIV or _type == MOD or _type == MULT)
	{
		X();
		uk1 = scaner->GetUK(); // Запомнить текущую позицию
		_type = scaner->Scaner(l); // Получить текущую лексему
	}
	scaner->SetUK(uk1);  // Вернуть старую позицию
}

// Элементарное выражение
void Diagram::X() {
	LEX l;
	int uk1;
	int _type = scaner->Scaner(l); // Получить текущую лексему

	if (_type != ID and _type != LBRACKET and _type != CONSTCHAR and _type != CONSTSTRING and _type != CONSTINT)
		scaner->PrintError("Ошибка! Ожидался идентификатор, левая скобка или констанста char, string, int.");

	if (_type == ID)
	{
		// Поиск имени идентификатора в таблице
		Tree* v1 = tree->SemGetType(l);

		uk1 = scaner->GetUK(); // Запомнить текущую позицию
		_type = scaner->Scaner(l); // Получить текущую лексему
		if (_type != LSBRACKET)
			scaner->SetUK(uk1);  // Вернуть старую позицию
		else
		{
			A();
			_type = scaner->Scaner(l); // Получить текущую лексему
			if (_type != RSBRACKET)
				scaner->PrintError("Ошибка! Ожидалась правая квадратная скобка.");

		}
	}
	else if (_type == LBRACKET)
	{
		A();
		_type = scaner->Scaner(l); // Получить текущую лексему
		if (_type != RBRACKET) 
			scaner->PrintError("Ошибка! Ожидалась правая скобка.");
	}
	else if (_type == CONSTCHAR or _type == CONSTINT or _type == CONSTSTRING)
		return;
}


void Diagram::printTree()
{
	tree->Print();
}