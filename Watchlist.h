#pragma once
#include <vector>
#include "Filme.h"
#include <iostream>

using namespace std;

class Watchlist
{
private:
	vector <Film*> list;

public:
	vector <Film*> getList() const;

	// this function adds a movie to the watchlist, if the movie is not in the repository
	// if the movie is already in the watchlist it will throw an exception from MyException class
	void addMovie(Film* movie);

	//this function deletes a movie to the watchlist
	// if the movie is not in the watchlist it will throw an exception 
	void deleteMovie(string titel, string genre, int jahr);

	// this function searches for a given movie
	// if the movie is in the watchlist it will return true, else false
	bool inWatchlist(string titel, string genre, int jahr);

	// prints all the movies from the watchlist
	void seeWatchlist();
};
