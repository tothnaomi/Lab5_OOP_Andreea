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

	// trebuie sa facem cumva legatura intre repository si Watchlist ca sa adaugam in Watchlist aceeasi pointer cu un film, ca
	// si in repository 
	// cautam in meniu cu repo.searchMovie(titlu, gen, an) si adaugam pointerul respectiv
	void addMovie(Film* movie);

	void deleteMovie(string titel, string genre, int jahr);

	bool inWatchlist(string titel, string genre, int jahr);

	void seeWatchlist();
};
