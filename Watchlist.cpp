#include "Watchlist.h"
#include "Watchtrailer.h"
#include "Filme.h"
#include "Repository.h"
#include "Error.h"
#include <iostream>

std::vector<Film> Watchlist::get_list() const
{
	return this->list;
}

void Watchlist::hinfugen(Film film)
{
	this->list.push_back(film);
}

void Watchlist::loschen(Film film)
{
	list.erase(list.begin() + 1);
}


void Watchlist::see_watchlist(Film film)
{
	std::vector<Film> get_list();
}

bool Watchlist::in_watchlist(std::string titel, std::string genre, int jahr)
{
	for (int i = 0; i < this->get_list().size(); i++)
	{
		if (this->list[i].get_titel() == titel && this->list[i].get_genre() == genre && this->list[i].get_erscheinungsjahr() == jahr)
			return true;
	}
	return false;
}



