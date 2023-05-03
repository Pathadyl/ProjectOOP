#include <iostream>
#include <string>
#include "Admin.h"
#include "Library.h"
using namespace std;

Admin::Admin()
    :RegisterUser()
{
    Library::getInstance().addAdmin(this);

}

Admin::Admin(int access, string userName, string password, int id, string phone, string fullName)
    :RegisterUser(access, userName, password, id, phone, fullName)
{
    Library::getInstance().addAdmin(this);

}

Admin::~Admin()
{
    for(Book* b : hideBookList){
        delete b;
    }
    hideBookList.clear();
}

void Admin::createAdmin(int access, string userName, string password, int id, string phone, string fullName){
    Admin a(access, userName, password, id, phone, fullName);
}

void Admin::addBook(Book* b){
    Library::getInstance().addPublicBook(b, this);
}

void Admin::removeBook(Book* b){
    Library::getInstance().removePublicBook(b, this);
}

void Admin::showBook(Book* b){
    if(!hideBookList.empty()){
        Book* book = hideBookList[getHideBookIndex(b)];
        hideBookList.erase(hideBookList.begin() + getHideBookIndex(b));
        Library::getInstance().addPublicBook(book, this);
    } else {
        Library::getInstance().addPublicBook(b, this);
    }
}

void Admin::hideBook(Book* b){
    int index = Library::getInstance().getBookIndex(b);
    Book* book = Library::getInstance().getPublicBookList()[index];
    this->removeBook(b);
    hideBookList.push_back(book);
}

void Admin::editBook(string serial, int numPage, int freePage){
    if(Library::getInstance().getBookBySerial(serial)){
        Library::getInstance().getBookBySerial(serial)->setNumPage(numPage);
        Library::getInstance().getBookBySerial(serial)->setFreePage(freePage);
    }
}

void Admin::createCollection(string name, int id){
    Collection* c = new Collection(name, id);
    Library::getInstance().addCollection(c, this);
}

void Admin::deleteCollection(Collection* c){
    Library::getInstance().removeCollection(c, this);
}

void Admin::addBookCollection(Book *b, Collection *c){
    c->addBook(b);
}

void Admin::removeBookCollection(Book *b, Collection *c){
    c->removeBook(b);
}

int Admin::getHideBookIndex(Book * b){
    for(int i = 0; i < hideBookList.size(); i++){
        if(hideBookList[i] == b){
            return i;
            break;
        }
    }
    return -1;
}



