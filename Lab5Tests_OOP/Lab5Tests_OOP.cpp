#include "pch.h"
#include "CppUnitTest.h"
#include "../Repository.h"
#include "../Controller.h"
#include <cassert>
#include "../Watchlist.h"
#include "../Persistor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab6TestOOP
{
	TEST_CLASS(FilmTest)
	{
	public:

		TEST_METHOD(SettersAndGetters)
		{
			Film movie = Film("Hello", "Drama", 2019, 254788, "https://www.google.com");
			Assert::IsTrue(movie.getTitel() == "Hello");
			movie.setGenre("Love");
			Assert::IsTrue(movie.getGenre() == "Love");
			movie.setJahr(2000);
			Assert::IsTrue(movie.getJahr() == 2000);
			movie.setLink("https://youtu.be/YQHsXMglC9A");
			Assert::IsTrue(movie.getLink() == "https://youtu.be/YQHsXMglC9A");
		}
	};

	TEST_CLASS(RepoTest)
	{
		TEST_METHOD(ConstructorTest)
		{
			vector<Film*> movies;
			Repo repo = Repo(movies);
			Assert::IsTrue(repo.getVektor() == movies);
		}
		
		TEST_METHOD(AddFilm)
		{
			vector<Film*> movies;
			Repo repo = Repo(movies);
			repo.addFilm("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			repo.addFilm("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			repo.addFilm("Skin", "Comedy", 1997, 45678, "https://www.google.com");
			Assert::IsTrue(repo.getVektor().size() == 3);
			Assert::IsTrue(repo.getVektor()[0]->getTitel() == "Hello");
			Assert::IsTrue(repo.getVektor()[1]->getTitel() == "Jumbo");
			try
			{
				repo.addFilm("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			}
			catch (SchonExists & error)
			{
			}
		}

		TEST_METHOD(DeleteFilm)
		{
			vector<Film*> movies;
			Repo repo = Repo(movies);
			repo.addFilm("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			repo.addFilm("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			repo.addFilm("Skin", "Comedy", 1997, 45678, "https://www.google.com");
			repo.deleteMovie("Hello", "Drama", 2019);
			Assert::IsTrue(repo.getVektor().size() == 2);
			try
			{
				repo.deleteMovie("Hello", "Drama", 2019);
			}
			catch (NotExistsError & error)
			{
			}
		}

		TEST_METHOD(UpdateTest)
		{
			vector<Film*> movies;
			Repo repo = Repo(movies);
			repo.addFilm("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			repo.addFilm("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			repo.addFilm("Skin", "Comedy", 1997, 45678, "https://www.google.com");

			repo.updateTitel("Hello", "Drama", 2019, "HELLO");
			Assert::IsTrue(repo.getVektor()[0]->getTitel() == "HELLO");
			try
			{
				repo.updateTitel("Hello", "Drama", 2019, "HELLO");
			}
			catch (NotExistsError & error)
			{
			}
			repo.updateGenre("Jumbo", "Love", 2000, "Comedy");
			Assert::IsTrue(repo.getVektor()[1]->getGenre() == "Comedy");
			repo.updateJahr("Jumbo", "Comedy", 2000, 2020);
			Assert::IsTrue(repo.getVektor()[1]->getJahr() == 2020);
			repo.updateLink("Jumbo", "Comedy", 2020, "HTTPS://WWW.GOOGLE.COM");
			Assert::IsTrue(repo.getVektor()[1]->getLink() == "HTTPS://WWW.GOOGLE.COM");
		}
	};

	TEST_CLASS(ControllerTest)
	{
		TEST_METHOD(ConstructorTest)
		{
			vector<Film*> movies;
			Repo repo = Repo(movies);
			Controller cont = Controller(&repo);
			Assert::IsTrue(cont.getRepositry() == repo);
		}

		TEST_METHOD(AddTest)
		{
			vector<Film*> movies;
			Repo repo = Repo(movies);
			Controller cont = Controller(&repo);
			cont.addMovie("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			cont.addMovie("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			cont.addMovie("Skin", "Comedy", 1997, 45678, "https://www.google.com");
			Assert::IsTrue(cont.getRepositry().getVektor().size() == 3);
			Assert::IsTrue(cont.getRepositry().getVektor()[0]->getTitel() == "Hello");
			Assert::IsTrue(cont.getRepositry().getVektor()[1]->getTitel() == "Jumbo");
			Assert::IsTrue(cont.getRepositry().getVektor()[2]->getTitel() == "Skin");
		}

		TEST_METHOD(DeleteTest)
		{
			vector<Film*> movies;
			Repo repo = Repo(movies);
			Controller cont = Controller(&repo);
			cont.addMovie("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			cont.addMovie("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			cont.addMovie("Skin", "Comedy", 1997, 45678, "https://www.google.com");
			cont.deleteMovie("Hello", "Drama", 2019);
			Assert::IsTrue(cont.getRepositry().getVektor().size() == 2);
			try
			{
				cont.deleteMovie("Hello", "Drama", 2019);
			}
			catch (NotExistsError & err)
			{

			}
			Assert::IsTrue(cont.getRepositry().getVektor().size() == 2);
		}

		TEST_METHOD(UpdateTest)
		{
			/*vector<Film*> movies;
			Repo repo = Repo(movies);
			Controller cont = Controller(&repo);
			cont.addMovie("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			cont.addMovie("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			cont.addMovie("Skin", "Comedy", 1997, 45678, "https://www.google.com");
			cont.updateTitel("Hello", "Drama", 2019, "HELLO");
			Assert::IsTrue(cont.getRepositry().getVektor()[0]->getTitel() == "HELLO");
			
			cont.updateGenre("Jumbo", "Love", 2000, "Comedy");
			Assert::IsTrue(cont.getRepositry().getVektor()[1]->getGenre() == "Comedy");
			cont.updateJahr("Jumbo", "Comedy", 2000, 2020);
			Assert::IsTrue(cont.getRepositry().getVektor()[1]->getJahr() == 2020);*/
		}
	};

	TEST_CLASS(WatchlistTest)
	{
		TEST_METHOD(AddTest)
		{
			Watchlist watchlist;
			Film movie1 = Film("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			Film movie2 = Film("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Film movie3 = Film("Skin", "Comedy", 1997, 45678, "https://www.google.com");
			watchlist.addMovie(&movie1);
			watchlist.addMovie(&movie2);
			watchlist.addMovie(&movie3);
			Assert::IsTrue(watchlist.getList().size() == 3);
		}

		TEST_METHOD(DeleteTest)
		{
			Watchlist watchlist;
			Film movie1 = Film("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			Film movie2 = Film("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Film movie3 = Film("Skin", "Comedy", 1997, 45678, "https://www.google.com");
			watchlist.addMovie(&movie1);
			watchlist.addMovie(&movie2);
			watchlist.addMovie(&movie3);
			Assert::IsTrue(watchlist.getList().size() == 3);

			watchlist.deleteMovie("Hello", "Drama", 2019);
			Assert::IsTrue(watchlist.getList().size() == 2);
			Assert::IsTrue(watchlist.inWatchlist("Hello", "Drama", 2019) == false);
		}

		TEST_METHOD(InWatchlistTest)
		{
			Watchlist watchlist;
			Film movie1 = Film("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			Film movie2 = Film("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Film movie3 = Film("Skin", "Comedy", 1997, 45678, "https://www.google.com");
			watchlist.addMovie(&movie1);
			watchlist.addMovie(&movie2);
			watchlist.addMovie(&movie3);

			Assert::IsTrue(watchlist.inWatchlist("Hello", "Drama", 2019) == true);
			Assert::IsTrue(watchlist.inWatchlist("Jumbo", "Love", 2000) == true);
			Assert::IsTrue(watchlist.inWatchlist("Skin", "Comedy", 1997) == true);

			Assert::IsTrue(watchlist.inWatchlist("Hi", "Drama", 2019) == false);
		}
	};

	TEST_CLASS(CSVTest)
	{
		TEST_METHOD(ReadTest)
		{
			CSV csv;
			csv.readFromFile();
		}

		TEST_METHOD(ConvertStringToIntTest)
		{
			CSV csv;
			Assert::IsTrue(CSV::convertStringToInt("15") == 15);
		}
	};
}
