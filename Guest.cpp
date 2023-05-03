#include <iostream>
#include "Guest.h"
#include "Library.h"
#include "Book.h"
#include "Collection.h"
using namespace std;

Guest::Guest()
    :User()
{
    id = 0;
}

Guest::Guest(int access, int id)
    :User(access)
{
    this -> id = id;
}

void Guest::setId(int id){
    this -> id = id;
}

void Guest::read(){
    for(Book* b : Library::getInstance().getCollectionList()[0]->getBooks()){
        cout << "Title: " <<  b->getTitle() << " - Free page: " << b->getFreePage() << endl;
        cout << "=========================" << endl;
    }
}

Member Guest::inviteRegister(int access, string userName, string password, int id, string phone, string fullName){
    Member m(access, userName, password, id, phone, fullName);
    return m;
}

