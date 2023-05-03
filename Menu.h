#pragma once
#include <vector>
#include <string>
using namespace std;


class Menu {

    private:
        string name;

        string descript;

        vector<Menu*> subMenu;

        Menu* parentMenu;

        int action;

    public:
        Menu();

        Menu(string name, string descript, int action = -1);

        ~Menu();

        void setName(string name);

        void setDescript(string descript);

        void setAction(int action);

        int getAction() const 
            {return action;}
            
        string getName() const  
            {return name;}

        string getDescript() const
            {return descript;}

        void addSubMenu(Menu* m);

        Menu* getSubMenu(int index);

        void displayMenu();

        int promptOption(); //ask user for a choice

        bool isSubMenu();

        Menu* getParentMenu();

};