#pragma once
#include <vector>
#include "register_user.h"
#include "Book.h"
#include "Collection.h"
using namespace std;

class Library;

#ifndef MEMBER_H
#define MEMBER_H

class Member : public RegisterUser{
    private:
        int startYear;
        int endYear;
        vector<Book*> borrowList;
        vector<Collection*> subscribedCollections;

    public:
        Member();

        Member(int, string, string, int, string, string);

        ~Member();

        void borrowBook(string);

        void returnBook(string);

        vector<Book*> getBorrowList() const 
            {return borrowList;}

        vector<Collection*> getSubscribedCollections() const
            {return subscribedCollections;}

        void addBorrowList(Book*);

        void showBorrowList();
        
        void subscribe(Collection*);

        void unSubscribe(Collection*);

        void showBookListSubscribed(Collection*);

        // void read(Book*);





};

#endif