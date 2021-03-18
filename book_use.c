#include "user_management.h"
#include "book_management.h"




static void add_a_book () {
    create_book(book);

    puts("Title:");
    gets(book->title);
    puts("Author:");
    gets(book->authors);
    puts("Year:");
    gets(book->year);
    puts("Copies:");
    gets(book->copies);

    add_book(*book);
}

static void remove_a_book () {
    int id;
    create_book(current);

    puts("Enter the id of the book to remove: ");
    scanf("%d", &id);

    current = head->array;
    while (current != NULL) {
        if (current->id == id) {
            if (!remove_book(*current)) {
                puts("Book removed successfully!");
                return;
            }
            else
                puts("Failed to store");
            
        }
        current = current->next;
    }
    puts("No such a book.");
    return;
}

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
