#include "Watchtrailer.h"
#include "Watchlist.h"
#include "Filme.h"
#include <iterator>
#include "Repository.h"
#include "Error.h"
#include <iostream>
#include <vector>

std::vector<Film> Watchtrailer::get_list_trailer() const
{
	return this->list_trailer;
	return this->list;
}

void Watchtrailer::insert_wenn_trailer_magt(Film film)
{
	std::vector<Film> get_titel();

	this->list.push_back(film);

}

void Watchtrailer::next_trailer(Film film)
{
	
	this->list_trailer.push_back(film);

}
