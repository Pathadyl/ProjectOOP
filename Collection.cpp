#include <iostream>
#include "Member.h"
#include "Collection.h"
using namespace std;

Collection::Collection(){
    name = "";
    id = 0;
}

Collection::Collection(string name, int id){
    this->name = name;
    this->id = id;
}

Collection::~Collection(){
    for(Book* b : books){
        delete b;
    }
    books.clear();

    for(Member* m : listSubcribers){
        delete m;
    }
    listSubcribers.clear();
}

void Collection::setName(string name){
    this->name = name;
}

void Collection::setId(int id){
    this->id = id;
}

void Collection::addBook(Book *b){
    books.push_back(b);
}

void Collection::removeBook(Book *b){
    for(int i = 0; i < books.size(); i++){
        if(books[i] == b){
            books.erase(books.begin() + i);
        }
    }
}

void Collection::addSubscriber(Member *m){
    listSubcribers.push_back(m);
}

void Collection::removeSubscriber(Member *m){
    for(int i = 0; i < listSubcribers.size(); i++){
        if(listSubcribers[i] == m){
            listSubcribers.erase(listSubcribers.begin() + i);
        }
    }
}

void Collection::showInfo(){
    cout << "Collection: " << name << " - ID: " << id << " - Num of books: " << books.size() << endl;

}


