#pragma once
#include "Filme.h"
#include "Error.h"
#include <vector>
#include <string>
#include <iostream>


class Repo
{
private:
	std::vector <Film> listOfMovies;

	/* returns the position of the object or -1 if the object is not in the list */
	int search(std::string titel, std::string genre, int jahr);

public:
	
	/* nu am putut sa o fac privat pentru ca am nevoie de functie cand imi fac testele! */
	std::vector <Film> get_list() const;

	/* this function deletes a movie from the repo
	ONLY FOR THE ADMIN */
	void loschen(std::string titel, std::string genre, int jahr);


	Film* search_movie(std::string titel, std::string genre, int jahr);

	/* changes the titel of the movie given as parameter */
	void bearbeiten_titel(std::string titel, std::string genre, int jahr, std::string new_titel);

	/* changes the genre of the movie given as parameter */
	void bearbeiten_genre(std::string titel, std::string genre, int jahr, std::string new_genre);

	/* changes the year of the movie given as parameter */
	void bearbeiten_erscheinungsjahr(std::string titel, std::string genre, int jahr, int new_year);

	/* changes the likes of the movie given as parameter */
	void bearbeiten_likes(std::string titel, std::string genre, int jahr, int new_likes);

	/* changes the link of the movie given as parameter */
	void bearbeiten_link(std::string titel, std::string genre, int jahr, std::string new_link);

	/* prints all the movies from the repo (application) */
	void print_all_movies();

	/* prints all the movies from the repo (application), which have a specific genre */
	std::vector<Film> print_all_movies(std::string genre);// get_all_movies -> fara cout si cin

	void hunfugen(Film film);
};

