#include "global_management.h"
#include "book_management.h"
#include "user_management.h"
#include "book_use.h"


extern BookArray *head;
extern User *loggedUser;
extern User *userHead;


void borrow_book () {
    int id, i = 0;


    if (head->array == NULL) {
        puts("No books in library!");
        return;
    }
    Book *current = head->array;
    puts_books(current);
    puts("Enter the id of the book to borrow: ");
    char *answer = my_gets();
    id = atoi(answer);
    free(answer);

    unsigned int *p = loggedUser->idContainer;
    for (int i = 0; i < 5; ++i) {
        if (id == p[i]) {
            puts("Failed. You have already borrowed this book.\n");
            puts("(Press enter to confirm)");
            getchar();
            puts("**********************************************************\n");
            return;
        }
    }


    for (Book *current = head->array; current != NULL; current = current->next) {        
        if (current->id == id) {

            for (i = 0; i < 5; ++i) {
                if (p[i] == 0) {
                    p[i] = id;
                    break;
                }
            }
            if (i == 5) {
                puts("Failed. You have borrowed 5 books, return some to borrow more books.\n");
                return;
            }
        }
    }
    
    puts("Success. You have borrowed these books =>\n: ");
    for (int i = 0; i < 5; ++i)
        if (p[i] != 0)
            printf("%d ", p[i]);
    puts("\nYou can check the book you have borrowed by id list.\n");
    puts("(Press enter to confirm)");
    getchar();
    puts("**********************************************************\n");
}

void return_book () {
    int id;

    // check empty
    unsigned int *p = loggedUser->idContainer;
    int i = 0;
    for (; i < 5; ++i)
        if (p[i] != 0)
            break;
    if (i == 5) {
        puts("You haven't borrowed any books.\n");
        puts("(Press enter to confirm)");
        getchar();
        puts("**********************************************************\n");

    }

    
    else {

        Book *current = head->array;
        puts_books(current);
        puts("You have borrowed these books =>\n: ");
        for (int i = 0; i < 5; ++i)
            if (p[i] != 0)
                printf("%d ", p[i]);
        puts("\nYou can check the book you have borrowed by id list.\n");

        puts("Enter id to return: ");
        char *answer = my_gets();
        id = atoi(answer);
        free(answer);

        for (i = 0; i < 5; ++i) {
            if (id == p[i]) {
                p[i] = 0;
                puts("Success. You have borrowed these books =>\n: ");
                for (i = 0; i < 5; ++i)
                    if (p[i] != 0)
                        printf("%d ", p[i]);
                    
                if (p[4] == 0)
                    printf("None");

                printf("\n");
                puts("You can check the book you have borrowed by id list.\n");
                puts("(Press enter to confirm)");
                getchar();
                puts("**********************************************************\n");
                return;
            }
        }

        if (i == 5) {
            puts("Failed. You haven't borrowed this book.\n");
            puts("(Press enter to confirm)");
            getchar();
            puts("**********************************************************\n");
        }
    }
}
