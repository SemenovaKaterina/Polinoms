#include "Monom.h"

Monom::Monom() //Конструктор по умолчанию
{
	num = 0;
	exp = 0;
	next = 0;
}

Monom::Monom(int n, int e) //Конструктор
{
	num = n;
	exp = e;
	next = 0;
}
