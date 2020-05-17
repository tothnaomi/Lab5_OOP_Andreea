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

	virtual void writeToTheFile() = 0;

	static int convertStringToInt(std::string string); // tested
};

class TXT : public Persistor
{
private:
	vector <Film*> list;

public:
	vector<Film*> getList() override;

	void setList(std::vector<Film*> list);

	void readFromFile();

	void writeToTheFile() override;
};

class CSV : public Persistor
{
private:
	vector <Film*> list;

public:
	vector<Film*> getList() override;

	void setList(std::vector<Film*> list);

	void writeToTheFile() override;
};


class HTML : public Persistor
{
private:
	vector <Film*> list;

public:
	virtual vector<Film*> getList() override;

	void setList(std::vector<Film*> filme);

	//void openHTML();

	void writeToTheFile() override;
};