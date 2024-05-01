#pragma once
#include <iostream>
template <typename T>
static T input(const char* text)//функция ввода с встроенной обработкой исключений
{
	T digital = 0;
	double tempDigit;
	bool flag = true;
	do {
		std::cout << text;
		std::cin >> tempDigit;
		flag = std::cin.good();// cin.good()= влияет на работу потока. после него не отработал getline...добавил ТУТ
		//cout << "cin.good()= " << cin.good() << std::endl;
		if (!flag)
		{
			std::cout << "Error of input. Not a number. Enter num again.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			digital = tempDigit;
			if (double(digital) != tempDigit)
			{
				std::cout << "Error of Type." << "reEntry is requared.\n";
				flag = false;
			}
		}
	} while (!flag);
	//Добавил чистку потоков. ТУТ  cin.good()= влияет на работу потока. после него не отработал getline
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return digital;
}
