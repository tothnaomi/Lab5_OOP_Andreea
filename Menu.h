#pragma once
#include <iostream>
#include "Controller.h"
#include "Watchlist.h"
using namespace std;

class MenuForTheAdmin
{

public:
	static void printOptionsForCsvOrHtml();

	static void printMenu();

	static void printMenuForUpdate();

	void run();
};

class MenuForTheUser
{
public:

	static void printOptionsForCsvOrHtml();

	static void printMenu();

	static void printMenuForLikeOrNot(); // cand stergem un film din watchlist trebuie sa-l intrebam pe user daca i-a placut filmul sau nu

	static void AddToWatchlistOrNot();

	void run();
};
