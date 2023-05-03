#pragma once
#include <string>
#include "user.h"
#include "Book.h"
using namespace std;


#ifndef REGISTER_USER_H
#define REGISTER_USER_H

class RegisterUser : public User {
    private:
        string userName;
        string password;
        int id;
        string phone;
        string fullName;
        static int userCount;

    public:
        RegisterUser();

        RegisterUser(int, string, string, int, string, string);

        void setUserName(string);

        string getUserName() const
            {return userName;}

        void setPassword(string);

        string getPassword() const 
            {return password;}

        void setId(int);

        int getId() const 
            {return id;}

        void setPhone(string);

        string getPhone() const 
            {return phone;}

        void setFullName(string);

        string getFullName() const 
            {return fullName;}

        void read(Book*);

        ~RegisterUser();

        

};

#endif