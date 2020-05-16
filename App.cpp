#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Repository.h"
#include "Menu.h"
#include "Persistor.h"
using namespace std;

int main()
{
	/*CSV csv;
	csv.readFromFile();
	cout << csv.getList().size();
	Repo* repo = new Repo(csv.getList());
	Controller cont = Controller(repo);

	cont.addMovie("HELLO", "Drama", 1997, 45782, "link");*/

	//cont.updateTitel("Hello", "Drama", 1975, "HELLO");
	//csv.writeToTheFile();

	//cont.printController();

	/*std::vector<Film*> movies;
	Repo repo = Repo(movies);
	Film* film1 = repo.makePointer("H", "Drama", 1998, 12, "google");
	Film* film2 = repo.makePointer("K", "Drama", 2000, 12, "google");
	repo.addFilm("H", "Drama", 1998, 12, "google");
	repo.addFilm("K", "Drama", 2000, 12, "google");
	cout << repo.getVektor().size() << endl;

	repo.updateGenre("H", "Drama", 1998, "Love");
	repo.printRepo();

	repo.deleteMovie("K", "Drama", 2000);
	repo.printRepo();*/

	/*try
	{
		Film* updateFilm = repo.searchMovie("KK", "Drama", 1997);
		repo.update("H", "Drama", 1998, 2000, "", [](Film* updateFilm, int, string) { updateFilm->setJahr(2000); });
	}
	catch (NotExistsError err)
	{
		err.printError();
	}
	Film* movie = repo.searchMovie("H", "Drama", 1998);
	if (movie == nullptr) cout << "nullptr";*/

	/*MenuForTheAdmin menuAdmin;
	MenuForTheUser menuUser;

	string option;
	cout << "Hi! Are you the admin or the user?" << endl;
	cin >> option;
	if (option == "Admin")
	{
		menuAdmin.run();
	}
	if (option == "User")
	{
		menuUser.run();
	}*/

	string UserOrAdmin;
	cout << "Are you the Admin or a User?\n";
	cin >> UserOrAdmin;
	if (UserOrAdmin == "Admin")
	{
		MenuForTheAdmin menuAdmin;
		menuAdmin.run();
	}
	if (UserOrAdmin == "User")
	{
		MenuForTheUser menuUser;
		menuUser.run();
	}
}