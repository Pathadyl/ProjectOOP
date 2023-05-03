#pragma once
#include <vector>
#include <string>
// #include "Member.h"
#include "Book.h"
using namespace std;

class Member;

#ifndef  COLLECTION_H
#define COLLECTION_H

class Collection{
    private:
        string name;
        int id;
        vector<Book*> books;
        vector<Member*> listSubcribers;

    public:

        Collection();

        Collection(string, int);

        ~Collection();

        void setName(string);

        void setId(int);

        string getName() const
            {return name;}
        
        int getId() const
            {return id;}

        void addBook(Book*);

        void removeBook(Book*);

        void addSubscriber(Member*);

        void removeSubscriber(Member*);

        vector<Book*> getBooks() const
            {return books;}

        vector<Member*> getListSubcribers() const
            {return listSubcribers;}

        void showInfo();
};

#endif