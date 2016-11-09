#ifndef BURSE
#define BURSE

#include <vector>
#include <iostream>

typedef long numbers;

class Burse
{
	numbers CurrencyNumber;
	std::vector<std::vector<float>> ExchangeRates; //курсы валют в виде матрицы
public:
	void takeCurrencyNumber();
	void takeCourses();

	friend class Graph;
};

void Burse::takeCurrencyNumber()
{
	std::cin >> CurrencyNumber;
	ExchangeRates.resize(CurrencyNumber);
	for (numbers i = 0; i < CurrencyNumber; ++i)
	{
		ExchangeRates[i].resize(CurrencyNumber);
	}
}

void Burse::takeCourses()
{
	for (numbers i = 0; i < CurrencyNumber; ++i)
	{
		for (numbers j = 0; j < CurrencyNumber; ++j)
		{
			if (i == j)
			{
				ExchangeRates[i][j] = 1;
			}
			else
			{
				std::cin >> ExchangeRates[i][j];
			}
		}
	}
}

#endif