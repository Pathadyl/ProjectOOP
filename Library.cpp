#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

Library* Library::instance = nullptr;

Library::Library(){}

Library::~Library(){
    // free memory allocated for member objects in memberList
    for (Member* member : memberList) {
        delete member;
    }
    memberList.clear();

    for(Admin* admin : adminList) {
        delete admin;
    }
    adminList.clear();

    for(Book* book : publicBookList) {
        delete book;
    }
    publicBookList.clear();

    for(Collection* collection : collectionList) {
        delete collection;
    }
    collectionList.clear();

    delete instance;
}

Library& Library::getInstance(){
    if (instance == nullptr) {
        instance = new Library();
    }
    return *instance;
}

Member* Library::memberLogin(string username, string password){
    for (Member* member : memberList) {
        if (member->getUserName() == username && member->getPassword() == password) {
            return member;
        }
    }
    return nullptr;
}

Admin * Library::adminLogin(string username, string password){
    for (Admin* admin : adminList) {
        if(admin->getUserName() == username && admin->getPassword() == password){
            return admin;
        }
    }
    return nullptr;
}

void Library::addMember(Member* member){
    memberList.push_back(member);
}

void Library::addAdmin(Admin * admin){
    adminList.push_back(admin);
}

void Library::addPublicBook(Book * b, Admin* a){
    if(isAdmin(a)){
        publicBookList.push_back(b);
    } else {
        cout << "Access denied! Only admin can modify book list." << endl;
    }
}

void Library::removePublicBook(Book* b, Admin* a){
    if(isAdmin(a)){
        publicBookList.erase(publicBookList.begin() + getBookIndex(b));
    } else {
        cout << "Access denied! Only admin can modify book list." << endl;
    }
}

void Library::addCollection(Collection *c, Admin *a){
    if(isAdmin(a)){
        collectionList.push_back(c);
    } else {
        cout << "Access denied! Only admin can modify collection list." << endl;
    }
}

void Library::removeCollection(Collection *c, Admin *a){
    if(isAdmin(a)){
        collectionList.erase(collectionList.begin() + getCollectionIndex(c));
    } else {
        cout << "Access denied! Only admin can modify collection list." << endl;
    }
}

bool Library::isAdmin(Admin* a){
    for (int i = 0; i < adminList.size(); i++){
        if(adminList[i] == a){ 
            return true;
            break;
        }
    }
    return false;
}

int Library::getBookIndex(Book* b){
    for(int i = 0; i < publicBookList.size(); i++){
        if(publicBookList[i] == b){
            return i;
            break;
        }
    }
    return -1;
}

int Library::getCollectionIndex(Collection *c){
    for(int i = 0; i < collectionList.size(); i++){
        if(collectionList[i] == c){
            return i;
            break;
        }
    }
    return -1;
}

Book* Library::getBookBySerial(string Serial){
    for(Book* b : publicBookList){
        if(b->getSerial() == Serial){
            return b;
            break;
        }
    }
    return nullptr;
}

Collection * Library::getCollectionById(int id){
    for(Collection* c : collectionList){
        if(c->getId() == id){
            return c;
            break;
        }
    }
    return nullptr;
}


void Library::showCollectionList(){
    for(int i = 0; i < collectionList.size(); i++){
        cout << i + 1 << ". ";
        collectionList[i]->showInfo();
    }
}