//Rectangle
#pragma once
#include "Point.h"
#include <iostream>
#include<string>
const int COUNT_OF_SIDES = 4;

class Rectangle
{
public:
	Rectangle() = default;
	Rectangle(Point* cords);
	~Rectangle() = default;

	void Move(const char route, const int scale);
	int Area() const;
	Rectangle& BuildRectangle(const Rectangle& rec1, const Rectangle& rec2) const;
	std::string TableOfPoints() const;


private:
	Point _cords[COUNT_OF_SIDES];
	int GetLength(const Point& point1, const Point& point2) const;
	bool RightRec() const;
	void Copy(const Point* cords);
};