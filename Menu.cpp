#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu(){
    name = "Default name";
    descript = "Default description";
    action = -1;
    parentMenu = nullptr;
    subMenu.clear();
}

Menu::Menu(string name, string descript, int action){
    this -> name = name;
    this -> descript = descript;
    this -> action = action;
    parentMenu = nullptr;
}

Menu::~Menu(){
    if(!subMenu.empty()){
        for(int i = 0; i < subMenu.size(); i++){
            if(subMenu[i])
                delete subMenu[i];
        }
        subMenu.clear();
    }
}

void Menu::setName(string name){
    this -> name = name;
}

void Menu::setDescript(string descript){
    this -> descript = descript;
}

void Menu::setAction(int action){
    this -> action = action;
}

void Menu::addSubMenu(Menu *m){
    // if(addParent = true){
    //     m->subMenu.push_back(this);
    // }
    m->parentMenu = this;
    this -> subMenu.push_back(m);
}

Menu *Menu::getSubMenu(int index){
    if(index > 0 && index <= subMenu.size()){
        index--;
        return subMenu[index];
    } else {
        return nullptr;
    }
}

void Menu::displayMenu(){
    system("cls");
    cout << "====" << this -> name << "====" << endl;
    cout << this -> descript << endl;
    for(int i = 0; i < subMenu.size(); i++){
        cout << i+1 << "." << subMenu[i] -> getName() << endl;
    }
}

int Menu::promptOption(){
    while(true){
        cout << "Pick an option: ";
        int option;
        cin >> option;
        try{
            if(cin.fail()){
                throw "Invalid input!";
            } else if(option < 1 || option > subMenu.size()){
                throw "Menu out of range!";
            } else {
                return option;
            }
        }
        catch(const char* n){
            cin.ignore();
            cin.clear();
            cout << "Error: " << n << endl;
        }

    }
}

bool Menu::isSubMenu(){
    return (subMenu.size() != 0);
}

Menu* Menu::getParentMenu(){
    return parentMenu;
}
