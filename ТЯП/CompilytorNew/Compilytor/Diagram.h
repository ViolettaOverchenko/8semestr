#pragma once
#include "Scaner.h"
#include "Tree.h"
class Diagram
{
private:
	TScaner *scaner;
	Tree* tree = new Tree();

public:
	Diagram(TScaner* s) { scaner = s; }
	~Diagram() {}

	void S(); // ��������
	void T(); // ���� ��������
	bool FOrW();	// ������� ��� ������
	void W();	// ������
	void F();	// �������
	void D();	// ������
	void Z();	// ���������, ������
	void A();	// ���������
	void Q();	// ��������� ��������
	void O();	// ��������� � ��������
	void K();	// �������� � ����� �������
	void H();	// while
	void U();	// 
	void B();	// ���������
	void E();	// ���������
	void X();	// ������������ ���������
	void printTree();

};


