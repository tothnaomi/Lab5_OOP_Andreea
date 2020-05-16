#pragma once
#include <string>
/* this is lab 6*/

class Film
{
private:

	std::string titel;
	std::string genre; // category of movie
	int erscheinungsjahr;
	int likes;
	std::string linkTrailer;

public:

	Film(std::string titel, std::string genre, int jahr, int likes, std::string link);

	/* setters */

	void set_titel(std::string titel);

	void set_genre(std::string genre);

	void set_erscheinungsjahr(int jahr);

	void set_likes(int like);

	void set_link(std::string link);

	/* getters */

	std::string get_titel() const;

	std::string get_genre() const;

	int get_erscheinungsjahr() const;

	int get_likes() const;

	std::string get_link() const;

	void print_movie();

	/* operator overloading */
	bool operator == (Film other);
};

