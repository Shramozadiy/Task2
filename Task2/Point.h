#pragma once

#include <iostream>
#include <cmath>

class Point
{
public:
	
	Point(double x = 0, double y = 0);

	Point(const Point&); 

	void setCoordinates(double x, double y);

	void getCoordinates(double& x, double& y);

	static double getDistance(const Point& point1, const Point& point2);

	Point operator+(const Point& a);

	Point operator-(const Point& a);

	Point operator*(double a);

	void output();

	friend std::istream& operator>>(std::istream& is, Point& point);

private:
	double x = 0;
	double y = 0;
};