#include "Menu.h"
#include "Persistor.h"

void MenuForTheAdmin::printOptionsForCsvOrHtml()
{
	cout << "What would you like to use? CSV or HTML file?" << endl;
}

void MenuForTheAdmin::printMenu()
{
	cout << "What would you like to do? Please press a number between 1-3\n1: Adding a movie\n 2: deleteing a movie\n 3: update a movie, 4: exit" << endl;
}

void MenuForTheAdmin::printMenuForUpdate()
{
	cout << "What would you like to update? Please introduce a number between 1-4!\n 1: the title, 2: the genre, 3: the year, 4: the link, 5: exit" << endl;
}

void MenuForTheAdmin::run()
{
	TXT* txt = new TXT();
	txt->readFromFile();

	Repo* repo = new Repo(txt->getList());
	Controller cont = Controller(repo);

	while (true)
	{
		int option;
		this->printMenu();
		cin >> option;

		if (option == 1)
		{
			// add a movie
			std::string titel;
			std::string genre;
			int jahr;
			int likes;
			std::string link;
			std::cout << "What is the title?";
			std::cin >> titel;
			std::cout << "What is the genre?";
			std::cin >> genre;
			std::cout << "What is the year?";
			std::cin >> jahr;
			std::cout << "How many likes are?";
			std::cin >> likes;
			std::cout << "What is the link?";
			std::cin >> link;
			try
			{
				cont.addMovie(titel, genre, jahr, likes, link);
				cont.printController();
				txt->setList(cont.getRepositry().getVektor());
				txt->writeToTheFile();
			}
			catch (SchonExists & error)
			{
				error.printError();
			}
		}
		if (option == 2)
		{
			// delete a movie
			std::string titel;
			std::string genre;
			int jahr;
			std::cout << "What is the title?";
			std::cin >> titel;
			std::cout << "What is the genre?";
			std::cin >> genre;
			std::cout << "What is the year?";
			std::cin >> jahr;

			try
			{
				cont.deleteMovie(titel, genre, jahr);
				cont.printController();
				txt->setList(cont.getRepositry().getVektor());
				txt->writeToTheFile();
			}
			catch (NotExistsError & error)
			{
				error.printError();
			}
		}
		if (option == 3)
		{
			//update a movie
			std::string titel;
			std::string genre;
			int jahr;
			std::cout << "What is the title?";
			std::cin >> titel;
			std::cout << "What is the genre?";
			std::cin >> genre;
			std::cout << "What is the year?";
			std::cin >> jahr;

			this->printMenuForUpdate();
			int option2;
			cin >> option2;
			if (option2 == 1)
			{
				//update titel
				string newTitel;
				cout << "What is the new Title?\n";
				cin >> newTitel;
				try
				{
					cont.updateTitel(titel, genre, jahr, newTitel);
					txt->setList(cont.getRepositry().getVektor());
					txt->writeToTheFile();
				}
				catch (NotExistsError & error)
				{
					error.printError();
				}
			}
			if (option2 == 2)
			{
				// update genre
				string newGenre;
				cout << "What is the new Genre?\n";
				cin >> newGenre;
				try
				{
					cont.updateGenre(titel, genre, jahr, newGenre);
					txt->setList(cont.getRepositry().getVektor());
					txt->writeToTheFile();
				}
				catch (NotExistsError & error)
				{
					error.printError();
				}
			}
			if (option2 == 3)
			{
				//update jahr
				int newJahr;
				cout << "What is the new Year?\n";
				cin >> newJahr;
				try
				{
					cont.updateJahr(titel, genre, jahr, newJahr);
					txt->setList(cont.getRepositry().getVektor());
					txt->writeToTheFile();
				}
				catch (NotExistsError & error)
				{
					error.printError();
				}
			}
			if (option2 == 4)
			{
				// update link
				string newLink;
				cout << "What is the new link?\n";
				cin >> newLink;
				try
				{
					cont.updateLink(titel, genre, jahr, newLink);
					txt->setList(cont.getRepositry().getVektor());
					txt->writeToTheFile();
				}
				catch (NotExistsError & error)
				{
					error.printError();
				}
			}
			if (option2 == 5)
			{
				break;
			}
		}
		if (option == 4)
		{
			break;
		}
	}

}

void MenuForTheUser::printOptionsForCsvOrHtml()
{
	cout << "What would you like to use? CSV or Html?" << endl;
}

void MenuForTheUser::printMenu()
{
	cout << "What would you like to do? Please introduce a numebr between 1-4! \n 1: search for a movie with a given genre, 2: delete a movie from watchlist, 3: see all movies from watchlist, 4: Exit" << endl;
}

void MenuForTheUser::printMenuForLikeOrNot()
{
	cout << "Did you like the movie or not?" << endl;
}

void MenuForTheUser::AddToWatchlistOrNot()
{
	cout << "1: add this movie to my watchlist, 2: Next movie, 3: Break" << endl;
}

void MenuForTheUser::run()
{
	this->printOptionsForCsvOrHtml();
	string CSVorHTML;
	cin >> CSVorHTML;

	TXT* txt = new TXT();
	txt->readFromFile();
	Repo* repo = new Repo(txt->getList());
	Controller cont = Controller(repo);
	CSV* csv = new CSV();
	HTML* html = new HTML();
	//html->createFile("informatii.html");

	Watchlist myWatchlist;
	while (true)
	{
		int option;
		this->printMenu();
		cin >> option;

		if (option == 1)
		{
			std::cout << "Please introduce here a genre: ";
			std::string genre;
			std::cin >> genre;

			std::vector<Film*> moviesWithGenre;
			if (genre == "")
				moviesWithGenre = cont.getRepositry().getVektor();
			else
			{
				moviesWithGenre = cont.alleFilmeMitEinGenre(genre);
			}

			if (moviesWithGenre.size() == 0) cout << "There are no movies with this genre!" << endl;
			for (int i = 0; i < moviesWithGenre.size(); i++)
			{
				std::cout << moviesWithGenre[i]->getTitel() << ", " << moviesWithGenre[i]->getGenre() << ", " << moviesWithGenre[i]->getJahr() << std::endl;
				std::string url = moviesWithGenre[i]->getLink();
				system(std::string("start " + url).c_str());
				int option2;
				std::cout << "1: Add to my Watchlist, 2: Next, 3: Exit " << std::endl;
				std::cin >> option2;
				if (option2 == 1)
				{
					myWatchlist.addMovie(moviesWithGenre[i]);
					csv->setList(myWatchlist.getList());
					csv->writeToTheFile();
					html->setList(myWatchlist.getList());
					html->writeToTheFile();
				}
				if (option2 == 3)
					break;
			}
		}
		else if (option == 2)
		{
			std::string titel;
			std::string genre;
			int jahr;

			std::string like;

			std::cout << "What is the title?";
			std::cin >> titel;

			std::cout << "What is the genre?";
			std::cin >> genre;

			std::cout << "What is the year?";
			std::cin >> jahr;

			std::cout << "Did you like it?";
			std::cin >> like;

			if (like == "yes")
			{
				bool found = false;
				for (auto movie : myWatchlist.getList())
				{
					if (movie->getTitel() == titel && movie->getGenre() == genre && movie->getJahr() == jahr)
					{
						found = true;
						movie->setLike(movie->getLike() + 1);
						std::cout << movie->getLike() << std::endl;
					}
					if (found)
						break;
				}
				if (not found)
					std::cout << "This movie is not in your watchlist!" << std::endl;
				else myWatchlist.deleteMovie(titel, genre, jahr);
			}
			else
			{
				myWatchlist.deleteMovie(titel, genre, jahr);
			}
			csv->setList(myWatchlist.getList());
			csv->writeToTheFile();
			html->setList(myWatchlist.getList());
			html->writeToTheFile();
		}
		else if (option == 3)
		{
			myWatchlist.seeWatchlist();
			string str = "start informatii.html";;
			system(str.c_str());
		}
		else if (option == 4)
		{
			break;
		}
		else
		{
			std::cout << "You did something wrong! PLease try again. " << std::endl;
		}
	}
}
