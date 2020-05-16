#pragma once
#include <string>
using namespace std;

class Film
{
private:
	string titel;
	string genre;
	int jahr;
	int like;
	string link;

public:
	Film(string, string, int, int, string);

	void openTheLink(string link);

	// setters and getter
	void setTitel(string neueTitel);
	void setGenre(string neueGenre);
	void setJahr(int neuesJahr);
	void setLike(int neueLike);
	void setLink(string neueLink);

	string getTitel() const;
	string getGenre() const;
	int getJahr() const;
	int getLike() const;
	string getLink() const;
};