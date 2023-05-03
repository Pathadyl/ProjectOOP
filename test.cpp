#include "Guest.h"
#include "Library.h"
#include "register_user.h"
#include "user.h"
#include "Book.h"
#include "Admin.h"
#include "Member.h"

int main(){

    Library& library = Library::getInstance();
    Admin* a = new Admin(1, "Admin01", "abcdef", 1, "Dylan Pham", "0867071680", library);

    Book* b1 = new Book("Book1", "123456", "Author1", "Science", 400, 10);
    a->addBook(b1);

    library.getPublicBookList().back()->printInfo();

    return 0;
}