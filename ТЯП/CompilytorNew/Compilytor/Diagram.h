#pragma once
#include "Scaner.h"
#include "Tree.h"
class Diagram
{
private:
	TScaner* scaner;
	Tree* tree = new Tree();
	bool flagInterpret = true;
	TData RetValue;
public:
	Diagram(TScaner* s) { scaner = s; }
	~Diagram() {}
	void SetInterpret(bool flag) { this->flagInterpret = flag; }
	bool GetInterpret() { return flagInterpret; }
	void S(); // ��������
	void T(); // ���� ��������
	bool FOrW();	// ������� ��� ������
	void W();	// ������
	void F();	// �������
	void Main();	// ������� �������
	void D(DataType type);	// ������
	void Z(DataType type);	// ���������, ������
	void A(TData* data);	// ���������
	void Q();	// ��������� ��������
	void O();	// ��������� � ��������
	void K();	// �������� � ����� �������
	void H();	// while
	void U();	// 
	void B(TData* data);	// ���������
	void P(TData* data);
	void E(TData* data);	// ���������
	void X(TData* data);	// ������������ ���������
	void FC(TData* data);	// ����� �������
	TData CallFunc(Tree* func);		// ����� ������� 2
	void V(Tree* var, TData* data); //����������, ������� �������
	void RET();
	void printTree();
};


