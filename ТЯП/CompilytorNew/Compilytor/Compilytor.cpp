// Compilytor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "defs.h"
#include "Scaner.h" 
#include "Diagram.h" 
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	TScaner* sc;
	if (argc <= 1) sc = new TScaner("input.txt");// файл по умолчанию
	else sc = new TScaner(argv[1]); // задан файл

	//TypeLex l;  //локальные переменные типа и изображения лексем
	sc->GetData();
	/*do {
		type = sc->Scaner(l);
		cout << type << "  -->  " << l << endl;
	} while (type != END);*/

	// Синтаксический анализатор
	Diagram* dg = new Diagram(sc);
	char inp;
	cout << "Флаг интерпретации (Y/N): ";
	cin >> inp;
	dg->SetInterpret(inp == 'Y');
	dg->S();

	//dg->printTree();
	system("pause");
	return 0;
}