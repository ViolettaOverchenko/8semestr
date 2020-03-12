#pragma once
#include "defs.h"

class TScaner {
private:
	TypeMod text;	// �������� �����
	int uk;			// ��������� ������� ������� � �������� ������
	int line = 1, pos = 0; //������, �������
	int max = -1;
	int maxPos = -1;
public:
	void SetUK(int i);
	int GetUK(void);
	void PrintError(const char *err);
	int Scaner(LEX l);
	void GetData(void);
	TScaner();
	~TScaner() {}
};
