#pragma once
#include "Error.h"
#include <vector>
#include "Filme.h"
#include <sstream>
using namespace std;

class Repo
{
	/* CRUD: create, read, update, delete */
private:
	vector<Film*> liste;

	template <typename Param, typename Func>
	void update(string titel, string genre, int jahr, Param param, Func lambdaFunc);

public:

	Repo(std::vector <Film*> movies);

	/// getter
	std::vector<Film*> getVektor() const; // tested

	void addFilm(string, string, int, int, string); // tested

	void deleteMovie(string, string, int);

	Film* searchMovie(string, string, int); // tested

	void updateTitel(string titel, string genre, int jahr, std::string newTitel);

	void updateGenre(string titel, string genre, int jahr, std::string newGenre);

	void updateJahr(string titel, string genre, int jahr, int newJahr);

	void updateLike(string titel, string genre, int jahr, int newLikes);

	void updateLink(string titel, string genre, int jahr, std::string newLink);

	Film* makePointer(std::string titel, std::string genre, int jahr, int likes, std::string link);

	bool operator==(Repo other);
};

