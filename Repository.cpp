#include "Repository.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


Repo::Repo(std::vector<Film*> movies)
{
	this->liste = movies;
}

std::vector<Film*> Repo::getVektor() const
{
	return this->liste;
}

template<typename Param, typename Func>
inline void Repo::update(string titel, string genre, int jahr, Param param, Func lambdaFunc)
{
	if (this->searchMovie(titel, genre, jahr) == nullptr)
	{
		// exceptia respectiva din clasa mea de exceptii
		NotExistsError err;
		throw err;
	}
	else
	{
		lambdaFunc(titel, genre, jahr, param);
	}
}


Film* Repo::makePointer(std::string titel, std::string genre, int jahr, int likes, std::string link)
{
	Film* newFilm = new Film(titel, genre, jahr, likes, link);
	return newFilm;
}

bool Repo::operator==(Repo other)
{
	if (this->liste.size() == other.liste.size())
	{
		for (int i = 0; i < this->liste.size(); i++)
		{
			if (this->liste[i] != other.liste[i])
				return false;
		}
	}
	else
		return false;
	return true;
}

void Repo::addFilm(string titel, string genre, int jahr, int likes, string link)
{
	/* we have to verify if the movie is already in the list or not */
	if (this->searchMovie(titel, genre, jahr) == nullptr)
	{
		Film* movie = this->makePointer(titel, genre, jahr, likes, link);
		this->liste.push_back(movie);
	}
}

void Repo::deleteMovie(string titel, string genre, int jahr)
{
	Film* deletedMovie = this->searchMovie(titel, genre, jahr);
	if (deletedMovie == nullptr)
	{
		NotExistsError err;
		throw err;
	}
	else
	{
		for (int i = 0; i < this->liste.size(); i++)
		{
			if (this->liste[i]->getTitel() == titel && this->liste[i]->getGenre() == genre && this->liste[i]->getJahr() == jahr)
			{
				delete (this->liste)[i];
				this->liste.erase(this->liste.begin() + i);
			}
		}
	}
}

Film* Repo::searchMovie(string titel, string genre, int jahr)
{
	for (auto film : this->liste)
	{
		if ((*film).getTitel() == titel && (*film).getGenre() == genre && (*film).getJahr() == jahr)
			return film;

	}
	return nullptr;
}

void Repo::updateTitel(string titel, string genre, int jahr, std::string newTitel)
{
	this->update(titel, genre, jahr, newTitel, [this](string titel, string genre, int jahr, std::string newTitel) {Film* movie = this->searchMovie(titel, genre, jahr);  movie->setTitel(newTitel); });
}

void Repo::updateGenre(string titel, string genre, int jahr, std::string newGenre)
{
	this->update(titel, genre, jahr, newGenre, [this](string titel, string genre, int jahr, std::string newGenre) {Film* movie = this->searchMovie(titel, genre, jahr);  movie->setGenre(newGenre); });
}

void Repo::updateJahr(string titel, string genre, int jahr, int newJahr)
{
	this->update(titel, genre, jahr, newJahr, [this](string titel, string genre, int jahr, int newJahr) {Film* movie = this->searchMovie(titel, genre, jahr);  movie->setJahr(newJahr); });
}

void Repo::updateLike(string titel, string genre, int jahr, int newLikes)
{
	this->update(titel, genre, jahr, newLikes, [this](string titel, string genre, int jahr, int newLikes) {Film* movie = this->searchMovie(titel, genre, jahr);  movie->setLike(newLikes); });
}

void Repo::updateLink(string titel, string genre, int jahr, std::string newLink)
{
	this->update(titel, genre, jahr, newLink, [this](string titel, string genre, int jahr, std::string newLink) {Film* movie = this->searchMovie(titel, genre, jahr);  movie->setLink(newLink); });
}
