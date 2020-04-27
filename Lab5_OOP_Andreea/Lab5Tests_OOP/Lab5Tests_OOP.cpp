#include "pch.h"
#include "CppUnitTest.h"
#include "../Repository.h"
#include "../Controller.h"
#include <cassert>
#include "../Watchlist.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5TestsOOP
{
	TEST_CLASS(ControllerTest)
	{
	public:
		TEST_METHOD(addTest)
		{	
			Repo repo;
			Controller cont = Controller();
			cont.set_repo(&repo);
			Film film1 = Film("Hello", "Comedy", 1997, 12, "https://youtu.be/YQHsXMglC9A");
			Film film2 = Film("Kojo", "Drama", 2007, 14, "https://www.google.com");

			cont.hinfugen(film1);
			assert(repo.get_list().size() == 1);
			cont.hinfugen(film2);
			assert(repo.get_list().size() == 2);
		}

		TEST_METHOD(searchTest)
		{
			Repo repo;
			Film film1 = Film("Hello", "Comedy", 1997, 12, "https://youtu.be/YQHsXMglC9A");
			Film film2 = Film("Kojo", "Drama", 2007, 14, "https://www.google.com");

			assert(repo.search("Hello", "Comedy", 1997) == -1);
			repo.hunfugen(film1);
			repo.hunfugen(film2);

			assert(repo.search("Hello", "Comedy", 1997) == 0);
			assert(repo.search("Kojo", "Drama", 2007) == 1);
		}

		TEST_METHOD(deleteTest)
		{
			Repo repo=Repo();
			Controller cont = Controller();
			cont.set_repo(&repo);
			Film film1 = Film("Hello", "Comedy", 1997, 12, "https://youtu.be/YQHsXMglC9A");
			Film film2 = Film("Kojo", "Drama", 2007, 14, "https://www.google.com");
			cont.hinfugen(film1);
			cont.hinfugen(film2);

			cont.loschen("Hi", "Comedy", 1997);
			assert(cont.get_repo()->get_list().size() == 2);

			cont.loschen("Hello", "Comedy", 1997);
			assert(cont.get_repo()->get_list().size() == 1);
		}

		TEST_METHOD(changingTest)
		{
			Repo repo = Repo();
			Controller cont = Controller();
			cont.set_repo(&repo);
			Film film1 = Film("Hello", "Comedy", 1997, 12, "https://youtu.be/YQHsXMglC9A");
			Film film2 = Film("Kojo", "Drama", 2007, 14, "https://www.google.com");

			cont.bearbeiten_titel("Hello", "Comedy", 1997, "HELLO");
			cont.bearbeiten_link("HELLO", "Comedy", 1977, "https://www.google.com");
		
			std::vector<Film> film = cont.get_repo()->get_list();
			for (int i = 0; i < film.size(); i++)
			{
				if (i == 0)
				{
					assert(film[i].get_titel() == "HELLO");
					assert(film[i].get_link() == "https://www.google.com");
					break;
				}
			}
		}

		TEST_METHOD(printAllWithGenreTest)
		{
			Repo repo = Repo();
			Controller cont = Controller();
			cont.set_repo(&repo);

			Film film1 = Film("Colour", "Drama", 2019, 2715, "https://youtu.be/tySUZIiXObc");
			Film film2 = Film("Skin", "Comedy", 2019, 20000, "https://youtu.be/S6g2VMnmFRk");
			Film film3 = Film("Dolemite", "Comedy", 2017, 15478, "https://youtu.be/Ws1YIKsuTjQ");
			Film film4 = Film("Tigers", "Sci-Fi", 2019, 15748, "https://youtu.be/KyoE0mSJXO8");
			Film film5 = Film("Invisible", "Romance", 2014, 1457, "https://youtu.be/NRF-Pba3QrE");
			Film film6 = Film("Kojo", "Drama", 2016, 11287, "https://youtu.be/2l7gC3fa3m0");
			Film film7 = Film("Crawl", "Drama", 2016, 17589, "https://youtu.be/H6MLJG0RdDE");
			Film film8 = Film("Burning", "Drama", 2019, 1547, "https://youtu.be/04krY7dl3cE");
			cont.hinfugen(film1);
			cont.hinfugen(film2);
			cont.hinfugen(film3);
			cont.hinfugen(film4);
			cont.hinfugen(film5);
			cont.hinfugen(film6);
			cont.hinfugen(film7);
			cont.hinfugen(film8);

			std::vector<Film> moviesWithGenre = cont.print_all_movies("Comedy");
			assert(moviesWithGenre.size() == 2);

			moviesWithGenre = cont.print_all_movies("Drama");
			assert(moviesWithGenre.size() == 4);
		}

	};

	TEST_CLASS(FilmTest)
	{
		TEST_METHOD(ConstructorTest)
		{
			Film film1 = Film("Colour", "Drama", 2019, 2715, "https://youtu.be/tySUZIiXObc");
			Film film2 = Film("Skin", "Comedy", 2019, 20000, "https://youtu.be/S6g2VMnmFRk");

			assert(film1.get_titel() == "Colour");
			assert(film1.get_genre() == "Drama");
			assert(film1.get_erscheinungsjahr() == 2019);
			assert(film1.get_likes() == 2715);
			assert(film1.get_link() == "https://youtu.be/tySUZIiXObc");

			film2.set_titel("SKIN");
			assert(film2.get_titel() == "SKIN");
			film2.set_genre("Drama");
			assert(film2.get_genre() == "Drama");
			film2.set_erscheinungsjahr(2020);
			assert(film2.get_erscheinungsjahr() == 2020);
			film2.set_likes(12);
			assert(film2.get_likes() == 12);
			film2.set_link("https://www.google.com");
			assert(film2.get_link() == "https://www.google.com");
		}

		TEST_METHOD(operatorOverloadTest)
		{
			Film film1 = Film("Colour", "Drama", 2019, 2715, "https://youtu.be/tySUZIiXObc");
			Film film2 = Film("Skin", "Comedy", 2019, 20000, "https://youtu.be/S6g2VMnmFRk");
			Film film3 = Film("Colour", "Drama", 2019, 2715, "https://youtu.be/tySUZIiXObc");

			assert(film1.operator==(film2) == false);
			assert(film1.operator==(film3) == true);
			assert(film2.operator==(film3) == false);
		}
	};

	TEST_CLASS(WatchlistTest)
	{
		TEST_METHOD(addTest)
		{
			Film film1 = Film("Colour", "Drama", 2019, 2715, "https://youtu.be/tySUZIiXObc");
			Film film2 = Film("Skin", "Comedy", 2019, 20000, "https://youtu.be/S6g2VMnmFRk");
			Watchlist watchlist;

			watchlist.hinfugen(film1);
			assert(watchlist.get_list().size() == 1);
			watchlist.hinfugen(film2);
			assert(watchlist.get_list().size() == 2);

			std::vector<Film> watch = watchlist.get_list();
			for (int i = 0; i < watch.size(); i++)
			{
				if (i == 0)
				{
					assert(watch[i].get_titel() == "Colour");
					assert(watch[i].get_genre() == "Drama");
				}
				if (i == 1)
				{
					assert(watch[i].get_titel() == "Skin");
					assert(watch[i].get_genre() == "Comedy");
				}
			}
		}
	};
}
