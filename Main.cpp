#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "register_user.h"
#include "Member.h"
#include "Admin.h"
#include "Guest.h"
#include "Book.h"
#include "Collection.h"
#include "Menu.h"
#include "Library.h"
using namespace std;

enum ACTIONTYPE {GUEST_READ, GUEST_SEARCH_TITLE, GUEST_SEARCH_SERIAL, REGISTER, EXIT, LOGIN_MEMBER, LOGIN_ADMIN, LOGOUT, 
                 CREATE_ADMIN, ADD_BOOK, SHOW_BOOK, HIDE_BOOK, REMOVE_BOOK, EDIT_BOOK, CREATE_COLLECTION, DELETE_COLLECTION, 
                 ADD_BOOK_COLLECTION, REMOVE_BOOK_COLLECTION, ADMIN_READ, ADMIN_SEARCH_TITLE, ADMIN_SEARCH_SERIAL,
                 MEMBER_READ, MEMBER_SEARCH_TITLE, MEMBER_SEARCH_SERIAL, BORROW_LIST, BORROW_BOOK, RETURN_BOOK,
                 SHOW_COLLECTION, SHOW_BOOK_LIST_COLLECTION, SUBSCRIBE_COLLECTION, UNSUBSCRIBE_COLLECTION};

bool isValidSerial(const string& serial) {
    if (serial.size() != 6) {
        return false;
    }
    for (char c : serial) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

string getValidSerial() {
    string serial;
    do {
        cin >> serial;
        if(!isValidSerial(serial)){
            cout << "Invalid serial, please try again: ";
        } 
    } while (!isValidSerial(serial));

    return serial;
}

int main(){

    Library& library = Library::getInstance();

// Default sample collection:
    Collection* c = new Collection("Sample", 0);
        Book* b1 = new Book("Book1", "123456", "Author1", "Culture", 400, 10);
        Book* b2 = new Book("Book2", "123457", "Author2", "Science", 450, 10);
        Book* b3 = new Book("Book3", "123458", "Author3", "Comedy", 500, 10);
    c->addBook(b1); c->addBook(b2); c->addBook(b3);

// Default user:
    Member* m = new Member(1, "dylan245", "12345", 14, "0906159559", "Pham Thanh Dat");
    Admin* a = new Admin(2, "admin01", "abcdef", 1, "0906159559", "Dylan Pham");
    library.addCollection(c, a);
    m->subscribe(c);

// Add books in sample book in bookList:
    a->addBook(b1); a->addBook(b2); a->addBook(b3);

// Current user:
    Guest g;
    Member* currentMember = nullptr;
    Admin* currentAdmin = nullptr;

//General menu
    Menu* logOut = new Menu("LOG OUT", "Thank you for using our service!", LOGOUT);
    Menu* registerReadMenu = new Menu("READING SECTION FOR REGISTERED USER","Read Book");
    Menu* exitMenu = new Menu("EXIT LIBRARY", "Bye!", EXIT);
    
//Main Menu
    Menu* mainMenu = new Menu("ONLINE LIBRARY", "Guess Loby");
        Menu* guestReadMenu = new Menu("READING SECTION FOR GUESS", "Read Book", GUEST_READ);
        Menu* guestSearchMenu = new Menu("GUESS SEARCHING BOOK", "Choose kind of method to search");
            Menu* guestSearchTitleMenu = new Menu("SEARCHING BOOK BY TITLE", "Please enter book title", GUEST_SEARCH_TITLE);
            Menu* guestSearchSerialMenu = new Menu("SEARCHING BOOK BY SERIAL", "Please enter book serial", GUEST_SEARCH_SERIAL);
        guestSearchMenu->addSubMenu(guestSearchTitleMenu);
        guestSearchMenu->addSubMenu(guestSearchSerialMenu);
        guestSearchMenu->addSubMenu(mainMenu);
        Menu* loginMenu = new Menu("USER LOGIN", "Please login");
        Menu* userRegisterMenu = new Menu("USER REGISTER", "Please enter your information", REGISTER);
    mainMenu->addSubMenu(guestReadMenu);
    mainMenu->addSubMenu(guestSearchMenu);
    mainMenu->addSubMenu(loginMenu);
    mainMenu->addSubMenu(userRegisterMenu);
    mainMenu->addSubMenu(exitMenu);

// Login Menu
    Menu* loginAdminMenu = new Menu("ADMIN LOGIN", "Please login", LOGIN_ADMIN);
    Menu* loginMemberMenu = new Menu("MEMBER LOGIN", "Please login", LOGIN_MEMBER);
    loginMenu->addSubMenu(loginAdminMenu);
    loginMenu->addSubMenu(loginMemberMenu);
    loginMenu->addSubMenu(mainMenu);

// Member Menu
    Menu* memberMenu = new Menu("MEMBER SECTION", "Welcome to member section");
        Menu* memberReadMenu = new Menu("READING MEMBER SECTION", "Read Book");
            Menu* readBookMenu = new Menu("READ BOOK", "Read book", MEMBER_READ);
            Menu* collectionMenu = new Menu("COLLECTION SECTION", "List of collections", SHOW_COLLECTION);
            Menu* showListBookCollectionSubcribe = new Menu("BOOK LIST COLLECTION SUBSCRIBE", "List of books in collection", SHOW_BOOK_LIST_COLLECTION);
        memberReadMenu->addSubMenu(readBookMenu);
        memberReadMenu->addSubMenu(collectionMenu);
        memberReadMenu->addSubMenu(showListBookCollectionSubcribe);
        memberReadMenu->addSubMenu(memberMenu);

        Menu* memberSearchMenu = new Menu("MEMBER SEARCHING SECTION", "Choose kind of method to search");
            Menu* memberSearchTitleMenu = new Menu("SEARCHING BOOK BY TITLE", "Please enter book title", MEMBER_SEARCH_TITLE);
            Menu* memberSearchSerialMenu = new Menu("SEARCHING BOOK BY SERIAL", "Please enter book serial", MEMBER_SEARCH_SERIAL);
        memberSearchMenu->addSubMenu(memberSearchTitleMenu);
        memberSearchMenu->addSubMenu(memberSearchSerialMenu);
        memberSearchMenu->addSubMenu(memberMenu);
    
        Menu* borrowListMenu = new Menu("BORROW LIST", "list of borrowed books", BORROW_LIST);
        Menu* serviceMenu = new Menu("SERVICE SECTION", "Choose kind of service");
            Menu* borrowBookMenu = new Menu("BORROW BOOK", "Borrow book", BORROW_BOOK);
            Menu*  returnBookMenu = new Menu("RETURN BOOK", "Return book", RETURN_BOOK);
            Menu* subscribedCollectionMenu = new Menu("SUBSCRIBE COLLECTION", "Member subscribes collection", SUBSCRIBE_COLLECTION);
            Menu* unSubsribedCollectionMenu = new Menu("UNSUBSCRIBE COLLECTION", "Member unsubscribes collection", UNSUBSCRIBE_COLLECTION);
        serviceMenu->addSubMenu(borrowBookMenu);
        serviceMenu->addSubMenu(returnBookMenu);
        serviceMenu->addSubMenu(subscribedCollectionMenu);
        serviceMenu->addSubMenu(unSubsribedCollectionMenu);
        serviceMenu->addSubMenu(memberMenu);

    memberMenu->addSubMenu(memberReadMenu);
    memberMenu->addSubMenu(memberSearchMenu);
    memberMenu->addSubMenu(serviceMenu);
    memberMenu->addSubMenu(borrowListMenu);
    memberMenu->addSubMenu(logOut);
    memberMenu->addSubMenu(exitMenu);

// Admin Menu
    Menu* adminMenu = new Menu("ADMIN SECTION", "Welcome to admin section");
        Menu* createAdminMenu = new Menu("CREATE ADMIN", "Create admin", CREATE_ADMIN);
        Menu* adminReadMenu = new Menu("READING ADMIN SECTION", "Read Book", ADMIN_READ);
        Menu* adminSearchMenu = new Menu("ADMIN SEARCHING SECTION", "Choose kind of method to search");
            Menu* adminSeachTitle = new Menu("SEARCHING BOOK BY TITLE", "Please enter book title", ADMIN_SEARCH_TITLE);
            Menu* adminSearchSerial = new Menu("SEARCHING BOOK BY SERIAL", "Please enter book serial", ADMIN_SEARCH_SERIAL);
        adminSearchMenu->addSubMenu(adminSeachTitle);
        adminSearchMenu->addSubMenu(adminSearchSerial);
        adminSearchMenu->addSubMenu(adminMenu);
        Menu* manageBookMenu = new Menu("MANAGEMENT BOOK SECTION", "Choose manage action!");
            Menu* addBookMenu = new Menu("ADD BOOK", "Add book", ADD_BOOK);
            Menu* removeBookMenu = new Menu("REMOVE BOOK", "Remove book", REMOVE_BOOK);
            Menu* showBookMenu = new Menu("SHOW BOOK", "Show book", SHOW_BOOK);
            Menu* hideBookMenu = new Menu("HIDE BOOK", "Hide book", HIDE_BOOK);
            Menu* editBookMenu = new Menu("EDIT BOOK", "Edit book", EDIT_BOOK);
        manageBookMenu->addSubMenu(addBookMenu);
        manageBookMenu->addSubMenu(showBookMenu);
        manageBookMenu->addSubMenu(hideBookMenu);
        manageBookMenu->addSubMenu(removeBookMenu);
        manageBookMenu->addSubMenu(editBookMenu);
        manageBookMenu->addSubMenu(adminMenu);

        Menu* manageCollectionMenu = new Menu("MANAGEMENT COLLECTION SECTION", "Choose manage action!");
            Menu* createCollectionMenu = new Menu("CREATE COLLECTION", "Create collection", CREATE_COLLECTION);
            Menu* deleteCollectionMenu = new Menu("DELETE COLLECTION", "Delete collection", DELETE_COLLECTION);
            Menu* addBookCollection = new Menu ("ADD BOOK TO COLLECTION", "Add book to collection", ADD_BOOK_COLLECTION);
            Menu* removeBookCollection = new Menu ("REMOVE BOOK FROM COLLECTION", "Remove book from collection", REMOVE_BOOK_COLLECTION);
        manageCollectionMenu->addSubMenu(createCollectionMenu);
        manageCollectionMenu->addSubMenu(deleteCollectionMenu);
        manageCollectionMenu->addSubMenu(addBookCollection);
        manageCollectionMenu->addSubMenu(removeBookCollection);
        manageCollectionMenu->addSubMenu(adminMenu);
    
    adminMenu->addSubMenu(adminReadMenu);
    adminMenu->addSubMenu(adminSearchMenu);
    adminMenu->addSubMenu(manageBookMenu);
    adminMenu->addSubMenu(manageCollectionMenu);
    adminMenu->addSubMenu(createAdminMenu);
    adminMenu->addSubMenu(logOut);
    adminMenu->addSubMenu(exitMenu);
    
// Start

    Menu* currentMenu = mainMenu;

    while(true){
        currentMenu->displayMenu();
        int opt = currentMenu->promptOption();
        currentMenu = currentMenu->getSubMenu(opt);

        switch (currentMenu->getAction()){
        case -1:
            break;
//==============================GUESS SECTION====================================//
        case GUEST_READ:
            currentMenu->displayMenu();
            g.read();
            system("pause");
            currentMenu = mainMenu;
            break;

        case GUEST_SEARCH_TITLE:
        {
            currentMenu->displayMenu();
            string bookTitle; cin.ignore();
            cout << "Enter book title: "; getline(cin, bookTitle);
            g.searchByTitle(bookTitle);
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;
        
        case GUEST_SEARCH_SERIAL:
        {
            currentMenu->displayMenu();
            string bookSerial; cin.ignore();
            cout << "Enter book serial: "; bookSerial = getValidSerial();
            g.searchBySerial(bookSerial);
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case REGISTER:
        {    
            currentMenu->displayMenu();
            char ch;
            string registerName, registerPhone, registerUserName, registerPassword;
            int id = library.getMemberList().back()->getId()+ 1;

            cin.ignore();
            cout << "Full name: "; getline(cin, registerName);
            cout << "Phone number: "; getline(cin, registerPhone);
            cout << "User Name: "; getline(cin, registerUserName);
            cout << "Password: "; getline(cin, registerPassword);

            g.inviteRegister(1, registerUserName, registerPassword, id, registerPhone, registerName);
            cout << "Register success! Press  any key to continue: "; cin.get(ch);
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case EXIT:
            cout << "Exit the library" << endl;
            exit(0);
            break;

    //=========================LOGIN - LOGOUT SECTION===================//

        case LOGIN_MEMBER:
        {
            currentMenu->displayMenu();
            string username, password;
            char ch;

            cin.ignore();
            cout << "Username: "; getline(cin, username);
            cout << "Password: "; getline(cin, password);
                
            currentMember = library.memberLogin(username, password);
            if(currentMember){
                cout << "Login success! Press any key to continue: "; cin.get(ch);
                currentMenu = memberMenu;
            } else {
                cout << "Invalid username or password! Press any key to continue: "; cin.get(ch);
                currentMenu = currentMenu->getParentMenu();
            }

        }
            break;
        
        case LOGIN_ADMIN:
        {
            currentMenu->displayMenu();
            string username, password;
            char ch;

            cin.ignore();
            cout << "Username: "; getline(cin, username);
            cout << "Password: "; getline(cin, password);
                
            currentAdmin = library.adminLogin(username, password);
            if(currentAdmin){
                cout << "Login success! Press any key to continue: "; cin.get(ch);
                currentMenu = adminMenu;
            } else {
                cout << "Invalid username or password! Press any key to continue: ";
                cin.get(ch);
                currentMenu = currentMenu->getParentMenu();
            }

        }
            break;

        case LOGOUT:
            currentMenu->displayMenu();
            currentMember = nullptr;
            currentAdmin = nullptr;
            currentMenu = mainMenu;
            break;

        //==============================MEMBER SECTION====================================//

        case MEMBER_READ:
        {
            currentMenu->displayMenu();
            string bookSerial; cin.ignore();

            cout << "Enter book serial you want to read: "; bookSerial = getValidSerial();
            if(library.getBookBySerial(bookSerial) != nullptr){
                currentMember->read(library.getBookBySerial(bookSerial));
            } else {
                cout << "The book does not exist!" << endl;
            }
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case MEMBER_SEARCH_TITLE:
        {
            currentMenu->displayMenu();
            string bookTitle; cin.ignore();
            cout << "Enter book title: "; getline(cin, bookTitle);
            currentMember->searchByTitle(bookTitle);
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case MEMBER_SEARCH_SERIAL:
        {
            currentMenu->displayMenu();
            string bookSerial; cin.ignore();
            cout << "Enter book serial: "; bookSerial = getValidSerial();
            currentMember->searchBySerial(bookSerial);
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case SHOW_COLLECTION:
            currentMenu->displayMenu();
            library.showCollectionList();
            system("pause");
            currentMenu = currentMenu->getParentMenu();
            break;

        case SHOW_BOOK_LIST_COLLECTION:
        {   
            currentMenu->displayMenu();
            int collectionID;

            cout << "Enter collection ID you want to see its list of books: "; cin >> collectionID;
            int index = currentMember->getSubscribeCollectionIndexById(collectionID);
            if(index != -1){
                for(Book* b : currentMember->getSubscribedCollections()[index]->getBooks()){
                    b->printInfo();
                }
            } else {
                cout << "You are not subscribed this collection!" << endl;
            }
                system("pause");
                currentMenu = currentMenu->getParentMenu();
        }
            break;

        case BORROW_BOOK:
        {
            currentMenu->displayMenu();
            string bookSerial; cin.ignore();
            cout << "Enter book serial you want to borrow: "; bookSerial = getValidSerial();
            currentMember->borrowBook(bookSerial);
            system("pause");
            currentMenu = currentMenu->getParentMenu();

        }
            break;
        
        case RETURN_BOOK:
        {
            currentMenu->displayMenu();
            string bookSerial; cin.ignore();
            cout << "Enter book serial you want to return: "; bookSerial = getValidSerial();
            currentMember->returnBook(bookSerial);
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case BORROW_LIST:
            currentMenu->displayMenu(); 
            currentMember->showBorrowList();
            system("pause");
            currentMenu = currentMenu->getParentMenu();
            break;

        case SUBSCRIBE_COLLECTION:
        {    currentMenu->displayMenu();
            int collectionID;

            cout << "Enter collection ID you want to subscribe: "; cin >> collectionID;
            
            if(library.getCollectionById(collectionID) != nullptr){
                currentMember->subscribe(library.getCollectionById(collectionID));
                cout << "Subscribe collection success!" << endl;
            } else {
                cout << "This collection does not exist!" << endl;
            }
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case UNSUBSCRIBE_COLLECTION:
        {   
            currentMenu->displayMenu();
            int collectionID;

            cout << "Enter collection ID you want to unsubscribe: "; cin >> collectionID;

            int index = currentMember->getSubscribeCollectionIndexById(collectionID);
            if(index != -1){
                if(currentMember->getSubscribedCollections()[index] == library.getCollectionById(collectionID)){
                    currentMember->unSubscribe(library.getCollectionById(collectionID));
                    cout << "Unscribed collection success!" << endl;
                    system("pause");
                } else {
                    cout << "Error!" << endl;
                    system("pause");
                }
            } else {
                cout << "You have not subscribed this collection!" << endl;
                system("pause");
            }
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        //=========================== ADMIN SECTION ==========================//

        case ADMIN_READ:
        {
            currentMenu->displayMenu();
            string bookSerial; cin.ignore();

            cout << "Enter book serial you want to read: "; bookSerial = getValidSerial();
            if(library.getBookBySerial(bookSerial) != nullptr){
                currentAdmin->read(library.getBookBySerial(bookSerial));
            } else {
                cout << "The book does not exist!" << endl;
            }
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case ADMIN_SEARCH_TITLE:
        {
            currentMenu->displayMenu();
            string bookTitle; cin.ignore();
            cout << "Enter book title: "; getline(cin, bookTitle);
            currentAdmin->searchByTitle(bookTitle);
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case ADMIN_SEARCH_SERIAL:
        {
            currentMenu->displayMenu();
            string bookSerial; cin.ignore();
            cout << "Enter book title: "; bookSerial = getValidSerial();
            currentAdmin->searchBySerial(bookSerial);
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case CREATE_ADMIN:
        {    
            currentMenu->displayMenu();
            char ch;
            string adminName, adminPhone, adminUserName, adminPassword;
            int id = library.getAdminList().back()->getId()+ 1;

            cin.ignore();
            cout << "Full name: "; getline(cin, adminName);
            cout << "Phone number: "; getline(cin, adminPhone);
            cout << "User Name: "; getline(cin, adminUserName);
            cout << "Password: "; getline(cin, adminPassword);

            currentAdmin->createAdmin(1, adminName, adminPhone, id, adminUserName, adminPassword);
            cout << "Create admin success! Press any key to continue: "; cin.get(ch);
            currentMenu = currentMenu->getParentMenu();
        }
        
        case ADD_BOOK:
        {
            currentMenu->displayMenu();
            string bookTitle, bookSerial, bookAuthor, bookCategory;
            int numBookPage, numFreePage;

            cin.ignore();
            cout << "Enter book title: "; getline(cin, bookTitle);
            cout << "Enter book serial: "; bookSerial = getValidSerial();
            cout << "Enter book author: "; getline(cin, bookAuthor);
            cout << "Enter book category: "; getline(cin, bookCategory);
            cout << "Enter number of book page: "; cin >> numBookPage;
            cout << "Enter number of free page: "; cin >> numFreePage;
            Book* newBook = new Book(bookTitle, bookSerial, bookAuthor, bookCategory, numBookPage, numFreePage);
            currentAdmin->addBook(newBook);
            cout << "Add book success!" << endl;
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case REMOVE_BOOK:
        {
            currentMenu->displayMenu();
            string bookSerial;

            cin.ignore();
            cout << "Enter book serial you want to remove: "; bookSerial = getValidSerial();
            if(library.getBookBySerial(bookSerial) == nullptr){
                currentAdmin->removeBook(library.getBookBySerial(bookSerial));
                cout << "Remove book success!" << endl;
            } else {
                cout << "This book does not exist!" << endl;
            }
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case SHOW_BOOK:
        {
            currentMenu->displayMenu();
            string bookSerial;

            cin.ignore();
            cout << "Enter book serial you want to show publicly: "; bookSerial = getValidSerial();
            if(library.getBookBySerial(bookSerial) == nullptr){
                currentAdmin->showBook(library.getBookBySerial(bookSerial));
                cout << "Show book success!" << endl;
            } else {
                cout << "This book does not exist!" << endl;
            }
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case HIDE_BOOK:
        {
            currentMenu->displayMenu();
            string bookSerial;

            cin.ignore();
            cout << "Enter book serial you want to hide: "; bookSerial = getValidSerial();
            if(library.getBookBySerial(bookSerial) == nullptr){
                currentAdmin->hideBook(library.getBookBySerial(bookSerial));
                cout << "Hide book success!" << endl;
            } else {
                cout << "This book does not exist!" << endl;
            }
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case EDIT_BOOK:
        {
            currentMenu->displayMenu();
            string bookSerial;
            int numBookPage, numFreePage;

            cin.ignore();
            cout << "Enter book serial you want to edit: "; bookSerial = getValidSerial();
            cout << "Enter number of book page: "; cin >> numBookPage;
            cout << "Enter number of free page: "; cin >> numFreePage;
            currentAdmin->editBook(bookSerial, numBookPage, numFreePage);
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;
        
        case CREATE_COLLECTION:
        {
            currentMenu->displayMenu();
            string collectionName; int collectionId;

            cin.ignore();
            cout << "Enter collection name: "; getline(cin, collectionName);
            collectionId = library.getCollectionList().back()->getId() + 1;
            currentAdmin->createCollection(collectionName, collectionId);
            cout << "Create collection success!" << endl;
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case DELETE_COLLECTION:
        {
            currentMenu->displayMenu();
            int collectionId;

            cout << "Enter collection id you want to delete: "; cin >> collectionId;
            if(library.getCollectionById(collectionId) != nullptr){
                currentAdmin->deleteCollection(library.getCollectionById(collectionId));
                cout << "Delete collection success!" << endl;
            } else {
                cout << "This collection does not exist!" << endl;
            }
            system("pause");
            currentMenu = currentMenu->getParentMenu();
            
        }
         break;

        case ADD_BOOK_COLLECTION:
        {
            currentMenu->displayMenu();
            int collectionId;
            string bookSerial;

            cout << "Enter collection id: "; cin >> collectionId;
            if(library.getCollectionById(collectionId) != nullptr){
                cin.ignore();
                cout << "Enter book serial: "; bookSerial = getValidSerial();
                currentAdmin->addBookCollection(library.getBookBySerial(bookSerial), library.getCollectionById(collectionId));
                cout << "Add book to collection success!" << endl;
            } else {
                cout << "This collection does not exist!" << endl;
            }
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;

        case REMOVE_BOOK_COLLECTION:
        {
            currentMenu->displayMenu();
            int collectionId;
            string bookSerial;

            cout << "Enter collection id: "; cin >> collectionId;
            if(library.getCollectionById(collectionId) != nullptr){
                cin.ignore();
                cout << "Enter book serial: "; bookSerial = getValidSerial();
                currentAdmin->removeBookCollection(library.getBookBySerial(bookSerial), library.getCollectionById(collectionId));
                cout << "Remove book from collection success!" << endl;
            } else {
                cout << "This collection does not exist!" << endl;
            }
            system("pause");
            currentMenu = currentMenu->getParentMenu();
        }
            break;


//=================================================================================   

        default:
            cout << "Default action!" << endl;
            break;
        }

    }

//Deallocate memory
    delete currentMember;
    delete currentAdmin;

    return 0;
}