#pragma once
class Monom
{
	int num;//�����������
	int exp;//������� xyz
	Monom* next;//��������� �� ��������� �����
public:
	Monom();//����������� �� ���������
	Monom(int n, int e);//�����������
	friend class Polynom;//������ ������� �������� protected ������
};

