#include "global_management.h"
#include "interface.h"
#include "book_management.h"
#include "user_management.h"
#include "book_use.h"

extern int status;
extern User *loggedUser;



static void start_menu() {
    status = 0;
    int option = 5;
    do {
        
        puts("\nWelcome to Tony's library:\n");
        puts("1. Display all books\n");
        puts("2. Search for books\n");
        puts("3. Login\t4. Register\n");
        puts("5. Quit\n");
        puts("(Enter number to execute corresponding option)\n");
        puts("Choice: ");
        option = atoi(my_gets());
        puts("**********************************************************\n");


        switch (option) {
            case 1:
                display_all_books();
                break;
            case 2:
                search_for_books();
                break;
            case 3:
                login_user();
                break;
            case 4:
                register_user();
                break;
            case 5:
                puts("Good bye!\n");
                status = -1;
                break;
            default:

                puts("Please enter a valid option\n");
        }
        if (status != 0)
            break;

    } while (option != 5);
    return;
}

/********************************************/

static void user_menu() {
    status = 1;
    int option = 5;

    do {

        
        printf("\nLogged as %s :)\n", loggedUser->name);
        puts("1. Display all books\n");
        puts("2. Search for books\n");
        puts("3. Borrow\t4. Return\n");
        puts("5. Quit\n");
        puts("(Enter number to execute corresponding option)\n");
        puts("Choice: ");
        option = atoi(my_gets());
        puts("**********************************************************\n");
        switch (option) {
            case 1:
                display_all_books();
                break;
            case 2:
                search_for_books();
                break;
            case 3:
                borrow_book();
                break;
            case 4:
                return_book();
                break;
            case 5:
                status = 0;
                puts("Logged out!\n");
                break;
            default:
                puts("Please enter a valid option\n");
        }
        if (status != 1)
            break;
    } while (option != 5);
    return;
}

/********************************************/

static void librarian_menu() {
    status = 2;
    int option = 5;
    do {
        puts("\nLogged as librarian :)\n");
        puts("1. Display all books\n");
        puts("2. Search for books\n");
        puts("3. Add\t4. Remove\n");
        puts("5. Quit\n");
        puts("(Enter number to execute corresponding option)\n");
        puts("Choice: ");
        option = atoi(my_gets());
        puts("**********************************************************\n");


        switch (option) {
            case 1:
                display_all_books();
                break;
            case 2:
                search_for_books();
                break;
            case 3:
                add_a_book();
                break;
            case 4:
                remove_a_book();
                break;
            case 5:
                status = 0;
                puts("Logged out!\n");
                puts("(Press enter to confirm)");
                my_gets();
                puts("**********************************************************\n");
                break;
            default:
                puts("Please enter a valid option\n");
        }
        if (status != 2)
            break;
    } while (option != 5);
    return;
}

/********************************************/
/********************************************/

void start_interface() {

    
    init();
    
/********************************************/   

    do {
        switch (status) {
            case 0:
                start_menu();
                break;
            case 1:
                user_menu();
                break;
            case 2:
                librarian_menu();
                break;
            default:
                break;
        }
    } while (status != -1);

/********************************************/
    end();


    return;
}




