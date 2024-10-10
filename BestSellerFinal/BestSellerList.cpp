// BestSellerList.cpp
#include <map>
#include "BestSellerList.h"

// Constructor: Initializes an empty list.
BestSellerList::BestSellerList() {
    Head = nullptr;
    Tail = nullptr;
    Count = 0;
}

// Destructor: Cleans up dynamically allocated memory.
BestSellerList::~BestSellerList() {
    while (Head != nullptr) {
        BestSeller* temp = Head;
        Head = Head->getNext();  // Assuming you have a getNext() method in the BestSeller class
        delete temp;            // Delete the current node
    }
}

// Insert a new node at the head of the list.
void BestSellerList::InsertHead(int year, string week, int rank, int titleID, string title, string author) {
    BestSeller* newNode = new BestSeller(year, week, rank, titleID, title, author);
    if (Head == nullptr) {
        // If the list is empty, set both head and tail to the new node.
        Head = newNode;
        Tail = newNode;
    } else {
        // Otherwise, update the head and set the new node's next to the old head.
        newNode->setNext(Head);
        Head = newNode;
    }
    Count++;
}

// Insert a new node at the tail of the list.
void BestSellerList::InsertTail(int year, string week, int rank, int titleID, string title, string author) {
    BestSeller* newNode = new BestSeller(year, week, rank, titleID, title, author);
    if (Tail == nullptr) {
        // If the list is empty, set both head and tail to the new node.
        Head = newNode;
        Tail = newNode;
    } else {
        // Otherwise, update the next pointer of the current tail to the new node,
        // and set the new node as the new tail.
        Tail->setNext(newNode);
        Tail = newNode;
    }
    Count++;
}

// Insert a new node while maintaining sorted order based on author's name.
void BestSellerList::AuthorInsert(int year, string week, int rank, int titleID, string title, string author) {
    // Create a new node with the provided data.
    BestSeller* newNode = new BestSeller(year, week, rank, titleID, title, author);

    // If the list is empty or the new node should be inserted before the current head:
    if (Head == nullptr || author < Head->getAuthor()) {
        InsertHead(year, week, rank, titleID, title, author);
    } else {
        BestSeller* current = Head;
        BestSeller* previous = nullptr;

        // Find the appropriate position to insert the new node.
        while (current != nullptr && author >= current->getAuthor()) {
            previous = current;
            current = current->getNext();
        }

        // Insert the new node between previous and current.
        previous->setNext(newNode);
        newNode->setNext(current);

        Count++;
    }
}

// Insert a new node while maintaining sorted order based on the book's title.
void BestSellerList::TitleInsert(int year, string week, int rank, int titleID, string title, string author) {
    // Create a new node with the provided data.
    BestSeller* newNode = new BestSeller(year, week, rank, titleID, title, author);

    // If the list is empty or the new node should be inserted before the current head:
    if (Head == nullptr || title < Head->getTitle()) {
        InsertHead(year, week, rank, titleID, title, author);
    } else {
        BestSeller* current = Head;
        BestSeller* previous = nullptr;

        // Find the appropriate position to insert the new node.
        while (current != nullptr && title >= current->getTitle()) {
            previous = current;
            current = current->getNext();
        }

        // Insert the new node between previous and current.
        previous->setNext(newNode);
        newNode->setNext(current);

        Count++;
    }
}


// MostPopularBook Method
void BestSellerList::MostPopularBook() const {
    BestSeller* current = Head;
    string mostPopularTitle;
    int maxCount = 0;
    string currentTitle;
    int currentCount = 0;

    while (current != nullptr) {
        currentTitle = current->getTitle();

        if (currentTitle != mostPopularTitle) {
            if (currentCount > maxCount) {
                mostPopularTitle = currentTitle;
                maxCount = currentCount;
            }
            currentCount = 1;
        } else {
            currentCount++;
        }

        current = current->getNext();
    }

    cout << "Most Popular Book: " << mostPopularTitle << " (Appeared " << maxCount << " times)" << endl;
}

// MostProlificAuthor Method
void BestSellerList::MostProlificAuthor() const {
    BestSeller* current = Head;
    string mostProlificAuthor;
    int maxCount = 0;
    string currentAuthor;
    int currentCount = 0;

    while (current != nullptr) {
        currentAuthor = current->getAuthor();

        if (currentAuthor != mostProlificAuthor) {
            if (currentCount > maxCount) {
                mostProlificAuthor = currentAuthor;
                maxCount = currentCount;
            }
            currentCount = 1;
        } else {
            currentCount++;
        }

        current = current->getNext();
    }

    cout << "Most Prolific Author: " << mostProlificAuthor << " (Appeared " << maxCount << " times)" << endl;
}

void BestSellerList::Print() const {
    BestSeller* current = Head;

    while (current) {
        cout << "Year:    (" << current->getYear() << ")\n";
        cout << "Week:  (" << current->getWeek() << ")\n";
        cout << "Rank:     (" << current->getRank() << ")\n";
        cout << "Title ID:    (" << current->getTitleID() << ")\n";
        cout << "Title:   (" << current->getTitle() << ")\n";
        cout << "Author:   (" << current->getAuthor() << ")\n\n";
        
        current = current->getNext();
    }

    // Add a message to indicate the end of the list
    cout << "End of List." << endl;
}