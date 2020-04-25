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
}; 
