#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "Scaner.h" 

using namespace std;

TScaner::TScaner() {
	//GetData();
	SetUK(0);
}

LEX Keyword[MAX_KEYW] = { "double", "char", "while", "main", "return" };
int IndexKeyword[MAX_KEYW] = { DOUBLE, CHAR, WHILE, MAIN, RETURN };

void TScaner::SetUK(int i) { uk = i; }		// ������������ ���������

int TScaner::GetUK(void) { return uk; }		// ��������� ���������

void TScaner::PrintError(const char* err, LEX l) {
	int line = 1;
	int symbol = 1;
	int n = GetUK();
	for (int i = 0; i < n; i++)
	{
		if (text[i] == '\n')
		{
			line += 1;
			symbol = 1;
		}
		else symbol += 1;
	}
	cout << "������: " << err << "������" << line << " ������: " << l << endl;
	// ������ �������������� ������, ����� ���������
	// �� ������ err � ��������� ������ l
	// �������� ��� ���������� ���������
	exit(1);
}

int TScaner::Scaner(LEX l) {
	int i;								// ������� ����� �������
	// ������� ���� �������
	for (i = 0; i < MAX_LEX; i++)
		l[i] = 0;
	i = 0;								// ������� ����������� � ������� i
	// ��� ������������ ��������
start:
	while ((text[uk] == ' ') || (text[uk] == '\n') || (text[uk] == '\t'))
		uk++;							// ���������� ���������� ��������
	if ((text[uk] == '/') && (text[uk + 1] == '/'))
	{
		// ������� �����������, ���������� ����� �� '\n'
		uk += 2;
		while ((text[uk] != '\n') && (text[uk] != '#'))
			uk++;
		goto start;
	}
	if ((text[uk] == '/') && (text[uk + 1] == '*'))
	{ // ������� �����������, ���� ���������� ����� �� �*/�
		uk += +2;
		while ((text[uk] != '*' || text[uk + 1] != '/') && text[uk] != 0) {
			uk++;
		}
		uk += 2;
		goto start;
	}

	if (text[uk] == '\0') {
		l[0] = '\0';
		return END;
	}
	else if ((text[uk] <= '9') && (text[uk] >= '0'))
	{
		l[i++] = text[uk++];
		while ((text[uk] <= '9') && (text[uk] >= '0'))
			if (i < MAX_CONSTINT)
			{
				l[i++] = text[uk++];
			}
			else
			{	// ���� ��������� ������� �������, �� ����� ������
				while ((text[uk] <= '9') && (text[uk] >= '0'))
					uk++;
				cout << "������. ������� ������� ���������:" << endl;
				return ERROR;
			}
		return CONSTINT;
	}
	else if ((text[uk] >= 'a') && (text[uk] <= 'z') ||
		(text[uk] >= 'A') && (text[uk] <= 'Z') ||
		(text[uk] == '_'))
	{
		// �������������
		l[i++] = text[uk++];
		while (((text[uk] >= 'a') && (text[uk] <= 'z')) ||
			((text[uk] >= 'A') && (text[uk] <= 'Z')) ||
			(text[uk] == '_'))
		{
			if (i < MAX_LEX)
				l[i++] = text[uk++];
			else
				uk++;	// �������� ������� �������������
		}
		// �������� �� �������� �����
		for (int j = 0; j < MAX_KEYW; j++)
			if (strcmp(l, Keyword[j]) == 0)
				return IndexKeyword[j];
		return ID;
	}
	else if (text[uk] == '\'' && text[uk + 2] == '\'')
	{
		uk++;		// �� ����� �������� ������� � ���������
		l[i++] = text[uk++];
		uk++;	// �� ����� �������� ������� � ���������
		return CONSTCHAR;
	}
	else if (text[uk] == '\"')
	{
		uk++;		// �� ����� �������� ������� � ���������
		while ((text[uk] != '\"') && (text[uk] != '#') && (text[uk] != '\n'))
		{
			if (i < MAX_LEX)
				l[i++] = text[uk++];
			else
				uk++;
		}
		if (text[uk] != '\"')
		{
			cout << "�������� ��������� ���������" << endl;
			return ERROR;
		}
		uk++;		// ����������� �������
		return CONSTSTRING;
	}
	else if (text[uk] == ',')
	{
		l[i++] = text[uk++];
		return COMMA;
	}
	else if (text[uk] == ';')
	{
		l[i++] = text[uk++];
		return SEMICOLON;
	}
	else if (text[uk] == '(')
	{
		l[i++] = text[uk++];
		return LBRACKET;
	}
	else if (text[uk] == ')')
	{
		l[i++] = text[uk++];
		return RBRACKET;
	}
	else if (text[uk] == '{')
	{
		l[i++] = text[uk++];
		return LBRACE;
	}
	else if (text[uk] == '}')
	{
		l[i++] = text[uk++];
		return RBRACE;
	}
	else if (text[uk] == '[')
	{
		l[i++] = text[uk++];
		return LSBRACKET;
	}
	else if (text[uk] == ']')
	{
		l[i++] = text[uk++];
		return RSBRACKET;
	}
	else if (text[uk] == '<')
	{
		l[i++] = text[uk++];
		if (text[uk] == '=')
		{
			l[i++] = text[uk++];
			return LE;
		}
		return LT;
	}
	else if (text[uk] == '>')
	{
		l[i++] = text[uk++];
		if (text[uk] == '=')
		{
			l[i++] = text[uk++];
			return GE;
		}
		return GT;
	}
	else if (text[uk] == '=')
	{
		l[i++] = text[uk++];
		if (text[uk] == '=')
		{
			l[i++] = text[uk++];
			return EQ;
		}
		return SAVE;
	}
	else if (text[uk] == '!' && text[uk + 1] == '=')
	{
		l[i++] = text[uk++];
		l[i++] = text[uk++];
		return NEQ;
	}
	else if (text[uk] == '+')
	{
		l[i++] = text[uk++];
		if (text[uk] == '=')
		{
			l[i++] = text[uk++];
			return PLUSEQ;
		}
		if (text[uk] == '+')
		{
			l[i++] = text[uk++];
			return PLUSPLUS;
		}
		return PLUS;
	}
	else if (text[uk] == '-')
	{
		l[i++] = text[uk++];
		if (text[uk] == '=')
		{
			l[i++] = text[uk++];
			return MINUSEQ;
		}
		if (text[uk] == '-')
		{
			l[i++] = text[uk++];
			return MINUSMINUS;
		}
		return MINUS;
	}
	else if (text[uk] == '/')
	{
		l[i++] = text[uk++];
		if (text[uk] == '=')
		{
			l[i++] = text[uk++];
			return DIVEQ;
		}
		return DIV;
	}
	else if (text[uk] == '*')
	{
		l[i++] = text[uk++];
		if (text[uk] == '=')
		{
			l[i++] = text[uk++];
			return MULTEQ;
		}
		return MULT;
	}
	else if (text[uk] == '%')
	{
		l[i++] = text[uk++];
		if (text[uk] == '=')
		{
			l[i++] = text[uk++];
			return MODEQ;
		}
		return MOD;
	}
	else
	{
		cout << "����������� ������" << endl;
		l[i++] = text[uk++];
		return ERROR;
	}

}

TScaner::TScaner(string filename) {
	LoadData(filename);
}

void TScaner::LoadData(string filename) {
	memset(text, 0, MAX_TEXT);
	ifstream inp(filename);
	inp.read(text, MAX_TEXT);
	inp.close();
}

void TScaner::GetData(void) {
	std::ifstream in("input.txt");
	if (!in.is_open())
		std::cout << "������! ���� ��� ������ �����������." << std::endl; // ���� ����� ���
	else
	{
		int i;
		i = 0;
		while (!in.eof())
		{
			in.get(text[i]);
			std::cout << text[i];
			i++;
			if (i >= MAX_TEXT)
			{
				std::cout << "������� ������� ������ ��������� ������" << std::endl;
				break;
			}
		}
		in.close();
		text[i - 1] = '\0';
		std::cout << text[i] << std::endl;
	}
}