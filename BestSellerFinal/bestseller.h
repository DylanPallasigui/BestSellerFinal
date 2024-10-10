#ifndef BESTSELLER_H
#define BESTSELLER_H
//-----------------------------------------------------------
//  Purpose:    Program that stores six pieces of information 
//              about books on the New York Times best sellers list. 
//  Author:     Dylan Pallasigui
//-----------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BestSeller 
{
public:
    BestSeller();
    BestSeller(const BestSeller & bSell);
    BestSeller(int year, string week, int rank, int titleID, string title, string author);
    ~BestSeller();
    void read();
    void print() const;

    int getYear();
    string getWeek() const;
    int getRank();
    int getTitleID();
    string getTitle() const;
    string getAuthor() const;
    BestSeller* getNext() const {
        return Next;
    }

    void setYear(int year);
    void setWeek(string week);
    void setRank(int rank);
    void setTitleID(int titleID);
    void setTitle(string title);
    void setAuthor(string author);
    void setNext(BestSeller* next) {
        Next = next;
    }

private:
    int Year;
    string Week;
    int Rank;
    int TitleID;
    string Title;
    string Author;
    BestSeller* Next;
};

#endif