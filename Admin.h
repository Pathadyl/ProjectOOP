#pragma once
#include <string>
#include<vector>
#include "register_user.h"
#include "Book.h"
#include "Collection.h"
using namespace std;

class Library;

#ifndef ADMIN_H
#define ADMIN_H

class Admin : public RegisterUser {
    private:
        vector<Book*> hideBookList;
    
    public: 
        Admin();

        Admin(int, string, string, int, string, string);

        ~Admin();

        void createAdmin(int, string, string, int, string, string);

        void addBook(Book* b);

        void removeBook(Book* b);

        void showBook(Book* b);

        void hideBook(Book* b);

        void editBook(string, int, int);

        int getHideBookIndex(Book* b);

        Book* getHideBookBySerial(string);

        vector<Book*> getHideBookList() const
            {return hideBookList;}

        void createCollection(string, int);

        void deleteCollection(Collection* c);

        void addBookCollection(Book* b, Collection* c);

        void removeBookCollection(Book* b, Collection* c);

};

#endif