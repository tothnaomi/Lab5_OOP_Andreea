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

vector<Film*> TXT::getList()
{
	return this->list;
}

void TXT::setList(std::vector<Film*> list)
{
	this->list = list;
}

void TXT::readFromFile()
{
	ifstream myfile;
	myfile.open("informatii.txt", ios::in);
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
			//cout << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ", " << v[4] << endl;

			Film* newFilm = new Film(newtitel, newgenre, newjahr, newlike, newlink);
			this->list.push_back(newFilm);
		}
	}
	else
		cout << "Not opened";
}

void TXT::createFile(string name)
{
}

void TXT::writeToTheFile()
{
	fstream myfile;
	myfile.open("informatii.txt", ios::out);
	for (auto film : this->list)
	{
		myfile << (*film).getTitel() << "," << (*film).getGenre() << "," << (*film).getJahr() << "," << (*film).getLike() << "," << (*film).getLink() << "," << "\n";
	}
}


vector<Film*> HTML::getList()
{
	return this->list;
}

void HTML::setList(std::vector<Film*> filme)
{
	this->list = filme;
}

void HTML::createFile(string name)
{
	fstream html;
	html.open(name);
}

void HTML::readFromFile()
{
}

void HTML::openHTML()
{
	string str = "start informatii.html";;
	system(str.c_str());
}

void HTML::writeToTheFile()
{
	ofstream html;
	html.open("informatii.html", ofstream::out || ofstream::trunc);

	//header
	ifstream file("header.html");
	string str;
	while (getline(file, str))
		html << str << '\n';
	file.close();

	for (auto m : this->list)
	{
		html << "<tr><td>" << m->getTitel() << "</td><td>" << m->getGenre() << "</td><td>" << m->getJahr() << "</td><td>" << m->getLike() << "</td><td><a href =" << m->getLink() << ">Link</a></td></tr>";
	}

	// footer
	ifstream file2("footer.html");
	while (getline(file2, str))
		html << str << '\n';
	file2.close();

	html.close();
}
