#include "Polynom.h"
#include "gtest.h"

TEST(Monom, can_create) 
{
	ASSERT_NO_THROW(Monom());
}

TEST(Polynom, can_create) 
{
	ASSERT_NO_THROW(Polynom());
}


TEST(Polynom, can_Insert_Monom) // Insert - добавление монома, поиск позиции для вставки
{
	Polynom A;

	ASSERT_NO_THROW(A.Insert(3, 523));
}


TEST(Polynom, can_assign_to_itself)
{
	Polynom A;

	A.Insert(3, 34);

	ASSERT_NO_THROW(A = A);
}

// operator+

TEST(Polinom, can_add_empty_polinoms)
{
	Polynom A, B;

	ASSERT_NO_THROW(A + B);
}

TEST(Polynom, can_add_polinoms)
{
	Polynom A, B;

	A.Insert(34, 34);
	B.Insert(2, 0);

	ASSERT_NO_THROW(A + B);
}

// operator-

TEST(Polynom, can_sub_empty_polinoms)
{
	Polynom A, B;

	ASSERT_NO_THROW(A - B);
}

TEST(Polynom, can_sub_polinoms)
{
	Polynom A, B;

	A.Insert(3, 34);
	B.Insert(2, 0);

	ASSERT_NO_THROW(A - B);
}



