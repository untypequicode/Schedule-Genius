#include "vincentcestmoi.h"

void vincentcestmoi()
{
	calculatrice();
}

#include <iostream>

int calculatrice()
{
	float data1 = 0;
	float data2 = 0;
	int test;

	std::cout << "Voulez vous faire une addition ? (0/1) ";
	std::cin >> test;
	if (test == 1)
	{
		std::cout << "Quels nombres voulez vous additionner ? " << std::endl;
		std::cin >> data1;
		std::cin >> data2;
		std::cout << data1 << " + " << data2 << " = " << data1 + data2 << std::endl;
	}

	std::cout << "Voulez vous faire une soustraction ? (0/1) ";
	std::cin >> test;
	if (test == 1)
	{
		std::cout << "Quels nombres voulez vous soustraire (a - b) ? " << std::endl;
		std::cout << "a : ";
		std::cin >> data1;
		std::cout << "b : ";
		std::cin >> data2;
		std::cout << data1 << " - " << data2 << " = " << data1 - data2 << std::endl;
	}

	std::cout << "Voulez vous faire une multiplication ? (0/1) ";
	std::cin >> test;
	if (test == 1)
	{
		std::cout << "Quels nombres voulez vous multiplier ? " << std::endl;
		std::cin >> data1;
		std::cin >> data2;
		std::cout << data1 << " x " << data2 << " = " << data1 * data2 << std::endl;
	}

	std::cout << "Voulez vous faire une division ? (0/1) " << std::endl;
	std::cin >> test;
	if (test == 1)
	{
		std::cout << "Quels nombres voulez vous diviser (a / b) ? ";
		std::cout << "a : ";
		std::cin >> data1;
		std::cout << "b : ";
		std::cin >> data2;
		std::cout << data1 << " / " << data2 << " = " << data1 / data2 << std::endl;
	}

	return 0;
}