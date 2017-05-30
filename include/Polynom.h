#pragma once
#include "Monom.h"
#include <iostream>
#include <string>
using namespace std;
class Polynom
{
	Monom* first;//��������� �� ������ �����
public:
	Polynom();//����������� �� ���������
	Polynom(string s);//�����������, �������������� ������ � �������

	void Insert(int n, int e);//���������� ������, ����� ������� ��� �������
	void InsertBefore(int n, int e, Monom*x);//�������� ����� ��
	string ToString();//�������������� �������� � ������

	bool IsNumber(char c);//��� �����?
	bool IsVariable(char c);//��� ����������?
	bool IsOperation(char c);//��� ��������?
	int Exp(char c);//������� ����������

	Polynom& operator+(Polynom&);//P1 + P2
	Polynom& operator-(Polynom&);//P1 + P2
	Polynom* operator*(Polynom*);//P1 * P2
	int Compute(int x, int y, int z);//��� �������� x y z
	Polynom& dx();
	Polynom& dy();
	Polynom& dz();
};

