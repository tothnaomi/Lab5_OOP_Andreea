#include "Watchlist.h"
#include "Error.h"

vector<Film*> Watchlist::getList() const
{
	return this->list;
}

void Watchlist::addMovie(Film* movie)
{
	if (this->inWatchlist(movie->getTitel(), movie->getGenre(), movie->getJahr()))
	{
		SchonExists err;
		throw err;
	}
	else
	{
		this->list.push_back(movie);
	}
}

void Watchlist::deleteMovie(string titel, string genre, int jahr)
{
	if (not this->inWatchlist(titel, genre, jahr))
	{
		NotExistsError err;
		throw err;
	}
	for (int i = 0; i < this->list.size(); i++)
	{
		if (this->list[i]->getGenre() == genre && this->list[i]->getTitel() == titel && this->list[i]->getJahr() == jahr)
		{
			this->list.erase(this->list.begin() + i);
			break;
		}
	}
}

bool Watchlist::inWatchlist(string titel, string genre, int jahr)
{
	for (auto elem : this->list)
	{
		if (elem->getGenre() == genre && elem->getTitel() == titel && elem->getJahr() == jahr)
			return true;
	}
	return false;
}

void Watchlist::seeWatchlist()
{
	for (auto elem : this->list)
	{
		cout << elem->getTitel() << ", " << elem->getGenre() << ", " << elem->getJahr() << ", " << elem->getLike() << ", " << elem->getLink() << endl;

	}
}
