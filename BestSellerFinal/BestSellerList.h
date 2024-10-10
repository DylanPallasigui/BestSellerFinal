// BestSellerList.h

#ifndef BESTSELLERLIST_H
#define BESTSELLERLIST_H

#include <iostream>
#include <string>
#include <vector>
#include "bestseller.h" // Include the BestSeller class

class BestSellerList {
public:
    BestSellerList();
    ~BestSellerList();

    // Linked list operations
    void InsertHead(int year, string week, int rank, int titleID, string title, string author);
    void InsertTail(int year, string week, int rank, int titleID, string title, string author);
    void AuthorInsert(int year, string week, int rank, int titleID, string title, string author);
    void TitleInsert(int year, string week, int rank, int titleID, string title, string author);
    void Print() const;
    
    // Methods to answer questions
    void MostPopularBook() const;
    void MostProlificAuthor() const;

private:
    BestSeller* Head; // Use the BestSeller class directly
    BestSeller* Tail; // Use the BestSeller class directly
    int Count;
};

#endif