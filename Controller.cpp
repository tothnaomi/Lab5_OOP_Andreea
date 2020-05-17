#include "Controller.h"

Controller::Controller(Repo* newRepo)
{
	this->repo = newRepo;
}

Repo Controller::getRepositry() const
{
	return *(this->repo);
}

void Controller::deleteMovie(string titel, string genre, int jahr)
{
	this->repo->deleteMovie(titel, genre, jahr);
}

void Controller::addMovie(string titel, string genre, int jahr, int likes, string link)
{
	this->repo->addFilm(titel, genre, jahr, likes, link);
}

void Controller::updateTitel(string titel, string genre, int jahr, std::string newTitel)
{
	this->repo->updateTitel(titel, genre, jahr, newTitel);
}

void Controller::updateGenre(string titel, string genre, int jahr, std::string newGenre)
{
	this->repo->updateGenre(titel, genre, jahr, newGenre);
}

void Controller::updateJahr(string titel, string genre, int jahr, int newJahr)
{
	this->repo->updateJahr(titel, genre, jahr, newJahr);
}

void Controller::updateLike(string titel, string genre, int jahr, int newLikes)
{
	this->repo->updateLike(titel, genre, jahr, newLikes);
}

void Controller::updateLink(string titel, string genre, int jahr, std::string newLink)
{
	this->repo->updateLink(titel, genre, jahr, newLink);
}

std::vector<Film*> Controller::alleFilmeMitEinGenre(std::string genre) const
{
	std::vector<Film*> moviesWithGenre;
	for (auto elem : this->repo->getVektor())
	{
		if (elem->getGenre() == genre)
			moviesWithGenre.push_back(elem);
	}
	return moviesWithGenre;
}

void Controller::printController() const
{
	for (auto elem : this->repo->getVektor())
	{
		cout << elem->getTitel() << ", " << elem->getGenre() << ", " << elem->getJahr() << ", " << elem->getLike() << ", " << elem->getLink() << endl;
	}
}
