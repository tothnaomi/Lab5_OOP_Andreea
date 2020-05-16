#pragma once
#include <string>
#include "Repository.h"
#include "Error.h"
#include <iostream>
using namespace std;

class Controller
{
private:
	Repo* repo;

public:
	Controller(Repo* newRepo);

	Repo getRepositry() const;

	/* for the admin */
	void deleteMovie(string, string, int);

	void addMovie(string, string, int, int, string);

	void updateTitel(string titel, string genre, int jahr, std::string newTitel);

	void updateGenre(string titel, string genre, int jahr, std::string newGenre);

	void updateJahr(string titel, string genre, int jahr, int newJahr);

	void updateLike(string titel, string genre, int jahr, int newLikes);

	void updateLink(string titel, string genre, int jahr, std::string newLink);

	std::vector <Film*> alleFilmeMitEinGenre(std::string genre) const;

	void printController() const;
};
