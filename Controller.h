#pragma once
#include "Repository.h"
#include "Error.h"
#include <iostream>

class Controller
{
private:
	Repo* repo;

public:

	void set_repo(Repo* repo);

	Repo* get_repo() const;

	/* this function adds a new movie to the list of movies (in repo)
	ONLY FOR THE ADMIN. */
	void hinfugen(Film film);

	/* deletes a movie from the list of movies */
	void loschen(std::string titel, std::string genre, int jahr);

	/* changes something in a given movie */
	void bearbeiten_titel(std::string titel, std::string genre, int jahr, std::string new_titel);
	void bearbeiten_genre(std::string titel, std::string genre, int jahr, std::string new_genre);
	void bearbeiten_year(std::string titel, std::string genre, int jahr, int new_year);
	void bearbeiten_likes(std::string titel, std::string genre, int jahr, int new_likes);
	void bearbeiten_link(std::string titel, std::string genre, int jahr, std::string new_link);

	/* prints all the movies from the repo (application) */
	void print_all_movies();

	/* prints all the movies from the repo (application), which have a specific genre */
	std::vector<Film> print_all_movies(std::string genre);
};