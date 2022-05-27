


#include "Point.h"


Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& point)
{
	x = point.x;
	y = point.y;
}

void Point::setCoordinates(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Point::getCoordinates(double& x, double& y)
{
	x = this->x;
	y = this->y;
}

double Point::getDistance(const Point& point1, const Point& point2)
{
	double distance = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
	return distance;
}

Point Point::operator+(const Point& a)
{
	Point point = { this->x + a.x, this->y + a.y };
	return point;
}

Point Point::operator-(const Point& a)
{
	Point point = { this->x - a.x, this->y - a.y};
	return point;
}

Point Point::operator*(double a)
{
	Point point = { this->x * a, this->y * a };
	return point;
}

void Point::output()
{
	std::cout << "{ " << x << ", " << y << " }";
}

std::istream& operator>>(std::istream& is, Point& point)
{
	is >> point.x >> point.y;
	return is;
}