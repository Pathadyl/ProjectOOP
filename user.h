#pragma once
#include <string>
using namespace std;

#ifndef USER_H
#define USER_H

class User{

    private:
        int access;

    public:
        User();

        User(int);

        virtual void read();

        void searchByTitle(string);

        void searchBySerial(string);

        void setAccessibility(int);

        int getAccessibility() const
            {return access;}

};

#endif