/**
* @file Point.hpp Header with definition of Point class
*/

#pragma once
#include <string>

/**
 * @class Point Point.hpp
 * @brief Represents a named and ordered point with given coordinates x, y
*/
class Point
{
private:
	/** name of the point */
	std::string _name;
	/** x coordinate */
	double _x;
	/** y coordinate */
	double _y;
	/** record number */
	int _number;

public:
	/** counter that helps number the objects*/
	static int counter;

	//CONSTRUCTORS
	/**
	 * @brief Default constructor of Point
	 * @param name Name of the point (empty string when not provided)
	 * @param x, y Coordinates (0 when not provided)
	*/
	Point(std::string name = "", double x = 0, double y = 0) : _x(x), _y(y), _name(name), _number(counter++ + 1) {};
	/**
	 * @brief Copy constructor of Point
	 * 
	 * It prints a communicate to std::cout informing which Object is being copied when called
	 * It increases counter and _number
	 * 
	 * @param old Object to be copied
	*/
	Point(const Point& old);
	/**
	 * @brief Move constructor of Point
	 * 
	 * It prints a communicate to std::cout informing which Object is being moved when called
	 * It increases counter and _number
	 * 
	 * @param old Object to be moved
	*/
	Point(Point&& old) noexcept;
	/**
	 * @brief Named constructor of Point
	 * 
	 * Creates a new Point with given coordinates
	 * 
	 * @param x, y Coordinates 
	*/
	static Point setPoint(double x, double y);
	/**
	 * @brief Named constructor of Point
	 * 
	 * Creates a new Point with opposite of given coordinates (-x, -y)
	 * 
	 * @param x, y Coordinates 
	*/
	static Point setContrary(double x, double y);
	/**
	 * @brief Named constructor of Point
	 * 
	 * When called on an object it returns a new object moved by x, y
	 * 
	 * @param name Name f the Point
	 * @param x, y Coordinates 
	*/
	Point newMoved(std::string name, double x, double y);


	//DESTRUCTOR
	/**
	 * @brief Destructor of Point
	 * 
	 * It decrements counter
	 * 
	*/
	~Point();


	//SETTERS & GETTERS
	/**
	 * @brief Changes name of Point (name setter)
	 * @param name New name
	*/
	void changeName(std::string name);


	//OTHER METHODS
	/**
	 * @brief Prints Point to std::cout
	 * 
	 * Point is printed as "number. name (x, y)"
	 * 
	*/
	void fullPrint() const;
};