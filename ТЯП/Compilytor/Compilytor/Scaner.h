#pragma once
#include "defs.h"

class TScaner {
private:
	TypeMod text;	// исходный текст
	int uk;			// указатель текущей позиции в исходном тексте
	int line = 1, pos = 0; //строка, позиция
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
