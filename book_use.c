#include "book_use.h"
#include "book_management.h"
#include "user_management.h"
#include "interface.h"

extern BookArray *head;
extern User *loggedUser;


void borrow_book () {
    Book *current = head->array;
    Book *currentBook;
    int id;


    if (head->array == NULL) {
        puts("No books in library!");
        return;
    }
    puts("Enter the id of the book to borrow: ");
    id = atoi(my_gets());


    for (; current != NULL; current = current->next) {        

        if (current->id == id) {
            create_book(new);
            *new = *current;
            current->id -= 1;
            currentBook = loggedUser->bookList;
            if (loggedUser->bookList != NULL)
                for (; currentBook->next != NULL; currentBook = currentBook->next);
            
            if (loggedUser->bookList == NULL)
                loggedUser->bookList = new;
            else
                currentBook->next = new;
            break;
        }
    }

    return;
}

void return_book () {
    Book *current = loggedUser->bookList, *previous = loggedUser->bookList;
    int id;

    if (loggedUser->bookList == NULL) 
        puts("You haven't borrowed any books.");
    
    else {
        
        puts("id\ttitle\tauthors\tyear\tcopies\n");

        for (; current != NULL; current = current->next)
            printf("%u\t%s\t%s\t%u\t%u\n", current->id, current->title, current->authors, current->year, current->copies);



        puts("Enter id of the book you want to return.");
        id = atoi(my_gets());
        current = loggedUser->bookList;
        for (; current != NULL; current = current->next) {        

            if (current->id == id) {
                if (current == loggedUser->bookList)
                    loggedUser->bookList = current->next;
                else
                    previous->next = current->next;
                free(current);
                break;
            }
            previous = current;
        }
    }

    return;
}
