#include "Polynom.h"

Polynom::Polynom() //����������� �� ���������
{
	first = 0;
}

Polynom::Polynom(string s) //�����������
{
	first = 0;
	char per = ' '; //x y z
	int n = 0; //�����������
	int e = 0; //�������
	int k = 1; //����������
	s += "+";
	for (unsigned int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (c == ' ') //������������ �������
			continue;
		if (IsNumber(c))
		{
			if (per == ' ') //���� ��� �����������
				n = n * 10 + (int)c - 48;
			else //���� ��� �������
				e += ((int)c - 48)*Exp(per);
		}
		else if (IsVariable(c)) //���� ��� � ��� y ��� z
			per = c;
		else if (IsOperation(c)) //���� ��� �������� + ��� -
		{
			if (n)
			{
				n = n * k;
				k = 1;
				Insert(n, e);
			}
			if (c == '-') //������������� �����������
				k = -1;
			n = 0; e = 0; per = ' ';
		}
	}
}

void Polynom::Insert(int n, int e) //���������� ������, ����� ������� ��� �������
{
	Monom* i = first;
	if (i == 0) //���� ������� ����
		first = new Monom(n, e);
	else
	{
		while (i) 
		{//�� ����� ��������
			if (i->exp == e) //���� ������� �������
			{
				i->num += n;
				break; //����� ������ ������ ��������� �� ����
			}
			if (i->exp < e) //���� ������� ���������� ������
			{
				InsertBefore(n, e, i); //�� ��������� ����� ���
				break;
			}
			if (i->next == 0) //��������� � �����
			{
				i->next = new Monom(n, e);
				break;
			}
			i = i->next;
		}
	}
}

void Polynom::InsertBefore(int n, int e, Monom* x) //�������� ����� ��
{
	if (x == first) //�������� ����� ������
	{
		Monom* i = first;
		first = new Monom(n, e);
		first->next = i;
	}
	else
	{
		Monom*i;
		for (i = first; i->next != x; i = i->next); //���� ����� ����� �������� �������
		i->next = new Monom(n, e);
		i->next->next = x;
	}
}

string Polynom::ToString() //�������������� �������� � ������
{
	string res = "";
	char b[16];
	Monom* i = first;
	if (i == 0) //���� ������� ����
		return "0";
	while (i)
	{
		sprintf_s(b, "%d", i->num);
		res += b;
		res += "x";
		sprintf_s(b, "%d", i->exp / 100);
		res += b;
		res += "y";
		sprintf_s(b, "%d", i->exp / 10 % 10);
		res += b;
		res += "z";
		sprintf_s(b, "%d", i->exp % 10);
		res += b;
		if (i->next)
		{
			if (i->next->num > 0)
				res += "+";
		}
		i = i->next;
	}
	return res;
}

bool Polynom::IsNumber(char c) //��� �����
{
	int chis = (int)c;
	if ((chis > 47) && (chis < 58)) //0...9
		return true;
	return false;
}

bool Polynom::IsVariable(char c) //��� x y z
{
	int chis = (int)c;
	if ((chis > 119) && (chis < 123)) //x, y, z
		return true;
	return false;
}

int Polynom::Exp(char c) //x-100 y-10 z-1 �������
{
	if (c == 'x')
		return 100; //x
	if (c == 'y')
		return 10; //y
	return 1; //z
}

bool Polynom::IsOperation(char c) //��� + ��� - ����� ��������
{
	if (c == '+' || c == '-')
		return true;
	return false;
}

Polynom& Polynom::operator+(Polynom&x) //P1 + P2 �������� ���������
{
	Polynom*res = new Polynom();
	Monom*p1 = this->first;
	Monom*p2 = x.first;
	Monom * tail;
	
	res->first = new Monom;
	tail = res->first;

	while (p1 && p2)
	{
		if (p1->exp == p2->exp) 
		{
			if (p1->num + p2->num)
			{
				tail->next = new Monom(p1->num + p2->num, p1->exp);
				tail = tail->next;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->exp > p2->exp) 
		{
			tail->next = new Monom(p1->num, p1->exp);
			tail = tail->next;

			p1 = p1->next;
		}
		else
		{
			tail->next = new Monom(p2->num, p2->exp);
			tail = tail->next;

			p2 = p2->next;
		}
	}
	while (p1)
	{
		tail->next = new Monom(p1->num, p1->exp);
		tail = tail->next;

		p1 = p1->next;
	}
	while (p2)
	{
		tail->next = new Monom(p2->num, p2->exp);
		tail = tail->next;

		p2 = p2->next;
	}

	tail = res->first->next;
	delete res->first;
	res->first = tail;

	return *res;
}

Polynom& Polynom::operator-(Polynom&x) //P1 - P2 ��������� ���������
{
	Polynom*res = new Polynom();
	Monom*p1 = this->first;
	Monom*p2 = x.first;
	Monom * tail;

	res->first = new Monom;
	tail = res->first;

	while (p1 && p2)
	{
		if (p1->exp == p2->exp)
		{
			if (p1->num - p2->num)
			{
				tail->next = new Monom(p1->num - p2->num, p1->exp);
				tail = tail->next;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->exp > p2->exp)
		{
			res->Insert(p1->num, p1->exp);
			p1 = p1->next;
		}
		else
		{
			tail->next = new Monom(p1->num, p1->exp);
			tail = tail->next;
			p2 = p2->next;
		}
	}
	while (p1)
	{
		tail->next = new Monom(p1->num, p1->exp);
		tail = tail->next;
		p1 = p1->next;
	}
	while (p2)
	{
		tail->next = new Monom(p2->num, p2->exp);
		tail = tail->next;
		p2 = p2->next;
	}
	return *res;
}

Polynom* Polynom::operator*(Polynom* x) //P1 * P2 ��������� ���������
{
	Polynom*res = new Polynom();
	Monom*p1 = this->first;
	while (p1)
	{
		Monom*p2 = x->first;
		while (p2)
		{
			//�������� ������� (>9)
			int x = p1->exp / 100 + p2->exp / 100;
			int y = p1->exp / 10 % 10 + p2->exp / 10 % 10;
			int z = p1->exp % 10 + p2->exp % 10;
			if (x > 9 || y > 9 || z > 9)
			{
				res = NULL;
				return res;
			}
			res->Insert(p1->num*p2->num, p1->exp + p2->exp);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return res;
}
