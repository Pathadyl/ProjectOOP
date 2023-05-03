#pragma once
#include <string>
using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book{
    private:
        string title;
        string serial;
        string author;
        string category;
        int numPage;
        int freePage;
    public:
        Book();

        Book(string, string, string, string, int, int);

        void setTitle(string);

        string getTitle() const
            {return title;}

        void setSerial(string);

        string getSerial() const
            {return serial;}
        
        void setAuthor(string);

        string getAuthor() const
            {return author;}

        void setCategory(string);

        string getCategory() const
            {return category;}

        void setNumPage(int);

        int getNumPage() const
            {return numPage;}

        void setFreePage(int);

        int getFreePage() const
            {return freePage;}

        void printInfo();




};

#endif