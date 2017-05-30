#pragma once
class Monom
{
	int num;//коэффициент
	int exp;//степень xyz
	Monom* next;//Указатель на следующий моном
public:
	Monom();//Конструктор по умолчанию
	Monom(int n, int e);//Конструктор
	friend class Polynom;//Классу Полином доступны protected данные
};

