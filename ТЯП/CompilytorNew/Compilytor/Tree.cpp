#include "Tree.h"
#define MAX(a,b) a > b ? a : b

TScaner* Tree::sc = NULL;
Tree* Tree::Cur = (Tree*)NULL;

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

const char* GetId(char* str) {
	return (str[0] == 0 ? "<empty>" : str);
}

// ���������� ��������� ������ ������
void Tree::Print(int k)
{
	for (int i = 0; i < k; i++)
		printf("\t");
	printf("������� %s ----->", GetId(n->id));
	if (Left != NULL) printf(" ����� %s", GetId(Left->n->id));
	if (Right != NULL) printf(" ������  %s", GetId(Right->n->id));
	printf("\n");
	if (Right != NULL) Right->Print(k + 1);
	if (Left != NULL) Left->Print(k);
}

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
	if (DupControl(Cur, a) && strlen(a) != 0)
		sc->PrintError("��������� �������� ��������������: ", a);
	Tree* v; Node b;
	if (t != ObjFunction)
	{
		memcpy(b.id, a, strlen(a) + 1);
		b.typeObject = t;
		b.Data.DataType = (DataType)t;
		b.Data.DataValue.DataAsDouble = NULL;
		GetCur()->SetLeft(&b); // ������� ������� - ����������
		SetCur(GetCur()->Left);
		return GetCur();
	}
	else
	{
		memcpy(b.id, a, strlen(a) + 1);
		b.typeObject = t;
		b.Data.DataValue.DataAsDouble = NULL;
		Cur->SetLeft(&b); // ������� ������� - �������
		Cur = Cur->Left;
		v = Cur; // ��� ����� �������� ����� ������ �� �������
		memcpy(&b.id, &"", 2); b.typeObject = (TypeObject)EMPTY; b.Data.DataValue.DataAsDouble = NULL;
		Cur->SetRight(&b); // ������� ������ �������
		Cur = Cur->Right;
		return v;
	}
}

// ���������� ��� t ��� ���������� �� ������ Addr
void Tree::SemSetType(Tree* Addr, TypeObject t)
{
	Addr->n->typeObject = t;
}

// ����� � ������� ���������� � ������ a
// � ������� ������ �� ��������������� ������� ������
Tree* Tree::SemGetType(LEX a)
{
	Tree* v = FindUp(Cur, a);
	if (v == NULL)
		sc->PrintError("����������� �������� �������������� ", a);
	if (v->n->typeObject == ObjFunction)
		sc->PrintError("�������� ������������� ������ ������� ", a);
	return v;
}

// ����� � ������� ������� � ������ a
// � ������� ������ �� ��������������� ������� ������.
Tree* Tree::SemGetFunct(LEX a)
{
	Tree* v = FindUp(Cur, a);
	if (v == NULL)
		sc->PrintError("����������� �������� ������� ", a);
	if (v->n->typeObject != ObjFunction)
		sc->PrintError("�� �������� �������� ������������� ", a);
	return v;
}

//��������� �� ���� �������
void Tree::SetFuncStart(int start) {
	this->n->funcStart = start;
}

int Tree::GetFuncStart() {
	return this->n->funcStart;
}

void Tree::DeleteSubTree(Tree* tree) {
	if (tree->GetChild() != NULL) {
		DeleteSubTree(tree->GetChild());
		free(tree->GetChild());
		tree->SetChild(NULL);
	}
	if (tree->GetBrother() != NULL) {
		DeleteSubTree(tree->GetBrother());
		free(tree->GetBrother());
		tree->SetBrother(NULL);
	}
}

void Tree::DeleteChilds() {
	Tree* child = GetChild(this);
	DeleteSubTree(child);
	free(child);
	this->SetChild(NULL);
}

Tree* Tree::GetChild(Tree* Addr) {
	return Addr->Right;
}

Tree* Tree::GetBrother(Tree* Addr) {
	return Addr->Left;
}

Tree* Tree::GetChild() {
	return GetChild(this);
}

Tree* Tree::GetBrother() {
	return GetBrother(this);
}

void Tree::SetChild(Tree* tree) {
	this->Right = tree;
	if (tree != NULL) tree->Up = this;
}

void Tree::SetBrother(Tree* tree) {
	this->Left = tree;
	if (tree != NULL) tree->Up = this;
}

void Tree::SetBrotherUp(Tree* tree) {
	this->Up = tree;
	tree->Left = this;
}

Tree* Tree::GetBrotherUp() {
	return this->Up;
}

Tree* Tree::CopyFunc() {
	if (this->n->typeObject != ObjFunction) return NULL;
	Tree* func = new Tree(*this->GetNode());
	func->SetChild(new Tree());

	func->Left = this->Left;
	func->Up = this;
	this->Left->Up = func;
	this->Left = func;
	Cur = func->GetChild();
	return func;
}

void Tree::RemoveCopyiedFunc() {
	if (this->n->typeObject != ObjFunction) return;
	this->Left->DeleteChilds();
	Tree* func = this->Left;
	this->Left = this->Left->Left;
	free(func);
	this->Left->Up = this;
}

Tree::Tree(Node Data) {
	this->n = new Node(Data);
}