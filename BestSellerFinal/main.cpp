#include <iostream>
#include <fstream>
#include <vector>
#include "bestseller.h"
#include "BestSellerList.h"

//-----------------------------------------------------------
//  Purpose:    Program that stores six pieces of information 
//              about books on the New York Times best sellers list. 
//  Author:     Dylan Pallasigui
//-----------------------------------------------------------

using namespace std;

// Function to read data from the file and populate the vector
void read_file(vector<BestSeller>& bestSellers) {
    ifstream inFile("nyt_best_sellers.tsv");
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    int year, rank, titleID;
    string week, title, author;

    while (inFile >> year >> week >> rank >> titleID) {
        inFile.ignore(); // Ignore the tab character after titleID
        getline(inFile, title, '\t');
        getline(inFile, author, '\n');
        BestSeller bs(year, week, rank, titleID, title, author);
        bestSellers.push_back(bs);
    }

    inFile.close();
}

//-----------------------------------------------------------
// Search array of bestseller objects for matching records.
//-----------------------------------------------------------
void search_bestseller(const vector<BestSeller>& bSell) {
    // Prompt user for input
    string choice = "";
    while ((choice != "t") && (choice != "a") && (choice != "w")) {
        cout << "Enter type of search (t = Title, a = Author, w = Week): ";
        getline(cin, choice);
    }

    cout << "Enter search string: ";
    string search = "";
    getline(cin, search);

    // Search bestseller array for matching data
    for (const BestSeller& bs : bSell) {
        if ((choice == "t") && (search == bs.getTitle()))
            bs.print();
        if ((choice == "a") && (search == bs.getAuthor()))
            bs.print();
        if ((choice == "w") && (search == bs.getWeek()))
            bs.print();
    }
}

// new(remove possibly), tests the bestsellerlist w/ random variables idk
void testBestSellerList() {
    BestSellerList bestSellerList;
    // Inserting BestSeller objects by title
    bestSellerList.TitleInsert(1970, "1970-12-27", 6, 4911, "THE CRYSTAL CAVE", "Mary Stewart");
    bestSellerList.TitleInsert(1970, "1970-12-27", 7, 4818, "THE CHILD FROM THE SEA", "Elizabeth Goudge");
    bestSellerList.TitleInsert(1970, "1970-12-27", 8, 2005, "GOD IS AN ENGLISHMAN", "R. F. Delderfield");
    bestSellerList.TitleInsert(1970, "1970-12-27", 9, 936, "CARAVAN TO VACCARES", "Alistair MacLean");
    bestSellerList.TitleInsert(1970, "1970-12-27", 10, 6241, "THE SECRET WOMAN", "Victoria Holt");

    // Print the BestSeller list by title
    cout << "BestSeller List by Title:" << endl;
    bestSellerList.Print();

    // Inserting BestSeller objects by author
    bestSellerList.AuthorInsert(1970, "1970-12-27", 6, 4911, "THE CRYSTAL CAVE", "Mary Stewart");
    bestSellerList.AuthorInsert(1970, "1970-12-27", 7, 4818, "THE CHILD FROM THE SEA", "Elizabeth Goudge");
    bestSellerList.AuthorInsert(1970, "1970-12-27", 8, 2005, "GOD IS AN ENGLISHMAN", "R. F. Delderfield");
    bestSellerList.AuthorInsert(1970, "1970-12-27", 9, 936, "CARAVAN TO VACCARES", "Alistair MacLean");
    bestSellerList.AuthorInsert(1970, "1970-12-27", 10, 6241, "THE SECRET WOMAN", "Victoria Holt");

    // Print the BestSeller list by author
    cout << "\nBestSeller List by Author:" << endl;
    bestSellerList.Print();

    // Inserting at head and tail
    bestSellerList.InsertHead(2023, "Week 5", 5, 11111, "Head Title", "Author D");
    bestSellerList.InsertTail(2023, "Week 6", 6, 99999, "Tail Title", "Author E");

    // Print the updated BestSeller list
    cout << "\nUpdated BestSeller List:" << endl;
    bestSellerList.Print();
}

int main() {
    // Declare bestseller vector
    vector<BestSeller> bestSellers;
    BestSellerList bestSellerList;

    // Read bestseller info from file
    read_file(bestSellers);

    // Print the first 20 and last 20 records
    for (unsigned int i = 0; i < 20 && i < bestSellers.size(); ++i) {
        bestSellers[i].print();
    }
    cout << "..." << endl;
    for (unsigned int i = bestSellers.size() - 20; i < bestSellers.size(); ++i) {
        bestSellers[i].print();
    }
    
    // Search for specific records
    cout << "\nSearching for best sellers:\n";
    search_bestseller(bestSellers);

    // Create a BestSellerList object and pass it to the testing function
    cout << "\nTesting BestSellerList:" << endl;
    testBestSellerList();

    // Test the MostPopularBook method
    bestSellerList.MostPopularBook();

    // Test the MostProlificAuthor method
    bestSellerList.MostProlificAuthor();
    
    return 0;
}