/*Необходимо написать торгового советника для поиска арбитража.
Арбитраж - это торговля по цепочке различных валют в надежде заработать на небольших различиях в коэффициентах.
Алгоритм решения - Форда-Беллмана. Работает за O(EV)
*/

#include <iostream>
#include "Burse.h"
#include "Graph.h"

#include <cstdlib>

int main()
{
	Burse B;
	B.takeCurrencyNumber();
	B.takeCourses();
	Graph G(B);
	if (G.findCycleByBellmanFord())
		std::cout << "YES";
	else
		std::cout << "NO";
	system("pause");
	return 0;
}