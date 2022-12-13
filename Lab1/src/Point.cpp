/**
* @file Point.cpp Source file with implementation of Point class
*/

#include "../include/Point.hpp"
#include <iostream>
#include <utility>

class Point;

int Point::counter = 0;

Point::Point(const Point& old): _x(old._x), _y(old._y), _name(old._name), _number(counter++ + 1)
{
	std::cout << "--- Kopiujemy " << old._number << ". " << _name << std::endl;
}
Point::Point(Point&& old) noexcept: _x(std::exchange(old._x, 0)), _y(std::exchange(old._y, 0)), _number(counter++ + 1), _name(std::move(old._name))
{
	std::cout << "--- Przenosimy " << old._number << ". " << _name << std::endl;
}
Point Point::setPoint(double x, double y)
{
	return Point("Punkt X", x, y);
}
Point Point::setContrary(double x, double y)
{
	return Point("Punkt X", -x, -y);
}
Point Point::newMoved(std::string name, double x, double y)
{
	return Point(name, this->_x+x, this->_y+y);
}

Point::~Point()
{
	counter--;
}

void Point::fullPrint() const
{
	std::cout << _number << ". " << _name << " (" << _x << ", " << _y << ")" << std::endl;
}

void Point::changeName(std::string name)
{
	_name = name;
}