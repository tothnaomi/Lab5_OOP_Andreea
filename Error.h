#pragma once
#include <iostream>
using namespace std;

class Error
{
public:
	virtual void printError() = 0;
};

class NotExistsError : Error
{
public:
	void printError() override { std::cout << "This object does not exist!" << endl; }
};

/*class FalseParameter : Error
{
public:
	void printError() override { std::cout << "The given parameter is not ok!" << endl; }
};

class DivisionByNull : Error
{
	void printError() override { std::cout << "Division by null error!" << endl; }
};*/

class SchonExists : Error
{
public:
	void printError() override { std::cout << "This object is already in the list!" << endl; }
};