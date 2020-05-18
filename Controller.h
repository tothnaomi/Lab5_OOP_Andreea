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

	/* deletes o movie from the list of movies */
	void deleteMovie(string, string, int);

	/* adds a movie to the list  of movies */
	void addMovie(string, string, int, int, string);

	/* these 5 functions update a movie in the list of movies */
	void updateTitel(string titel, string genre, int jahr, std::string newTitel);

	void updateGenre(string titel, string genre, int jahr, std::string newGenre);

	void updateJahr(string titel, string genre, int jahr, int newJahr);

	void updateLike(string titel, string genre, int jahr, int newLikes);

	void updateLink(string titel, string genre, int jahr, std::string newLink);

	/* this function returns a vector of movies with a given genre*/
	std::vector <Film*> alleFilmeMitEinGenre(std::string genre) const;

	/* this function prints all the elements from the controller */
	void printController() const;
};
