#include "Tree.h"
#define MAX(a,b) a > b ? a : b

// конструктор создает узел с заданными связями и данными
Tree::Tree(Tree* l, Tree* r, Tree* u, Node* d)
{
	n = new Node();
	Up = u; Left = l; Right = r; // установили ссылки
	memcpy(n, d, sizeof(Node)); // установили данные
}

Tree::Tree(void)
// конструктор создает новый узел с пустыми связями и данными
{
	n = new Node();
	Up = NULL; Left = NULL; Right = NULL;
	memcpy(n, &("------"), sizeof(Node));
}

// создать левого потомка от текущей вершины this
void Tree::SetLeft(Node* Data)
{
	Tree* a = new Tree(NULL, NULL, this, Data); // новая вершина
	this->Left = a; // связали this с новой вершиной
}

// создать правого потомка от текущей вершины this
void Tree::SetRight(Node* Data)
{
	Tree* a = new Tree(NULL, NULL, this, Data); // новая вершина
	Right = a; // связали this с новой вершиной
}

// поиск данных в дереве, начиная от текущей вершины this
// до его корня вверх по связям
Tree* Tree::FindUp(LEX id)
{
	return FindUp(this, id);
}

Node* Tree::GetNode() {
	return this->n;
}

void Tree::SetNode(Node* n) {
	this->n = n;
}

// поиск данных в дереве от заданной вершины From
// до его корня вверх по связям
Tree* Tree::FindUp(Tree* From, LEX id)
{
	Tree* i = From; // текущая вершина поиска
	while ((i != NULL) &&
		(memcmp(id, i->n->id, MAX(strlen(i->n->id), strlen(id))) != 0))
		i = i->Up; // поднимаемся наверх по связям
	return i;
}

// отладочная программа печати дерева
void Tree::Print(void)
// отладочная программа печати дерева
{
	printf("Вершина с данными %s ----->", n->id);
	if (Left != NULL) printf(" слева данные %s", Left->n->id);
	if (Right != NULL) printf(" справа данные %s", Right->n->id);
	printf("\n");
	if (Left != NULL) Left->Print();
	if (Right != NULL) Right->Print();
}

TScaner* Tree::sc = NULL;
Tree* Tree::Cur = (Tree*)NULL;

// установить текущий узел дерева
void Tree::SetCur(Tree* a)
{
	Cur = a;
}

// получить значение текущего узла дерева
Tree* Tree::GetCur(void)
{
	return Cur;
}


Tree* Tree::FindUpOneLevel(Tree* From, LEX id) {
	Tree* i = From; // текущая вершина поиска
	while ((i != NULL) && (i->Up != NULL) && (i->Up->Right != i))
	{
		if (memcmp(id, i->n->id, MAX(strlen(i->n->id), strlen(id))) == 0)
			return i; // нaшли совпадающий идентификатор
		i = i->Up; // поднимаемся наверх по связям
	}
	return NULL;
}

// Проверка идентификатора а на повторное описание внутри блока.
// Поиск осуществляется вверх от вершины Addr.
int Tree::DupControl(Tree* Addr, LEX a)
{
	if (FindUpOneLevel(Addr, a) == NULL) return 0;
	return 1;
}

//Семантические подпрограммы
// занесение идентификатора a в таблицу с типом t
Tree* Tree::SemInclude(LEX a, TypeObject t)
{
	if (DupControl(GetCur(), a) && strlen(a) != 0)
		sc->PrintError("Повторное описание идентификатора: ");
	Tree* v; Node b;
	if (t != ObjFunction)
	{
		memcpy(b.id, a, strlen(a) + 1);
		b.typeObject = t;
		b.Data = NULL;
		GetCur()->SetLeft(&b); // сделали вершину - переменную
		SetCur(GetCur()->Left);
		return GetCur();
	}
	else
	{
		memcpy(b.id, a, strlen(a) + 1);
		b.typeObject = t;
		b.Data = NULL;
		Cur->SetLeft(&b); // сделали вершину - функцию
		Cur = Cur->Left;
		v = Cur; // это точка возврата после выхода из функции
		memcpy(&b.id, &"", 2); b.typeObject = (TypeObject)EMPTY; b.Data = NULL;
		Cur->SetRight(&b); // сделали пустую вершину
		Cur = Cur->Right;
		return v;
	}
}

// установить тип t для переменной по адресу Addr
void Tree::SemSetType(Tree* Addr, TypeObject t)
{
	Addr->GetNode()->typeObject = t;
}

// найти в таблице переменную с именем a
// и вернуть ссылку на соответствующий элемент дерева
Tree* Tree::SemGetType(LEX a)
{
	Tree* v = FindUp(Cur, a);
	if (v == NULL)
		sc->PrintError("Отсутствует описание идентификатора ");
	if (v->n->typeObject == ObjFunction)
		sc->PrintError("Неверное использование вызова функции ");
	return v;
}

// найти в таблице функцию с именем a
// и вернуть ссылку на соответствующий элемент дерева.
Tree* Tree::SemGetFunct(LEX a)
{
	Tree* v = FindUp(Cur, a);
	if (v == NULL)
		sc->PrintError("Отсутствует описание функции ");
	if (v->GetNode()->typeObject != ObjFunction)
		sc->PrintError("Не является функцией идентификатор ");
	return v;
}