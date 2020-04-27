#pragma once
#include <vector>
#include "Filme.h"
#include <string>

class Watchtrailer
{private:

	std::vector <Film> list_trailer;
	std::vector <Film> list;

public:
	std::vector<Film> get_list_trailer() const;

	/* if the user likes the trailer, add movie to watchlist */
	void insert_wenn_trailer_magt(Film film);

	/* if the user doesn't like the trailer, go to next trailer */
	void next_trailer(Film film);
};

