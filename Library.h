#pragma once
#include <string>
#include <vector>
#include "Member.h"
#include "Admin.h"
#include "Book.h"
#include "Collection.h"
using namespace std;

#ifndef LIBRARY_H
#define LIBRARY_H

class Library {
    private:
        static Library* instance;
        vector<Member*> memberList;
        vector<Admin*> adminList;
        vector<Book*> publicBookList;
        vector<Collection*> collectionList;
        Library();
    public: 
        
        static Library& getInstance();

        ~Library();

        Member* memberLogin(string, string);

        Admin* adminLogin(string, string);

        void addMember(Member*);

        void addAdmin(Admin*);

        void addPublicBook(Book*, Admin*);

        void removePublicBook(Book*, Admin*);

        void addCollection(Collection*, Admin*);

        void removeCollection(Collection*, Admin*);

        vector<Member*> getMemberList() const
            {return memberList;}

        vector<Admin*> getAdminList() const
            {return adminList;}

        vector<Book*> getPublicBookList() const
            {return publicBookList;}

        vector<Collection*> getCollectionList() const
            {return collectionList;}

        bool isAdmin(Admin*);
        
        int getBookIndex(Book*);

        int getCollectionIndex(Collection*);

        Book* getBookBySerial(string);

        Collection* getCollectionById(int);

        void showCollectionList();
        
};


#endif