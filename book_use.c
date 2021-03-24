#include "book_use.h"
#include "book_management.h"
#include "user_management.h"
#include "interface.h"


extern BookArray *head;
extern User *loggedUser;
extern User *userHead;


void borrow_book () {
    int id, i = 0;


    if (head->array == NULL) {
        puts("No books in library!");
        return;
    }
    display_all_books();
    puts("Enter the id of the book to borrow: ");
    id = atoi(my_gets());

    unsigned int *p = loggedUser->idContainer;
    for (int i = 0; i < 5; ++i) {
        if (id == p[i]) {
            puts("Failed. You have already borrowed this book.");
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
                puts("Failed. You have borrowed 5 books, return some to borrow more books.");
                return;
            }
        }
    }
    
    Book *current = head->array;
    puts_books(current);
    puts("Success. You have borrowed these books: ");
    for (int i = 0; i < 5; ++i)
        if (p[i] != 0)
            printf("%d ", p[i]);
    puts("You can check the book you have borrowed by id list.");
}

void return_book () {
    int id;

    // check empty
    unsigned int *p = loggedUser->idContainer;
    int i = 0;
    for (; i < 5; ++i)
        if (p[i] != 0)
            break;
    if (i == 5)
        puts("You haven't borrowed any books.");

    
    else {

        Book *current = head->array;
        puts_books(current);
        puts("You have borrowed these books: ");
        for (int i = 0; i < 5; ++i)
            if (p[i] != 0)
                printf("%d ", p[i]);
        puts("You can check the book you have borrowed by id list.");

        puts("Enter id of the book you want to return.");
        id = atoi(my_gets());
        for (i = 0; i < 5; ++i) {
            if (id == p[i]) {
                p[i] = 0;
                puts_books(current);
                puts("Success. You have borrowed these books: ");
                for (int i = 0; i < 5; ++i) {
                    if (p[i] != 0)
                        printf("%d ", p[i]);
                    if (p[4] == 0)
                        printf("None");
                }

                printf("\n");
                puts("You can check the book you have borrowed by id list.");
                break;
            }
        }

        if (i == 5) {
            puts("Failed. You haven't borrowed this book.");
        }


        // for (; current != NULL; current = current->next) {

        // }
    }



}
