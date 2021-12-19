#pragma once
#include <iostream>
#include "Interface.h"
#define COUNT_OF_CASES 3	
using std::logic_error;

Interface::Interface()
{
	_names = new std::string[COUNT_OF_CASES];
	_cases = new Rectangle[COUNT_OF_CASES];
}

Interface::~Interface()
{
	delete[] _names;
	delete[] _cases;
}


void Interface::CalculateArea() const
{
	std::string name;
	std::cout << "Enter name of rectangle to calculate area: ";

	std::cin >> name;
	int index = GetIndex(name);

	if (index == -1)
	{
		std::cout << "Can't find rectangle with this name\n";
	}
	else
	{
		int area = _cases[index].Area();
		std::cout << "Thea area of rectagnel is: ";
		std::cout << area<<"\n";
	}

}

int Interface::GetIndex(const std::string name) const
{
	for (int i = 0; i < COUNT_OF_CASES; i++)
	{
		if (name == _names[i])
		{
			return i;
		}
	}
	return -1;
}

void Interface::MoveRectangle()const
{
	std::string name;
	std::cout<<"Enter name of rectangle to move: ";

	std::cin >> name;
	int index = GetIndex(name);

	char route;
	int scale;

	if (index == -1)
	{
		std::cout << "Can't find rectangle with this name\n";
	}
	else
	{
		std::cout << "Choose your route and scale\n";
		std::cout << "r - move to the right\nl - move to the left\nd - move to the down\nu - move to the up\n";
		std::cout << "Route: ";
		std::cin >> route;
		std::cout << "Scale: ";
		std::cin >> scale;
		std::cout << "\n";

		_cases[index].Move(route, scale);
	}
	


}

void Interface::PrintAllRectangles()const
{
	for (int i = 0; i < COUNT_OF_CASES; i++)
	{
		if (_names[i].empty())
		{
			std::cout << "Rectangle " << i + 1 << "\n";
			std::cout << "Is empty\n\n";
		}
		else
		{
			std::cout << "Rectangle " << i + 1 << "\n";
			std::cout << "Name: " << _names[i] << "\n";
			std::cout << _cases[i].TableOfPoints()<<"\n\n";
		}
	}
}

void Interface::PrintRectangle() const
{
	std::cout << "Enter name of rectangle to print: ";

	std::string name;
	std::cin >> name;

	int index = GetIndex(name);

	if (index == -1)
	{
		std::cout << "Can't find rectangle with this name\n";
	}
	else
	{
		std::cout << "Name of rectangle:" << name << "\n";
		std::cout << _cases[index].TableOfPoints();
	}


}

void Interface::DelRectangle() const
{
	std::string choice;
	std::string name;

	std::cout << "Enter name of rectangle to delete\n>> ";
	std::cin >> name;
	int index = GetIndex(name);

	if (index == -1)
	{
		std::cout << "Can't find rectangle with this name\n";
	}
	else
	{
		std::cout << "Are you sure?Y|N\n";
		std::cin >> choice;

		if (choice == "Y" || choice == "y")
		{
			_names[index] = "";
			std::cout << "Complete\n";

		}

		if (choice == "N" || choice == "n")
		{
			std::cout << "Okay\n";
		}
		if((choice != "Y" && choice !="y") && (choice != "N" && choice != "n"))
		{
			std::cout << choice << " is not a 'y' or 'n'\n";
		}
	}
	
}

void Interface::Build() const
{
	std::string name;
	std::string name1;
	int arg;
	std::cout << "Enter name of first rectangle: ";
	std::cin >> name;
	std::cout << "Enter name of second rectangle: ";
	std::cin >> name1;
	if (GetIndex(name) != -1 && GetIndex(name1) != -1)
	{
		Point* cords = new Point[COUNT_OF_SIDES];
		std::string name2; bool isEnoughtSpace = false; int index;
		std::cout << "Enter name of new build rectangle: ";
		std::cin >> name2;

		for (int i = 0; i < COUNT_OF_CASES; i++)
		{
			if (_names[i].empty())
			{
				isEnoughtSpace = true;
				index = i;
			}
		}

		if (isEnoughtSpace)
		{
			Rectangle temp;
			try
			{
				temp = temp.BuildRectangle(_cases[GetIndex(name)], _cases[GetIndex(name1)]);
			}
			catch (const std::logic_error& error)
			{
				std::cout << error.what();
				return;
			}
			_names[index] = name2;
			_cases[index] = temp;
		}
		else
		{
			std::cout << "You don't have enought space, if you want delete something press '1', else press '2'\n";
			int choice = 0;
			std::cin >> choice;
			if (choice == 1)
			{
				DelRectangle();
				Rectangle temp;
				try
				{
					temp = temp.BuildRectangle(_cases[GetIndex(name)], _cases[GetIndex(name1)]);
				}
				catch (const std::logic_error& error)
				{
					std::cout << error.what();
					return;
				}
				_names[index] = name2;
				_cases[index] = temp;
			}
			if (choice == 2)
			{
				std::cout << "Okay\n";
			}
			else
			{
				std::cout << "It is not 1 or 2\n";
			}
		}

		delete[] cords;
	}
	else
	{
		std::cout << "Wrong name\n";
	}

}

void Interface::Createrectangle() const
{
	Point *_cords = new Point[COUNT_OF_SIDES];

	std::string name; bool isEnoughtSpace = false; int index;

	std::cout << "Write down your point`s\n";
	std::cout << "Enter cords (x,y)\n1------2\n-      -\n-      -\n-      -\n4------3\n";

	for (int i = 0; i < COUNT_OF_SIDES; i++)
	{
		std::cin >> _cords[i].x >> _cords[i].y;
	}

	std::cout << "Write down name of rectangle: ";
	std::cin >> name;

	for (int i = 0; i < COUNT_OF_CASES; i++)
	{
		if (_names[i].empty())
		{
			isEnoughtSpace = true;
			index = i;
			break;
		}
	}
	
	if (isEnoughtSpace)
	{
		try
		{
			Rectangle temp(_cords);
			_names[index] = name;
			_cases[index] = temp;
			std::cout << "Complete\n";
		}
		catch (const std::logic_error& error)
		{
			std::cout << error.what() << "\n";
		}

	}
	else
	{
		std::cout << "You don't have enought space, if you want delete something press '1', else press '2'\n";
		int choice = 0;
		std::cin >> choice;
		if (choice == 1)
		{
			DelRectangle();
			try
			{
				Rectangle temp(_cords);
				_names[index] = name;
				_cases[index] = temp;
				std::cout << "Complete\n";
			}
			catch (const std::logic_error& err)
			{
				std::cout << err.what() << "\n";
			}

		}
		if (choice == 2)
		{
			std::cout << "Okay\n";
		}
		else
		{
			std::cout << "It is not 1 or 2\n";
		}
	}

}

void Interface::Init() const
{
	std::cout << "You can save 3 rectangle in memory\n";

	int code, arg; std::string name, name2;
	bool fl = true;
	while (fl)
	{
		std::cout << "Enter \"1\" - Help\n";
		std::cout << ">> ";
		std::cin >> code;

		switch (code)
		{
		case 1:
			Help();
			break;

		case 2:
			Createrectangle();
			break;

		case 3:
			DelRectangle();
			break;

		case 4:
			MoveRectangle();
			break;

		case 5:
			Build();
			break;

		case 6:
			CalculateArea();
			break;
		
		case 7:
			PrintAllRectangles();
			break;

		case 8:
			PrintRectangle();
			break;

		case 0:
			fl = false;
			break;

		default:
			std::cout << "Wrong command\n";
			break;
		}
	}
}

void Interface::Help() const
{
	std::cout << "\"1\" - Call help\n\"2\" - Create rectangle\n\"3\" - Delete rectangle\n\"4\" - Move rectangle\n\"5\" - Build new rectangle\n\"6\" - Area\n\"7\" - Print all rectangles\n\"8\" - Print rectangle by the name\n\"0\" - Exit\n";
}

