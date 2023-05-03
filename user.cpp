#include <iostream>
#include "user.h"
#include "Library.h"
using namespace std;

User::User(){
    access = 0;
}

User::User(int access){
    this -> access = access;
}

void User::read(){
}

void User::searchByTitle(string title){
    cout << "You may be want to find this book in the library: " << endl;
    cout << "====================" << endl;
    for(int i = 0; i < Library::getInstance().getPublicBookList().size(); i++){
        if(Library::getInstance().getPublicBookList()[i]->getTitle() == title){
            Library::getInstance().getPublicBookList()[i]->printInfo();
        }
    } 
}       

void User::searchBySerial(string serial){
    cout << "You may be want to find this book in the library: " << endl;
    cout << "====================" << endl;
    for(int i = 0; i < Library::getInstance().getPublicBookList().size(); i++){
        if(Library::getInstance().getPublicBookList()[i]->getSerial() == serial){
            Library::getInstance().getPublicBookList()[i]->printInfo();
            break;
        }
    }
}


void User::setAccessibility(int access)
{
    this -> access = access;
}

