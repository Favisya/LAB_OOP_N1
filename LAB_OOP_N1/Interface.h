//Interface
#pragma once
#include "Rectangle.h"

class Interface
{
public:
	Interface();
	~Interface();
	
	void Init() const;

private:
	void Help() const;
	int GetIndex(const std::string name) const;
	void CalculateArea() const;
	void Createrectangle() const;
	void DelRectangle() const;
	void MoveRectangle() const;
	void PrintAllRectangles() const;
	void PrintRectangle() const;
	void StrinOfPoints() const;
	void Build() const;
	std::string* _names = nullptr;
	Rectangle* _cases = nullptr;
};