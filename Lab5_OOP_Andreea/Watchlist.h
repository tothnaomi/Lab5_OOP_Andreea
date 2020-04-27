#pragma once
#include <vector>
#include "Filme.h"
#include <string>

class Watchlist
{
private:
	std::vector <Film> list;

public:

	/* getter */
	std::vector <Film> get_list() const;

	/* adding an element to the watchlist */
	void hinfugen(Film film);

	/* deleting elemnt from watchlist */
	void loschen(Film film);

	/* if the user likes the trailer, add movie to watchlist 
	void insert_wenn_trailer_magt(Film film);

	if the user doesn't like the trailer, go to next trailer 
	void next_trailer(Film film); */

	/* see the user's watchlist */
	void see_watchlist(Film film);
}; 
