#include <iostream>
#include "Member.h"
#include "Library.h"
using namespace std;

Member::Member()
    :RegisterUser()
{
    startYear = 2022;
    endYear = 2024;
    Library::getInstance().addMember(this);
}

Member::Member(int access, string userName, string password, int id, string phone, string fullName)
    :RegisterUser(access, userName, password, id, phone, fullName)
{
    startYear = 2022;
    endYear = 2024;
    Library::getInstance().addMember(this);
}

Member::~Member(){
    for(Book* b  : borrowList){
        delete b;
    }
    borrowList.clear();
}

void Member::borrowBook(string serial){
    if(getPublicBookIndexBySerial(serial) != -1){
        Book* borrow = Library::getInstance().getBookBySerial(serial);
        borrowList.push_back(borrow);
        cout << "Borrow book success!" << endl;
    } else {
        cout << "This book is not available" << endl;
    }
}

void Member::returnBook(string serial){
    int index = getBorrowListIndexBySerial(serial);
    if(index != -1){
        borrowList.erase(borrowList.begin() + index);
        cout << "Return book success!" << endl;
    } else {
        cout << "This book is not in your borrow list" << endl;
    }
}

void Member::addBorrowList(Book *b){
    borrowList.push_back(b);
}

void Member::showBorrowList(){
    cout << "Here is the list of books you borrowed: " << endl;
    cout << "====================" << endl;
    for(Book*b : borrowList){
        b->printInfo();
    }
}

void Member::subscribe(Collection* c){
    c->addSubscriber(this);
    subscribedCollections.push_back(c);
}

void Member::unSubscribe(Collection* c){
    for(int i = 0; i < subscribedCollections.size(); i++){
        if(subscribedCollections[i] == c){
            subscribedCollections.erase(subscribedCollections.begin() + i);
            c->removeSubscriber(this);
        }
    }
}

void Member::showBookListSubscribed(Collection* c){
    for(Book* b : c->getBooks()){
        b->printInfo();
    }
}

int Member::getBorrowListIndexBySerial(string serial){
    for(int i = 0; i < borrowList.size(); i++){
        if(borrowList[i]->getSerial() == serial){
            return i;
            break;
        }
    }
    return -1;
}

int Member::getSubscribeCollectionIndexById(int id){
    for(int i = 0; i < subscribedCollections.size(); i++){
        if(subscribedCollections[i]->getId() == id){
            return i;
            break;
        }
    }
    return -1;
}




