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
    vector<int> index = getPublicBookIndexByTitle(title);
    if(!index.empty()){
        cout << "You may be want to find this book in the library: " << endl;
        cout << "====================" << endl;
        for(int i = 0; i < index.size(); i++){
            Library::getInstance().getPublicBookList()[index[i]]->printInfo();
        }
    } else {
        cout << "No such book in the library" << endl;
    }

}       

void User::searchBySerial(string serial){
    int index = getPublicBookIndexBySerial(serial);
    if(index != -1){
        cout << "You may be want to find this book in the library: " << endl;
        cout << "====================" << endl;
        Library::getInstance().getPublicBookList()[index]->printInfo();
    } else {
        cout << "No such book in the library" << endl;
    }

}


void User::setAccessibility(int access)
{
    this -> access = access;
}

int User::getPublicBookIndexBySerial(string serial){
    for(int i = 0; i < Library::getInstance().getPublicBookList().size(); i++){
        if(Library::getInstance().getPublicBookList()[i]->getSerial() == serial){
            return i;
        }
    }
    return -1;
}


vector<int> User::getPublicBookIndexByTitle(string title){
    vector<int> index;
    for(int i = 0; i < Library::getInstance().getPublicBookList().size(); i++){
        if(Library::getInstance().getPublicBookList()[i]->getTitle() == title){
            index.push_back(i);
        }
    }
    return index;
}
