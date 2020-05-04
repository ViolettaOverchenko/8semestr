#pragma once
#include "defs.h"
#include <string>
using namespace std;

class TScaner {
private:
	TypeMod text;	// �������� �����
	int uk = 0;			// ��������� ������� ������� � �������� ������
	int line = 1, pos = 0; //������, �������
	int max = -1;
	int maxPos = -1;
public:
	TScaner(string filename);
	void SetUK(int i);
	int GetUK(void);
	void PrintError(const char* err, LEX l);
	int Scaner(LEX l);
	void GetData(void);
	TScaner();
	~TScaner() {}
	void LoadData(string filename);
};
