#include "Tree.h"
#define MAX(a,b) a > b ? a : b

// ����������� ������� ���� � ��������� ������� � �������
Tree::Tree(Tree* l, Tree* r, Tree* u, Node* d)
{
	n = new Node();
	Up = u; Left = l; Right = r; // ���������� ������
	memcpy(n, d, sizeof(Node)); // ���������� ������
}

Tree::Tree(void)
// ����������� ������� ����� ���� � ������� ������� � �������
{
	n = new Node();
	Up = NULL; Left = NULL; Right = NULL;
	memcpy(n, &("------"), sizeof(Node));
}

// ������� ������ ������� �� ������� ������� this
void Tree::SetLeft(Node* Data)
{
	Tree* a = new Tree(NULL, NULL, this, Data); // ����� �������
	this->Left = a; // ������� this � ����� ��������
}

// ������� ������� ������� �� ������� ������� this
void Tree::SetRight(Node* Data)
{
	Tree* a = new Tree(NULL, NULL, this, Data); // ����� �������
	Right = a; // ������� this � ����� ��������
}

// ����� ������ � ������, ������� �� ������� ������� this
// �� ��� ����� ����� �� ������
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

// ����� ������ � ������ �� �������� ������� From
// �� ��� ����� ����� �� ������
Tree* Tree::FindUp(Tree* From, LEX id)
{
	Tree* i = From; // ������� ������� ������
	while ((i != NULL) &&
		(memcmp(id, i->n->id, MAX(strlen(i->n->id), strlen(id))) != 0))
		i = i->Up; // ����������� ������ �� ������
	return i;
}

// ���������� ��������� ������ ������
void Tree::Print(void)
// ���������� ��������� ������ ������
{
	printf("������� � ������� %s ----->", n->id);
	if (Left != NULL) printf(" ����� ������ %s", Left->n->id);
	if (Right != NULL) printf(" ������ ������ %s", Right->n->id);
	printf("\n");
	if (Left != NULL) Left->Print();
	if (Right != NULL) Right->Print();
}

TScaner* Tree::sc = NULL;
Tree* Tree::Cur = (Tree*)NULL;

// ���������� ������� ���� ������
void Tree::SetCur(Tree* a)
{
	Cur = a;
}

// �������� �������� �������� ���� ������
Tree* Tree::GetCur(void)
{
	return Cur;
}


Tree* Tree::FindUpOneLevel(Tree* From, LEX id) {
	Tree* i = From; // ������� ������� ������
	while ((i != NULL) && (i->Up != NULL) && (i->Up->Right != i))
	{
		if (memcmp(id, i->n->id, MAX(strlen(i->n->id), strlen(id))) == 0)
			return i; // �a��� ����������� �������������
		i = i->Up; // ����������� ������ �� ������
	}
	return NULL;
}

// �������� �������������� � �� ��������� �������� ������ �����.
// ����� �������������� ����� �� ������� Addr.
int Tree::DupControl(Tree* Addr, LEX a)
{
	if (FindUpOneLevel(Addr, a) == NULL) return 0;
	return 1;
}

//������������� ������������
// ��������� �������������� a � ������� � ����� t
Tree* Tree::SemInclude(LEX a, TypeObject t)
{
	if (DupControl(GetCur(), a) && strlen(a) != 0)
		sc->PrintError("��������� �������� ��������������: ");
	Tree* v; Node b;
	if (t != ObjFunction)
	{
		memcpy(b.id, a, strlen(a) + 1);
		b.typeObject = t;
		b.Data = NULL;
		GetCur()->SetLeft(&b); // ������� ������� - ����������
		SetCur(GetCur()->Left);
		return GetCur();
	}
	else
	{
		memcpy(b.id, a, strlen(a) + 1);
		b.typeObject = t;
		b.Data = NULL;
		Cur->SetLeft(&b); // ������� ������� - �������
		Cur = Cur->Left;
		v = Cur; // ��� ����� �������� ����� ������ �� �������
		memcpy(&b.id, &"", 2); b.typeObject = (TypeObject)EMPTY; b.Data = NULL;
		Cur->SetRight(&b); // ������� ������ �������
		Cur = Cur->Right;
		return v;
	}
}

// ���������� ��� t ��� ���������� �� ������ Addr
void Tree::SemSetType(Tree* Addr, TypeObject t)
{
	Addr->GetNode()->typeObject = t;
}

// ����� � ������� ���������� � ������ a
// � ������� ������ �� ��������������� ������� ������
Tree* Tree::SemGetType(LEX a)
{
	Tree* v = FindUp(Cur, a);
	if (v == NULL)
		sc->PrintError("����������� �������� �������������� ");
	if (v->n->typeObject == ObjFunction)
		sc->PrintError("�������� ������������� ������ ������� ");
	return v;
}

// ����� � ������� ������� � ������ a
// � ������� ������ �� ��������������� ������� ������.
Tree* Tree::SemGetFunct(LEX a)
{
	Tree* v = FindUp(Cur, a);
	if (v == NULL)
		sc->PrintError("����������� �������� ������� ");
	if (v->GetNode()->typeObject != ObjFunction)
		sc->PrintError("�� �������� �������� ������������� ");
	return v;
}