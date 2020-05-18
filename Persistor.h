#pragma once
#include "Filme.h"
#include <vector>
#include <string>

using namespace std;

class Persistor
{
	/* this class is an abstract class, I made this class to create the TXT, HTML and CSV class with inheritance */
private:
	vector <Film*> list;

public:
	virtual vector<Film*> getList() = 0;

	/* this function writes to the given file (depending from the class) */
	virtual void writeToTheFile() = 0;

	static int convertStringToInt(std::string string); // tested
};

class TXT : public Persistor
{
private:
	vector <Film*> list;

public:
	// getter
	vector<Film*> getList() override;

	// setter
	void setList(std::vector<Film*> list);

	// this function read from file
	void readFromFile();

	// this function writes to the file
	void writeToTheFile() override;
};

class CSV : public Persistor
{
private:
	vector <Film*> list;

public:
	// getter
	vector<Film*> getList() override;

	// setter
	void setList(std::vector<Film*> list);

	// this function writes to the file
	void writeToTheFile() override;
};


class HTML : public Persistor
{
private:
	vector <Film*> list;

public:
	// getter
	virtual vector<Film*> getList() override;

	// setter
	void setList(std::vector<Film*> filme);

	//void openHTML();

	// writes to the HTML file 
	void writeToTheFile() override;
};