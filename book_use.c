#include "book_use.h"
#include "book_management.h"
#include "interface.h"


int borrow_book (){
    create_book(current);
    create_book(book);

    add_book(*book);
    current = head->array;

    while (current->next != NULL) {
        if (book->id == current->id)
            current->copies -= 1;
        current = current->next;
    }
    return 0;
}

int return_book () {
    create_book(current);
    create_book(book);

    remove_book(*book);
    current = head->array;
    while (current->next != NULL) {
        if (book->id == current->id)
            current->copies += 1;
        current = current->next;
    }
    return 0;
}
