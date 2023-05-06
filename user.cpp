#include "user.h"
#include "Library.h"
#include <iostream>
using namespace std;

User::User() { access = 0; }

User::User(int access) { this->access = access; }

void User::read() {}

void User::searchByTitle(string title) {
    cout << "You may be want to find this book in the library: " << endl;
    cout << "====================" << endl;
    vector<Book *> matchedBooks;

    for (Book *book : Library::getInstance().getPublicBookList()) {
        if (book->getTitle().find(title) != string::npos) {
            matchedBooks.push_back(book);
        }
    }

    for (Book *book : matchedBooks) {
        book->printInfo();
    }

    if (!matchedBooks.size()) {
        cout << "No such book in the library!" << endl;
    }
}

void User::searchBySerial(string serial) {
    cout << "You may be want to find this book in the library: " << endl;
    cout << "====================" << endl;
    vector<Book *> matchedBooks;
    for (Book *book : Library::getInstance().getPublicBookList()) {
        if (book->getSerial().find(serial) != string::npos) {
            matchedBooks.push_back(book);
        }
    }
    for (Book *book : matchedBooks) {
        book->printInfo();
    }

    if (!matchedBooks.size()) {
        cout << "No such book in the library!" << endl;
    }
}

void User::setAccessibility(int access) { this->access = access; }

int User::getPublicBookIndexBySerial(string serial) {
    for (int i = 0; i < Library::getInstance().getPublicBookList().size();
         i++) {
        if (Library::getInstance().getPublicBookList()[i]->getSerial() ==
            serial) {
            return i;
        }
    }
    return -1;
}

vector<int> User::getPublicBookIndexByTitle(string title) {
    vector<int> index;
    for (int i = 0; i < Library::getInstance().getPublicBookList().size();
         i++) {
        if (Library::getInstance().getPublicBookList()[i]->getTitle() ==
            title) {
            index.push_back(i);
        }
    }
    return index;
}
