#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
using namespace std;
class Movie
{
private:
string title;
string director;
int year;
public:
void setTitle(string t) {
title = t;
}
void setDirector(string d) {
director = d;
}
void setYear(int y) {
year = y;
}
void display() {
cout << "Title: " << title << endl;
cout << "Director: " << director << endl;
cout << "Year: " << year << endl;
}
};
#endif // MOVIE_H

int main() {
Movie myFavoriteMovie;
myFavoriteMovie.setTitle("Gattaca");
myFavoriteMovie.setDirector("Andrew Niccol");
myFavoriteMovie.setYear(1997);
myFavoriteMovie.display();
return 0;
}