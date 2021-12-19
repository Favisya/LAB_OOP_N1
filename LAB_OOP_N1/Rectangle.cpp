#pragma once
#include "Rectangle.h"
#include <cstring>
#include <iostream>
using std::logic_error;

Rectangle::Rectangle(Point* cords)
{
	(*this).Copy(cords);

	if (!RightRec())
	{
		throw std::logic_error("NON-EXISTING RECTANGLE");
	}
}

std::string Rectangle::TableOfPoints() const
{
	std::string Rectangle = "";
	for (int i = 0; i < COUNT_OF_SIDES; i++)
	{
		Rectangle += "Point";
		Rectangle += '"';
		Rectangle += std::to_string(i + 1);
		Rectangle += '"';
		Rectangle += " - (";
		Rectangle += std::to_string(_cords[i].x);
		Rectangle += ',';
		Rectangle += std::to_string(_cords[i].y);
		Rectangle += ")\n";
	}
	return Rectangle;
}

Rectangle& Rectangle::BuildRectangle(const Rectangle& rec1, const Rectangle& rec2) const
{
	Rectangle rec3;

	if ((rec1._cords[0].x >= rec2._cords[1].x) || (rec1._cords[1].x <= rec2._cords[0].x) || (rec1._cords[0].y <= rec2._cords[3].y) || (rec1._cords[3].y >= rec2._cords[0].y))//íå ïåðåñåêàþòñÿ
	{
		throw std::logic_error("DISJOINT RECTANGLES");
	}

	else if ((rec1._cords[0].x < rec2._cords[1].x) && (rec1._cords[2].x >= rec2._cords[2].x))//left
	{
		rec3._cords[0].x = rec1._cords[0].x;
		rec3._cords[3].x = rec1._cords[0].x;
		rec3._cords[2].x = rec2._cords[2].x;
		rec3._cords[1].x = rec2._cords[2].x;

		if (rec1._cords[0].y <= rec2._cords[0].y)
		{
			rec3._cords[0].y = rec1._cords[0].y;
			rec3._cords[1].y = rec1._cords[0].y;

			if (rec1._cords[3].y <= rec2._cords[3].y)
			{
				rec3._cords[2].y = rec2._cords[3].y;
				rec3._cords[3].y = rec2._cords[3].y;
			}
			else
			{
				rec3._cords[2].y = rec1._cords[3].y;
				rec3._cords[3].y = rec1._cords[3].y;
			}

		}
		else
		{
			rec3._cords[0].y = rec2._cords[0].y;
			rec3._cords[1].y = rec2._cords[0].y;

			if (rec1._cords[3].y <= rec2._cords[3].y)
			{
				rec3._cords[2].y = rec2._cords[3].y;
				rec3._cords[3].y = rec2._cords[3].y;
			}
			else
			{
				rec3._cords[2].y = rec1._cords[3].y;
				rec3._cords[3].y = rec1._cords[3].y;
			}
		}
		return rec3;
	}
	else if ((rec1._cords[1].x > rec2._cords[0].x) && (rec1._cords[0].x <= rec2._cords[0].x))//right
	{
		rec3._cords[0].x = rec2._cords[0].x;
		rec3._cords[3].x = rec2._cords[0].x;
		rec3._cords[2].x = rec1._cords[1].x;
		rec3._cords[1].x = rec1._cords[1].x;

		if (rec1._cords[0].y <= rec2._cords[0].y)
		{
			rec3._cords[0].y = rec1._cords[0].y;
			rec3._cords[1].y = rec1._cords[0].y;

			if (rec1._cords[3].y <= rec2._cords[3].y)
			{
				rec3._cords[2].y = rec2._cords[3].y;
				rec3._cords[3].y = rec2._cords[3].y;
			}
			else
			{
				rec3._cords[2].y = rec1._cords[3].y;
				rec3._cords[3].y = rec1._cords[3].y;
			}

		}
		else
		{
			rec3._cords[0].y = rec2._cords[0].y;
			rec3._cords[1].y = rec2._cords[0].y;

			if (rec1._cords[3].y <= rec2._cords[3].y)
			{
				rec3._cords[2].y = rec2._cords[3].y;
				rec3._cords[3].y = rec2._cords[3].y;
			}
			else
			{
				rec3._cords[2].y = rec1._cords[3].y;
				rec3._cords[3].y = rec1._cords[3].y;
			}
		}
		return rec3;
	}
	else if ((rec1._cords[0].y >= rec2._cords[3].y) && (rec2._cords[0].y >= rec1._cords[0].y))//top
	{
		rec3._cords[0].y = rec1._cords[0].y;
		rec3._cords[1].y = rec1._cords[0].y;
		rec3._cords[2].y = rec2._cords[3].y;
		rec3._cords[3].y = rec2._cords[3].y;

		if (rec1._cords[0].x <= rec2._cords[0].x)
		{
			rec3._cords[0].x = rec1._cords[0].x;
			rec3._cords[3].x = rec1._cords[0].x;
		}
		if (rec1._cords[0].x > rec2._cords[0].x)
		{
			rec3._cords[0].x = rec2._cords[0].x;
			rec3._cords[3].x = rec2._cords[0].x;
		}
		if (rec1._cords[1].x <= rec2._cords[1].x)
		{
			rec3._cords[2].x = rec1._cords[2].x;
			rec3._cords[1].x = rec1._cords[2].x;
		}
		if (rec1._cords[1].x > rec2._cords[1].x)
		{
			rec3._cords[2].x = rec2._cords[2].x;
			rec3._cords[1].x = rec2._cords[2].x;
		}
		return rec3;
	}
	else if ((rec1._cords[3].y <= rec2._cords[1].y) && (rec1._cords[0].y >= rec2._cords[0].y))//bot
	{
		rec3._cords[0].y = rec2._cords[0].y;
		rec3._cords[1].y = rec2._cords[0].y;
		rec3._cords[2].y = rec1._cords[3].y;
		rec3._cords[3].y = rec1._cords[3].y;
		if (rec1._cords[0].x <= rec2._cords[0].x)
		{
			rec3._cords[0].x = rec1._cords[0].x;
			rec3._cords[3].x = rec1._cords[0].x;
		}
		if (rec1._cords[0].x > rec2._cords[0].x)
		{
			rec3._cords[0].x = rec2._cords[0].x;
			rec3._cords[3].x = rec2._cords[0].x;
		}
		if (rec1._cords[1].x <= rec2._cords[1].x)
		{
			rec3._cords[2].x = rec1._cords[2].x;
			rec3._cords[1].x = rec1._cords[2].x;
		}
		if (rec1._cords[1].x > rec2._cords[1].x)
		{
			rec3._cords[2].x = rec2._cords[2].x;
			rec3._cords[1].x = rec2._cords[2].x;
		}
		return rec3;
	}
	else if ((rec1._cords[0].x >= rec2._cords[0].x) && (rec1._cords[1].x <= rec2._cords[1].x) && (rec1._cords[0].y <= rec2._cords[0].y) && (rec1._cords[3].y >= rec2._cords[3].y))
	{
		for (int i = 0; i < COUNT_OF_SIDES; i++)
		{
			rec3._cords[i].x = rec1._cords[i].x;
			rec3._cords[i].y = rec1._cords[i].y;
		}
		return rec3;
	}
	else if ((rec1._cords[0].x <= rec2._cords[0].x) && (rec1._cords[1].x >= rec2._cords[1].x) && (rec1._cords[0].y >= rec2._cords[0].y) && (rec1._cords[3].y <= rec2._cords[3].y))
	{
		for (int i = 0; i < COUNT_OF_SIDES; i++)
		{
			rec3._cords[i].x = rec2._cords[i].x;
			rec3._cords[i].y = rec2._cords[i].y;
		}
		return rec3;
	}
}

bool Rectangle::RightRec() const
{
	int side1 = GetLength(_cords[0], _cords[1]);
	int side2 = GetLength(_cords[3], _cords[2]);
	int side3 = GetLength(_cords[0], _cords[3]);
	int side4 = GetLength(_cords[1], _cords[2]);

	if (side1 == side2 && side3 == side4 && side1 != 0)  //(_cords[0])
	{
		return true;
	}
	else
	{
		return false;
	}

}

int Rectangle::GetLength(const Point& point1, const Point& point2) const
{
	return abs(point1.x - point2.x) + abs(point1.y - point2.y);
}

int Rectangle::Area() const
{
	return GetLength(_cords[0], _cords[1]) * GetLength(_cords[1], _cords[2]);
}


void Rectangle::Copy(const Point* cords)
{
	memcpy(_cords, cords, COUNT_OF_SIDES * sizeof(Point));
}

void Rectangle::Move(const char route, const int scale)
{
	switch (route)
	{
	case 'r':
		for (int i = 0; i < COUNT_OF_SIDES; i++)
		{
			_cords[i].x += scale;
		}
		break;
	case 'l':
		for (int i = 0; i < COUNT_OF_SIDES; i++)
		{
			_cords[i].x -= scale;
		}
		break;
	case 'd':
		for (int i = 0; i < COUNT_OF_SIDES; i++)
		{
			_cords[i].y -= scale;
		}
		break;
	case'u':
		for (int i = 0; i < COUNT_OF_SIDES; i++)
		{
			_cords[i].y += scale;
		}
		break;
	}
}

