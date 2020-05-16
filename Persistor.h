#pragma once
#include "Filme.h"
#include <vector>
#include <string>

using namespace std;

class Persistor
{
private:
	vector <Film*> list;

public:
	virtual vector<Film*> getList() = 0;

	virtual void createFile(string name) = 0;

	virtual void readFromFile() = 0;

	virtual void writeToTheFile() = 0;

	static int convertStringToInt(std::string string); // tested
};

class CSV : public Persistor
{
private:
	vector <Film*> list;

public:
	vector<Film*> getList() override;

	void setList(std::vector<Film*> list);

	void readFromFile() override;

	void writeToTheFile() override;

	void createFile(string name) override;

	void printAll();
};


class HTML : public Persistor
{
private:
	vector <Film*> list;

public:

	void readFromFile() override;

	void writeToTheFile() override;
}; 
