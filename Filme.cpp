#include "Filme.h"
#include <iostream>

Film::Film(std::string titel, std::string genre, int jahr, int likes, std::string link)
{
	this->titel = titel;
	this->genre = genre;
	this->erscheinungsjahr = jahr;
	this->likes = likes;
	this->linkTrailer = link;
}

void Film::set_titel(std::string titel)
{
	this->titel = titel;
}

void Film::set_genre(std::string genre)
{
	this->genre = genre;
}

void Film::set_erscheinungsjahr(int jahr)
{
	this->erscheinungsjahr = jahr;
}

void Film::set_likes(int like)
{
	this->likes = like;
}

void Film::set_link(std::string link)
{
	this->linkTrailer = link;
}

std::string Film::get_titel() const
{
	return this->titel;
}

std::string Film::get_genre() const 
{
	return this->genre;
}


int Film::get_erscheinungsjahr() const
{
	return this->erscheinungsjahr;
}

int Film::get_likes() const
{
	return this->likes;
}

std::string Film::get_link() const
{
	return this->linkTrailer;
}

void Film::print_movie()
{
	std::cout << this->get_titel() << ", " << this->get_genre() << ", " << this->get_erscheinungsjahr() << ", " << this->get_likes() << ", " << this->get_link() << std::endl;
}


bool Film::operator==(Film other)
{
	if (this->titel == other.titel && this->genre == other.genre && this->erscheinungsjahr == other.erscheinungsjahr)
		return true;
	else
		return false;
}
