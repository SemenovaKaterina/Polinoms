#include "Monom.h"

Monom::Monom() //����������� �� ���������
{
	num = 0;
	exp = 0;
	next = 0;
}

Monom::Monom(int n, int e) //�����������
{
	num = n;
	exp = e;
	next = 0;
}
