
#include "Manipulator.h"

Manipulator::Manipulator(Point center, double radius)
{
	center_ = tool_ = center;
	radius_ = radius;
}

Point Manipulator::getTool()
{
	return tool_;
}


Point Manipulator::getCenter()
{
	return center_;
}


double Manipulator::getRadius()
{
	return radius_;
}

double Manipulator::getDistanceToPoint(Point point)
{
	double distance = Point::getDistance(center_, point);
	if (distance <= radius_)
		return Point::getDistance(tool_ , point);
	else
		return -1;
}

void Manipulator::setCenter(Point point)
{
	center_ = point;
}

void Manipulator::moveToPoint(Point point)
{
	if (getDistanceToPoint(point) == -1)
	{
		Point delta = center_ - point;
		double distance = Point::getDistance(center_, point);
		center_ = point + (center_ - point) * (radius_ / distance);

	}

	tool_ = point;
}

