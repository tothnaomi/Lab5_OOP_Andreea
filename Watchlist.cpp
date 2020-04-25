#include "Watchlist.h"
#include <iostream>

std::vector<Film> Watchlist::get_list() const
{
	return this->list;
}

void Watchlist::hinfugen(Film film)
{
	this->list.push_back(film);
}
