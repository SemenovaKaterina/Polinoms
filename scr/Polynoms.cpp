
#include "Polynom.h"
#include "iostream"
#include <string>
#include "stdio.h"
#include "conio.h"
#include "locale.h"
using namespace::std;

int main()
{
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		string s1;
		cout << "������� ������ �������" << endl;
		cin >> s1;
		Polynom *P1 = new Polynom(s1);
		string s2;
		cout << "������� ������ �������" << endl;
		cin >> s2;
		Polynom *P2 = new Polynom(s2);
		Polynom* Res = new Polynom();
		char operation;
		cout << "������� ��������" << endl;
		cin >> operation;
		switch (operation)
		{
		case '+': *Res = *P1 + *P2; break;
		case '-': *Res = *P1 - *P2; break;
		case '*': Res = P1->operator*(P2);
			if (Res == 0)
				cout << "������������ ���������" << endl;
			break;
		}
		if (Res)
			cout << Res->ToString() << endl;
		string res;
		cout << "������� exit ��� ����������, ����� 1" << endl;
		cin >> res;
		if (res == "exit")
			break;
	}
	return 0;
}

