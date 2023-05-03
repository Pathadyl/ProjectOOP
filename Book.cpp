#include <iostream>
#include "Book.h"
using namespace std;

Book::Book(){
    title = "";
    serial = "";
    author = "";
    category = "";
    numPage = 0;
    freePage = 0;
}

Book::Book(string title, string serial, string author, string category, int numPage, int freePage){
    this -> title = title;
    this -> serial = serial;
    this -> author = author;
    this -> category = category;
    this -> numPage = numPage;
    this -> freePage = freePage;
}

void Book::setTitle(string title){
    this -> title = title;
}

void Book::setSerial(string serial){
    this -> serial = serial;
}

void Book::setAuthor(string author){
    this -> author = author;
}

void Book::setCategory(string category){
    this -> category = category;
}

void Book::setNumPage(int numPage){
    this -> numPage = numPage;
}

void Book::setFreePage(int freePage){
    this -> freePage = freePage;
}

void Book::printInfo(){
    cout << "Title: " << this->getTitle() << "\n"
         << "Author: " << this->getAuthor() << "\n"
         << "Category: " << this->getCategory() << "\n"
         << "Serial number: " << this->getSerial() << "\n"
         << "====================" << endl;
}
