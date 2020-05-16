#include "Persistor.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<Film*> CSV::getList()
{
	return this->list;
}

void CSV::setList(std::vector<Film*> list)
{
	this->list = list;
}

void CSV::readFromFile()
{
	fstream myfile;
	myfile.open("informatii.csv", ios::in);
	string line;
	string newtitel, newgenre, newlink;
	int newjahr, newlike;
	vector <string> v;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			v.clear();
			stringstream ss(line);
			while (getline(ss, line, ','))
			{
				v.push_back(line);
			}
			newtitel = v[0];
			newgenre = v[1];
			newjahr = convertStringToInt(v[2]);
			newlike = convertStringToInt(v[3]);
			newlink = v[4];

			Film* newFilm = new Film(newtitel, newgenre, newjahr, newlike, newlink);
			this->list.push_back(newFilm);
		}
	}
	else
		cout << "Not opened";
}

void CSV::writeToTheFile()
{
	fstream myfile;
	myfile.open("informatii.csv", ios::out);
	for (auto film : this->list)
	{
		myfile << (*film).getTitel() << "," << (*film).getGenre() << "," << (*film).getJahr() << "," << (*film).getLike() << "," << (*film).getLink() << "\n";
	}
}

void CSV::createFile(string name)
{
	fstream file;
	file.open(name, ios::out | ios::app | ios::in);
}

void CSV::printAll()
{
	for (auto elem : this->list)
		cout << elem->getTitel() << ", " << elem->getGenre() << ", " << elem->getJahr() << ", " << elem->getLike() << ", " << elem->getLink() << endl;
}

int Persistor::convertStringToInt(std::string string)
{
	return stoi(string);
}
