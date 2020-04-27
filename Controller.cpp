#include "Controller.h"
#include <iostream>

void Controller::set_repo(Repo* repo)
{
	this->repo = repo;
}

Repo* Controller::get_repo() const
{
	return this->repo;
}

void Controller::hinfugen(Film film)
{
	this->repo->hunfugen(film);
}

void Controller::loschen(std::string titel, std::string genre, int jahr)
{
	(*this->repo).loschen(titel, genre, jahr);
}

void Controller::bearbeiten_titel(std::string titel, std::string genre, int jahr, std::string new_titel)
{
	(*this->repo).bearbeiten_titel(titel, genre, jahr, new_titel);
}

void Controller::bearbeiten_genre(std::string titel, std::string genre, int jahr, std::string new_genre)
{
	this->repo->bearbeiten_genre(titel, genre, jahr, new_genre);
}

void Controller::bearbeiten_year(std::string titel, std::string genre, int jahr, int new_year)
{
	(*this->repo).bearbeiten_erscheinungsjahr(titel, genre, jahr, new_year);
}

void Controller::bearbeiten_likes(std::string titel, std::string genre, int jahr, int new_likes)
{
	(*this->repo).bearbeiten_likes(titel, genre, jahr, new_likes);
}

void Controller::bearbeiten_link(std::string titel, std::string genre, int jahr, std::string new_link)
{
	(*this->repo).bearbeiten_link(titel, genre, jahr, new_link);
}

void Controller::print_all_movies()
{
	this->repo->print_all_movies();
}

std::vector<Film> Controller::print_all_movies(std::string genre)
{
	std::vector<Film> movies = this->repo->print_all_movies(genre);
	return movies;
}

