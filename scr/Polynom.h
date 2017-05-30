#pragma once
#include "Monom.h"
#include <iostream>
#include <string>
using namespace std;
class Polynom
{
	Monom* first; //Указатель на первый моном
public:
	Polynom(); //Конструктор по умолчанию
	Polynom(string s); //Конструктор, преобразование строки в полином

	void Insert(int n, int e); //Добавление монома, поиск позиции для вставки
	void InsertBefore(int n, int e, Monom*x); //Добавить моном до
	string ToString(); //Преобразование полинома в строку

	bool IsNumber(char c); //Это число?
	bool IsVariable(char c); //Это переменная?
	bool IsOperation(char c); //Это операция?
	int Exp(char c); //Степень переменной

	Polynom& operator+(Polynom&); //P1 + P2
	Polynom& operator-(Polynom&); //P1 + P2
	Polynom* operator*(Polynom*); //P1 * P2
};

