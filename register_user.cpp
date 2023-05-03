#include <iostream>
#include "register_user.h"
using namespace std;

int RegisterUser::userCount = 0;

RegisterUser::RegisterUser()
    :User()
{
    userName = "";
    password = "";
    id = 0;
    phone = "";
    fullName = "";
    userCount++;
}

RegisterUser::RegisterUser(int access, string userName, string password, int id, string phone, string fullName)
    :User(access)
{
    this -> userName = userName;
    this -> password = password;
    this -> id = id;
    this -> phone = phone;
    this -> fullName = fullName;
    userCount++;
}

void RegisterUser::setUserName(string userName)
{
    this -> userName = userName;
}

void RegisterUser::setPassword(string password){
    this -> password = password;
}

void RegisterUser::setId(int id){
    this -> id = id;
}

void RegisterUser::setPhone(string phone){
    this -> phone = phone;
}

void RegisterUser::setFullName(string fullName){
    this -> fullName = fullName;
}

void RegisterUser::read(Book *b){
    cout << "Title: " <<  b->getTitle() << " - Num page: " << b->getNumPage() << endl;
    cout << "=========================" << endl;
}

RegisterUser::~RegisterUser()
{
    userCount--;
}



