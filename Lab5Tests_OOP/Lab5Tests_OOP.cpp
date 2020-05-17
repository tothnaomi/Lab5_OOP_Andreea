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
			movie.setTitel("HELLO");
			Assert::IsTrue(movie.getTitel() == "HELLO");
			movie.setGenre("Love");
			Assert::IsTrue(movie.getGenre() == "Love");
			movie.setJahr(2000);
			Assert::IsTrue(movie.getJahr() == 2000);
			movie.setLike(1554);
			Assert::IsTrue(movie.getLike() == 1554);
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
			try
			{
				repo.updateGenre("Jumbo", "Love", 2000, "Comedy");
			}
			catch (NotExistsError & error) {}
			repo.updateJahr("Jumbo", "Comedy", 2000, 2020);
			Assert::IsTrue(repo.getVektor()[1]->getJahr() == 2020);
			try
			{
				repo.updateJahr("Jumbo", "Comedy", 2000, 2020);
			}
			catch (NotExistsError & err) {}
			repo.updateLike("Jumbo", "Comedy", 2020, 15554);
			Assert::IsTrue(repo.getVektor()[1]->getLike() == 15554);
			repo.updateLink("Jumbo", "Comedy", 2020, "HTTPS://WWW.GOOGLE.COM");
			Assert::IsTrue(repo.getVektor()[1]->getLink() == "HTTPS://WWW.GOOGLE.COM");

			try
			{
				repo.updateLike("SKIN", "Comedy", 1997, 122221);
			}
			catch (NotExistsError & err) {}

			try
			{
				repo.updateLink("SKIN", "Comedy", 1997, "https://www.google.com");
			}
			catch (NotExistsError & err) {}
		}

		TEST_METHOD(OperatorOverloadTest)
		{
			std::vector<Film*> movies1;
			std::vector<Film*> movies2;
			Repo repo1 = Repo(movies1);
			Repo repo2 = Repo(movies2);
			repo1.addFilm("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			repo1.addFilm("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");

			repo2.addFilm("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Assert::IsTrue(repo1.operator==(repo2) == false);
			repo2.deleteMovie("Jumbo", "Love", 2000);
			repo2.addFilm("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			repo2.addFilm("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Assert::IsTrue(repo1.operator==(repo2) == false);

			repo1.addFilm("Skin", "Comedy", 1997, 45678, "https://www.google.com");
			repo2.addFilm("HELLO", "Love", 2020, 1554, "https://www.google.com");
			Assert::IsTrue(repo1.operator==(repo2) == false);
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
			vector<Film*> movies;
			Repo repo = Repo(movies);
			Controller cont = Controller(&repo);
			cont.addMovie("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			cont.addMovie("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			cont.addMovie("Skin", "Comedy", 1997, 45678, "https://www.google.com");

			cont.updateTitel("Hello", "Drama", 2019, "HELLO");
			Assert::IsTrue(cont.getRepositry().getVektor()[0]->getTitel() == "HELLO");
			try
			{
				cont.updateTitel("Hello", "Drama", 2019, "HELLO");
			}
			catch (NotExistsError & error)
			{

			}
			cont.updateGenre("Jumbo", "Love", 2000, "Comedy");
			Assert::IsTrue(cont.getRepositry().getVektor()[1]->getGenre() == "Comedy");
			try
			{
				cont.updateGenre("Jumbo", "Love", 2000, "Comedy");
			}
			catch (NotExistsError & error) {}

			cont.updateJahr("Jumbo", "Comedy", 2000, 2020);
			Assert::IsTrue(cont.getRepositry().getVektor()[1]->getJahr() == 2020);
			try
			{
				cont.updateJahr("Jumbo", "Comedy", 2000, 2020);
			}
			catch (NotExistsError & err) {}
			cont.updateLike("Jumbo", "Comedy", 2020, 15554);
			Assert::IsTrue(cont.getRepositry().getVektor()[1]->getLike() == 15554);
			cont.updateLink("Jumbo", "Comedy", 2020, "HTTPS://WWW.GOOGLE.COM");
			Assert::IsTrue(cont.getRepositry().getVektor()[1]->getLink() == "HTTPS://WWW.GOOGLE.COM");

			try
			{
				cont.updateLike("SKIN", "Comedy", 1997, 122221);
			}
			catch (NotExistsError & err) {}

			try
			{
				cont.updateLink("SKIN", "Comedy", 1997, "https://www.google.com");
			}
			catch (NotExistsError & err) {}

		}

		TEST_METHOD(AlleFilmeMitGenre)
		{
			vector<Film*> movies;
			Repo repo = Repo(movies);
			Controller cont = Controller(&repo);

			cont.addMovie("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			cont.addMovie("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			cont.addMovie("Skin", "Drama", 1997, 45678, "https://www.google.com");

			Film film1 = Film("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			Film film2 = Film("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Film film3 = Film("Skin", "Drama", 1997, 45678, "https://www.google.com");
			
			vector<Film*> moviesWithGenre = cont.alleFilmeMitEinGenre("Drama");
			Assert::IsTrue(moviesWithGenre.size() == 2);
		}

		TEST_METHOD(PrintTest)
		{
			vector<Film*> movies;
			Repo repo = Repo(movies);
			Controller cont = Controller(&repo);

			cont.addMovie("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			cont.addMovie("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			cont.addMovie("Skin", "Drama", 1997, 45678, "https://www.google.com");
			cont.printController();
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
			try
			{
				watchlist.addMovie(&movie1);
			}
			catch(SchonExists& err) {}
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

			try {
				watchlist.deleteMovie("Hello", "Drama", 2019);
			}
			catch (NotExistsError& err) {}
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
			watchlist.seeWatchlist();
		}
	};

	TEST_CLASS(CSVTest)
	{
		TEST_METHOD(WriteTest)
		{
			CSV csv;
			vector<Film*> movies;
			Film* movie1 = new Film("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			Film* movie2 = new Film("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Film* movie3 = new Film("Skin", "Comedy", 1997, 45678, "https://www.google.com");

			movies.push_back(movie1); movies.push_back(movie2); movies.push_back(movie3);
			csv.setList(movies);

			csv.writeToTheFile();
		}

		TEST_METHOD(ConvertStringToIntTest)
		{
			CSV csv;
			Assert::IsTrue(CSV::convertStringToInt("15") == 15);
		}

		TEST_METHOD(GetListSetList)
		{
			CSV csv;
			vector<Film*> movies;
			Film* movie1 = new Film("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			Film* movie2 = new Film("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Film* movie3 = new Film("Skin", "Comedy", 1997, 45678, "https://www.google.com");

			movies.push_back(movie1); movies.push_back(movie2); movies.push_back(movie3);
			csv.setList(movies);
			Assert::IsTrue(csv.getList() == movies);
		}
	};

	TEST_CLASS(HTMLTest)
	{
		TEST_METHOD(SetGetList)
		{
			HTML html;
			vector<Film*> movies;
			Film* movie1 = new Film("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			Film* movie2 = new Film("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Film* movie3 = new Film("Skin", "Comedy", 1997, 45678, "https://www.google.com");

			movies.push_back(movie1); movies.push_back(movie2); movies.push_back(movie3);
			html.setList(movies);
			Assert::IsTrue(html.getList() == movies);
		}

		TEST_METHOD(WriteTest)
		{
			HTML html;
			vector<Film*> movies;
			Film* movie1 = new Film("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			Film* movie2 = new Film("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Film* movie3 = new Film("Skin", "Comedy", 1997, 45678, "https://www.google.com");

			movies.push_back(movie1); movies.push_back(movie2); movies.push_back(movie3);
			html.setList(movies);
			html.writeToTheFile();
		}

		TEST_METHOD(OpenTest)
		{
			HTML html;
			html.writeToTheFile();
			//html.openHTML();
		}

	};

	TEST_CLASS(TXTTest)
	{
		TEST_METHOD(SetGetList)
		{
			TXT txt;
			vector<Film*> movies;
			Film* movie1 = new Film("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			Film* movie2 = new Film("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Film* movie3 = new Film("Skin", "Comedy", 1997, 45678, "https://www.google.com");
			 
			movies.push_back(movie1); movies.push_back(movie2); movies.push_back(movie3);
			txt.setList(movies);
			Assert::IsTrue(txt.getList() == movies);
		}

		TEST_METHOD(ReadTest)
		{
			TXT txt;
			txt.readFromFile();
		}

		TEST_METHOD(WriteTest)
		{
			TXT txt;
			vector<Film*> movies;
			Film* movie1 = new Film("Hello", "Drama", 2019, 1245788, "https://www.google.com");
			Film* movie2 = new Film("Jumbo", "Love", 2000, 45177, "https://www.youtube.com");
			Film* movie3 = new Film("Skin", "Comedy", 1997, 45678, "https://www.google.com");

			movies.push_back(movie1); movies.push_back(movie2); movies.push_back(movie3);
			txt.setList(movies);
			txt.writeToTheFile();
		}
	};


	TEST_CLASS(ErrorTest)
	{
		TEST_METHOD(TestAll)
		{
			NotExistsError notexists;
			notexists.printError();
			SchonExists schonexists;
			schonexists.printError();
		}
	};
}
