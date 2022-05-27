
// Задание 2

#include <iostream>
#include <vector>
#include <algorithm>

#include "Manipulator.h"


int getOptimalManipulator(std::vector <Manipulator> manipulators, Point point)
{
	auto optimalManipulator = std::min_element(manipulators.begin(), manipulators.end(),
		[point](Manipulator& a, Manipulator& b)
		{
			if (a.getDistanceToPoint(point) == -1)
				return false;
			else if (b.getDistanceToPoint(point) == -1)
				return true;
			else
				return a.getDistanceToPoint(point) < b.getDistanceToPoint(point);
		});

	if (optimalManipulator == manipulators.end())
	{
		return -1;
	}

	if (optimalManipulator->getDistanceToPoint(point) == -1)
	{
		return -1;
	}

	return optimalManipulator - manipulators.begin();
}

int getNearestManipulator(std::vector <Manipulator> manipulators, Point point)
{
	auto nearestManipulator = std::min_element(manipulators.begin(), manipulators.end(),
		[point](Manipulator& a, Manipulator& b)
		{
			return Point::getDistance(a.getTool(), point) < Point::getDistance(b.getTool(), point);
		});

	if (nearestManipulator == manipulators.end())
	{
		return -1;
	}

	return nearestManipulator - manipulators.begin();
}



int main()
{
	// Массив точек
	std::vector <Point> P;
	int sizeP = 0;

	std::cout << "Count points: ";
	std::cin >> sizeP;

	std::cout << "Array of points {x, y}: ";
	for (int i = 0; i < sizeP; i++)
	{
		Point Pk;
		std::cin >> Pk;
		P.push_back(Pk);
	}

	// Манипуляторы
	Point O1;
	Point O2;
	double R1;
	double R2;

	std::cout << "Coordinates of the first manipulator: ";
	std::cin >> O1;

	std::cout << "Radius of the first manipulator:";
	std::cin >> R1;

	std::cout << "Coordinates of the second manipulator: ";
	std::cin >> O2;

	std::cout << "Radius of the second manipulator:";
	std::cin >> R2;

	// Массив манипуляторов
	std::vector <Manipulator> manipulators; 
	
	// Инициализация манипуляторов
	manipulators.push_back({ O1, R1 });
	manipulators.push_back({ O2, R2 });

	// Индексы манипуляторов для каждой точки
	std::vector <int> numManipulator;

	// Цикл для определения, какие точки обойдет какой манипулятор
	for (auto& i : P)
	{
		int numOptimalManipulator = getOptimalManipulator(manipulators, i);
		int numNearestManipulator = getNearestManipulator(manipulators, i);

		if (numOptimalManipulator != -1) // Если найден оптимальный манипулятор
		{
			numManipulator.push_back(numOptimalManipulator);
		}
		else if (numNearestManipulator != -1)
		{
			manipulators[numNearestManipulator].moveToPoint(i);
			numManipulator.push_back(numNearestManipulator);
		}
		else
		{
			numManipulator.push_back(-1);
		}
	}

	// Вывед строк: какие точки обойдет каждый манипулятор
	for (int i = 0; i < manipulators.size(); i++)
	{
		std::cout << "Manipulator number " << i << ": ";
		for (int j = 0; j < numManipulator.size(); j++)
		{
			if (numManipulator[j] == i)
				P[j].output();
			else
				std::cout << "________";
			std::cout << " ";
		}
		std::cout << std::endl;
	}


	return 0;
}