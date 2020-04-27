#include <exception>
#include <iostream>
#include "Controller.h"
#include "Repository.h"
#include "Filme.h"
#include "Watchlist.h"
#include "Watchtrailer.h"

/* IMPORTANT: opening an url: system (std::string("start " + url).c_str()) -> url is the string of the actual url */

int main()
{
    std::string modus;
    std::string name;

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


    std::cout << "Welcome to the Movie Watcher App. Are you the Admin or are you a User?" << std::endl;
    std::cin >> modus;
    std::cout << "What is your name?";
    std::cin >> name;
    if (modus == "Admin")
    {
        std::cout << "Hello " << name << " Admin!:)" << std::endl;
        int option;
        while (true)
        {
            std::cout << "What do you want to do?" << std::endl << "1: adding a movie" << std::endl << "2: deleting a movie";
            std::cout << std::endl << "3: changing something" << std::endl << "4: print all the movies" << std::endl << "5: Exit" << std::endl;
            std::cin >> option;
            if (option == 1)
            {
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

                Film film = Film(titel, genre, jahr, likes, link);
                //try
                //{
                    cont.hinfugen(film);
                //}
                //catch (Error err)
                //{
                //    std::cout << "The Movie is already in the list of movies!" << std::endl;
                //}
            }
            else if (option == 2)
            {
                std::string titel;
                std::string genre;
                int jahr;
                std::cout << "What is the title?";
                std::cin >> titel;
                std::cout << "What is the genre?";
                std::cin >> genre;
                std::cout << "What is the year?";
                std::cin >> jahr;

                //try
                //{
                    cont.loschen(titel, genre, jahr);
                //}
                //catch (Error err)
                //{
                //    std::cout << "This movie is not in the list of movies!" << std::endl;
                //}
            }
            else if (option == 3)
            {
                std::string titel;
                std::string genre;
                int jahr;
                std::cout << "What is the title?";
                std::cin >> titel;
                std::cout << "What is the genre?";
                std::cin >> genre;
                std::cout << "What is the year?";
                std::cin >> jahr;

                int mini_option;
                std::cout << "What do you want to change?" << std::endl;
                std::cout << "1: title" << std::endl << "2: genre" << std::endl << "3: year" << std::endl << "4: likes" << std::endl << "5: link" << std::endl << "6: Exit" << std::endl;
                std::cin >> mini_option;

                //try
                //{
                    if (mini_option == 1)
                    {
                        std::string new_titel;
                        std::cout << "What is the new title?";
                        std::cin >> new_titel;

                        cont.bearbeiten_titel(titel, genre, jahr, new_titel);
                    }
                    else if (mini_option == 2)
                    {
                        std::string new_genre;
                        std::cout << "What is the new genre?";
                        std::cin >> new_genre;

                        cont.bearbeiten_genre(titel, genre, jahr, new_genre);
                    }
                    else if (mini_option == 3)
                    {
                        int new_year;
                        std::cout << "What is the new year?";
                        std::cin >> new_year;

                        cont.bearbeiten_year(titel, genre, jahr, new_year);
                    }
                    else if (mini_option == 4)
                    {
                        int new_like;
                        std::cout << "What is the new number of likes?";
                        std::cin >> new_like;

                        cont.bearbeiten_likes(titel, genre, jahr, new_like);
                    }
                    else if (mini_option == 5)
                    {
                        std::string new_link;
                        std::cout << "What is the new link?";
                        std::cin >> new_link;

                        cont.bearbeiten_link(titel, genre, jahr, new_link);
                    }
                    else
                    {
                        std::cout << "You did something wrong! Please try again!" << std::endl;
                    }
                //}
                //catch (Error err)
                //{
                //    std::cout << "This Movie is not in the list of movies!" << std::endl;
                //}
            }
            else if (option == 4)
            {
                //try
                {
                    cont.print_all_movies();
                }
                //catch (Error err)
                //{
                //    std::cout << "The list is empty!" << std::endl;
                //}
            }
            else if (option == 5)
                break;
            else
            {
                std::cout << "You did something wrong! Please try again!" << std::endl;
            }
        }
    }
    else if (modus == "User")
    {
        std::cout << "Hello " << name << " User!:)" << std::endl;
        Watchlist watchlist;
        Watchtrailer watchtrailer;
        std::vector <Film> movies_with_genre;

        while (true)
        {
            std::cout << "What would you like to do? " << std::endl << "1: searching for movies" << std::endl << "2: delete a movie from watchlist" << std::endl << "3: see all the movies in my watchlist" << std::endl << "4: Exit the app" << std::endl;
            int option;
            std::cin >> option;
            if (option == 1)
            {
                std::cout << "Please introduce here a genre: ";
                std::string genre;
                std::cin >> genre;

                if (genre == "")
                {
                    movies_with_genre = cont.get_repo()->get_list();
                }
                else
                {
                    movies_with_genre = cont.print_all_movies(genre);
                }

                if (movies_with_genre.size() == 0)
                {
                    std::cout << "There are no movies with this genre, please try again. ";
                }

                for (int i = 0; i < movies_with_genre.size(); i++)
                {
                    std::cout << movies_with_genre[i].get_titel() << ", " << movies_with_genre[i].get_genre() << ", " << movies_with_genre[i].get_erscheinungsjahr() << std::endl;
                    std::string url = movies_with_genre[i].get_link();
                    system(std::string("start " + url).c_str());
                    int option2;
                    std::cout << "1: Add to my Watchlist" <<std::endl << "2: instantly add movie to watchlist if you like the trailer" <<std::endl << "3: go to next movie trailer" << std::endl << "4:delete movie from watchlist" << std::endl << "5:see the whole watchlist" << std::endl << "6:break" << std::endl;
                    std::cin >> option2;
                    if (option2 == 1)
                    {
                        watchlist.hinfugen(movies_with_genre[i]);
                    }
                    if (option2 == 2)
                    {
                        watchtrailer.insert_wenn_trailer_magt(movies_with_genre[i]);
                    }
                    if (option2 == 3)
                    {
                        watchtrailer.next_trailer(movies_with_genre[i]);
                    }
                    if (option2 == 4)
                        watchlist.loschen(movies_with_genre[i]);
                    if (option2 == 5)
                        watchlist.see_watchlist(movies_with_genre[i]);
                    if (option2 == 6)
                        break;

                }

            }
            else if (option == 4)
            {
                break;
            }
        }
    }
    return 0;
}