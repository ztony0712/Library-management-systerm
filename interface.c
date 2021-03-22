#include "interface.h"
#include "book_management.h"
#include "user_management.h"
// #include "book_use.h"

extern int status;
extern BookArray *head;
FILE *bookFile;


static void start_menu() {
    status = 0;
    int option = 5;
    do {

        puts("\nWelcome to Tony's library:\n1. Display all books\n2. Search for books\n3. Login\t4. Register\n5. Quit\n(Enter number to execute corresponding option)\nChoice: ");
        option = atoi(my_gets());


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
    char *userName = NULL;
    int option = 5;

    do {

        printf("\nLogged as %s :)\n1. Display all books\n2. Search for books\n3. Borrow a book\t4. Return a book\n5. Logout\n(Enter number to execute corresponding option)\nChoice: ", userName);
        option = atoi(my_gets());

        switch (option) {
            case 1:
                display_all_books();
                break;
            case 2:
                search_for_books();
                break;
            // case 3:
            //     borrow_book();
            //     break;
            // case 4:
            //     return_book();
            //     break;
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

        puts("\nLogged as librarian :)\n1. Display all books\n2. Search for books\n3. Add a book\t4. Remove a book\n5. Logout\n(Enter number to execute corresponding option)\nChoice: ");
        option = atoi(my_gets());

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
                puts("Logged out\n");
                puts("(Press enter to continue.)");
                my_gets();
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
    status = 0;
    head = (BookArray*) malloc (sizeof(BookArray));
    head->array = NULL;
    head->length = 0;

    
    // FILE *userFile = fopen("books.bin", "r");
 /********************************************/   
    bookFile = fopen("books.txt", "r");
    if (load_books(bookFile) == 1)
        puts("No such file\n");
    else
        puts("Books loaded\n");

    // if (load_users(userFile) == 1)
    //     my_puts("No such file\n");
    // else
    //     my_puts("Users loaded");
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
    fclose(bookFile);

    return;
}

char* my_gets() {
   char * line = malloc(2), * line_head = line, *found;
   char ch;

   while(1) {
     ch = fgetc(stdin);
     line_head = realloc (line_head, 1);
     if((*line++ = ch) == '\n')
         break;
    }

    found = strchr(line_head, '\n');
    if (found)
        *found = '\0';
    // fflush(stdin);

   return line_head;
}

// char* my_gets(char *string) {
    
//     char *result, *found;
//     string = (char*) malloc (sizeof(char));

//     result = fgets(string, 30, stdin);
//     if (result) {
//         found = strchr(string, '\n');
//         if (found)
//             *found = '\0';
//         else
//             while(getchar() != '\n')
//                 continue;
//     }
//     return result;
// }

