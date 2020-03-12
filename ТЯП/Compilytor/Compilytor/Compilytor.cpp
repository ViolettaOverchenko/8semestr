// Compilytor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "defs.h"
#include "Scaner.h" 
#include "Diagram.h" 
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	TScaner *sc = new TScaner();
	int type;
	//TypeLex l;  //локальные переменные типа и изображения лексем
	sc->GetData();
	/*do {
		type = sc->Scaner(l);
		cout << type << "  -->  " << l << endl;
	} while (type != END);*/

	// Синтаксический анализатор
	Diagram *dg = new Diagram(sc);
	dg->S();

	dg->printTree();


	system("pause");
	return 0;
}

