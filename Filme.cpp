#include "Filme.h"

Film::Film(string titel, string genre, int jahr, int like, string link)
{
	this->titel = titel;
	this->genre = genre;
	this->jahr = jahr;
	this->like = like;
	this->link = link;
}

void Film::setTitel(string neueTitel)
{
	this->titel = neueTitel;
}

void Film::setGenre(string neueGenre)
{
	this->genre = neueGenre;
}

void Film::setJahr(int neuesJahr)
{
	this->jahr = neuesJahr;
}

void Film::setLike(int neueLike)
{
	this->like = neueLike;
}

void Film::setLink(string neueLink)
{
	this->link = neueLink;
}

std::string Film::getTitel() const
{
	return this->titel;
}

std::string Film::getGenre() const
{
	return this->genre;
}


int Film::getJahr() const
{
	return this->jahr;
}

int Film::getLike() const
{
	return this->like;
}

string Film::getLink() const
{
	return this->link;
}
