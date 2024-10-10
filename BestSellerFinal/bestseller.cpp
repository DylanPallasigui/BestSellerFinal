#include "bestseller.h"

//-----------------------------------------------------------
//  Purpose:    Program that stores six pieces of information 
//              about books on the New York Times best sellers list. 
//  Author:     Dylan Pallasigui
//-----------------------------------------------------------

// Default constructor
BestSeller::BestSeller() {
    Year = 0;
    Week = "";
    Rank = 0;
    TitleID = 0;
    Title = "";
    Author = "";
}

// Copy constructor
BestSeller::BestSeller(const BestSeller & bSell) {
    Year = bSell.Year;
    Week = bSell.Week;
    Rank = bSell.Rank;
    TitleID = bSell.TitleID;
    Title = bSell.Title;
    Author = bSell.Author;
}

// Parameterized constructor
BestSeller::BestSeller(int year, string week, int rank, int titleID, string title, string author) {
    Year = year;
    Week = week;
    Rank = rank;
    TitleID = titleID;
    Title = title;
    Author = author;
}

// Destructor
BestSeller::~BestSeller() {
}

int BestSeller::getYear() {
    return Year;
}

string BestSeller::getWeek() const{
    return Week;
}

int BestSeller::getRank() {
    return Rank;
}

int BestSeller::getTitleID() {
    return TitleID;
}

string BestSeller::getTitle() const {
    return Title;
}

string BestSeller::getAuthor() const {
    return Author;
}

void BestSeller::setYear(int year) {
    Year = year;
}

void BestSeller::setWeek(string week) {
    Week = week;
}

void BestSeller::setRank(int rank) {
    Rank = rank;
}

void BestSeller::setTitleID(int titleID) {
    TitleID = titleID;
}

void BestSeller::setTitle(string title) {
    Title = title;
}

void BestSeller::setAuthor(string author) {
    Author = author;
}

void BestSeller::read() {
    // Implementation to read data from the user
}

void BestSeller::print() const {
    cout << "Year:    (" << Year << ")" << endl
        << "Week:  (" << Week << ")" << endl
        << "Rank:     (" << Rank << ")" << endl
        << "Title ID:    (" << TitleID << ")" << endl 
        << "Title:   (" << Title << ")" << endl;
    cout << "Author:   (" << Author << ")" << endl << endl;
}