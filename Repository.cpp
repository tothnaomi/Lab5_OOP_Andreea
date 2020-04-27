#include "Repository.h"
#include <iostream>
#include "Error.h"

std::vector<Film> Repo::get_list() const
{
	return this->listOfMovies;
}

int Repo::search(std::string titel, std::string genre, int jahr)
{
	if (this->listOfMovies.size() == 0)
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < this->listOfMovies.size(); i++)
		{
			if (this->listOfMovies[i].get_titel() == titel && this->listOfMovies[i].get_genre() == genre && this->listOfMovies[i].get_erscheinungsjahr() == jahr)
				return i;
		}
		return -1;
	}
}

Film* Repo::search_movie(std::string titel, std::string genre, int jahr)
{
	return nullptr;
}


void Repo::loschen(std::string titel, std::string genre, int jahr)
{
	int n = this->search(titel, genre, jahr);
	if (n != -1)
	{
		listOfMovies.erase(listOfMovies.begin() + n);
	}
}

void Repo::bearbeiten_titel(std::string titel, std::string genre, int jahr, std::string new_titel)
{
	if (this->search(titel, genre, jahr) != -1)
	{
		int n = this->search(titel, genre, jahr);
		this->listOfMovies[n].set_titel(new_titel);
	}
}

void Repo::bearbeiten_genre(std::string titel, std::string genre, int jahr, std::string new_genre)
{
	if (this->search(titel, genre, jahr) != -1)
	{
		int n = this->search(titel, genre, jahr);
		this->listOfMovies[n].set_genre(new_genre);
	}
}

void Repo::bearbeiten_erscheinungsjahr(std::string titel, std::string genre, int jahr, int new_year)
{
	int n = this->search(titel, genre, jahr);
	if (n != -1)
	{
		this->listOfMovies[n].set_erscheinungsjahr(new_year);
	}
	/*else
	{
		Error err = Error();
		throw err;
	}
	*/
}

void Repo::bearbeiten_likes(std::string titel, std::string genre, int jahr, int new_likes)
{
	int n = this->search(titel, genre, jahr);
	if (n != -1)
	{
		this->listOfMovies[n].set_likes(new_likes);
	}
	/*else
	{
		Error err = Error();
		throw err;
	}
	*/
}

void Repo::bearbeiten_link(std::string titel, std::string genre, int jahr, std::string new_link)
{
	int n = this->search(titel, genre, jahr);
	if (n != -1)
	{
		this->listOfMovies[n].set_link(new_link);
	}
	/*else
	{
		Error err = Error();
		throw err;
	}*/
}

void Repo::print_all_movies()
{
	for (auto film : this->listOfMovies)
	{
		film.print_movie();
	}
	std::cout << std::endl;
}

std::vector<Film> Repo::print_all_movies(std::string genre)
{
	std::vector<Film> filme_genre;
	for (auto film : this->listOfMovies)
	{
		if (film.get_genre() == genre)
		{
			filme_genre.push_back(film);
		}
	}
	return filme_genre;
}

void Repo::hunfugen(Film film)
{
	/* we have to verify if the movie is already in the list or not */
	if (this->search_movie(film.get_titel(), film.get_genre(), film.get_erscheinungsjahr()) == nullptr) this->listOfMovies.push_back(film);
}
