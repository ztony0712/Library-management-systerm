
#include "interface.h"
#include "book_management.h"



static void start_menu() {
    status = 0;
    int option = 5;
    do {

        printf("\nWelcome to Tony's library:\n1. Display all books\n2. Search for books\n3. Login\t4. Register\n5. Quit\n(Enter number to execute corresponding option)\nChoice: ");
        scanf("%d", &option);

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
                printf("Good bye!");
                status = -1;
                break;
            default:
                printf("Please enter a valid option\n");
        }

    } while (option != 5);
    return;
}

static void user_menu() {
    status = 1;
    char *userName;
    int option = 5;

    do {

        printf("\nLogged as %s :)\n1. Display all books\n2. Search for books\n3. Borrow a book\t4. Return a book\n5. Logout\n(Enter number to execute corresponding option)\nChoice: ", userName);
        scanf("%d", &option);

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
                printf("Logged out!");
                break;
            default:
                printf("Please enter a valid option\n");
        }

    } while (option != 5);
    return;
}

static void librarian_menu() {
    status = 2;
    int option = 5;
    do {

        printf("\nLogged as librarian :)\n1. Display all books\n2. Search for books\n3. Add a book\t4. Remove a book\n5. Logout\n(Enter number to execute corresponding option)\nChoice: ");
        scanf("%d", &option);

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
                printf("Logged out");
                break;
            default:
                printf("Please enter a valid option\n");
        }

    } while (option != 5);
    return;
}

void run_interface() {
    FILE *bookFile = fopen("books.txt", "r");
    FILE *userFile = fopen("books.txt", "r");
    load_books(bookFile);
    load_users(userFile);
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

    return;
}



