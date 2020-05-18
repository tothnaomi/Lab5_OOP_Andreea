#pragma once
#include "Error.h"
#include <vector>
#include "Filme.h"
#include <sstream>
using namespace std;

class Repo
{
	/* CRUD: create, read, update, delete */
private:
	vector<Film*> liste;

	template <typename Param, typename Func>
	void update(string titel, string genre, int jahr, Param param, Func lambdaFunc);

public:
	// constructor
	Repo(std::vector <Film*> movies);

	// this function adds a movie if it is not already in the list of movies, else throws an exception from MyException class
	void addFilm(string, string, int, int, string); // tested

	// this function deletes a movie if it is already in the list of movies, else throws an exception from MyException class
	void deleteMovie(string titel, string genre, int jahr);

	// returns a pointer of a movie from the list of movies, if the given movie is not in the list of movies it will return the nullptr
	Film* searchMovie(string titel, string genre, int jahr); // tested

	// these 5 functions update a movie given as parameter 
	void updateTitel(string titel, string genre, int jahr, std::string newTitel);

	void updateGenre(string titel, string genre, int jahr, std::string newGenre);

	void updateJahr(string titel, string genre, int jahr, int newJahr);

	void updateLike(string titel, string genre, int jahr, int newLikes);

	void updateLink(string titel, string genre, int jahr, std::string newLink);

	// this function creates a pointer for the add function
	Film* createFilmPtr(std::string titel, std::string genre, int jahr, int likes, std::string link);

	// getter
	std::vector<Film*> getVektor() const; 

	// operator overload 
	bool operator==(Repo other);
};

