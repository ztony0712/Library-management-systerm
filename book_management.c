#include "book_management.h"
#include "interface.h"


// #define init_string(st) char *st = malloc (sizeof(char));

// #define my_puts(st) printf("%s\n", st);
// #define my_gets(st) scanf("%s", st);
// #define my_gets_num(num) scanf("%u", &num);



void display_all_books() {
    create_book(current);

    current = head->array;
    while (current->next != NULL) {
        puts(current); // unmodified
        current = current->next;
    }
}

/********************************************/

void display_of_search(BookArray *headArray) {
    if (headArray == NULL) {
        puts("No such a book!");
        return;
    }
    
    create_book(current);

    current = headArray->array;
    while (current->next != NULL) {
        puts(current); // unmodified
        current = current->next;
    }
}

void search_for_books() {
    char *title, *author;
    unsigned int year;


    int option = 4;
    puts("(Enter number to choose rule of search\n1. Search by title\n2. Search by author\n3. Search by year\n4. Return to previous\nChoice:");
    option = atoi(my_gets());

    do {
    switch (option) {
            case 1:
                puts("Enter title: ");
                title = my_gets();
                
                display_of_search(find_book_by_title(title));
                break;
            case 2:
                puts("Enter author: ");
                author = my_gets();
                
                display_of_search(find_book_by_author(author));
                break;
            case 3:
                puts("Enter year: ");
                year = atoi(my_gets());
                
                display_of_search(find_book_by_year(year));
                break;
            case 4:
                break;
            default:
                puts("Please enter a valid option\n");
        }
    } while (option != 4);
    return;
}

BookArray* find_book_by_title (const char *title) {
    create_book(current);
    create_book(previous);
    create_book_head(headTitle)

    current = head->array;
    headTitle->array = NULL;

    while (current->next != NULL) {
        if (strstr(title, current->title) != NULL) {
            create_book(book);
            *book = *current;

            if (headTitle->array == NULL)
                headTitle->array = book;
            else
                previous->next = book;
            previous = book;
            book = NULL;
        }
        current = current->next;
    }
    return headTitle;
}


BookArray* find_book_by_author (const char *authors) {
    create_book(current);
    create_book(previous);
    create_book_head(headAuthor)

    current = head->array;
    headAuthor->array = NULL;

    while (current->next != NULL) {
        if (strstr(authors, current->authors) != NULL) {
            create_book(book);
            *book = *current;

            if (headAuthor->array == NULL)
                headAuthor->array = book;
            else
                previous->next = book;
            previous = book;
            book = NULL;
        }
        current = current->next;
    }
    return headAuthor;
}


BookArray* find_book_by_year (unsigned int year) {
    create_book(current);
    create_book(previous);
    create_book_head(headYear)

    current = head->array;
    headYear->array = NULL;

    while (current->next != NULL) {
        if (year == current->year) {
            create_book(book);
            *book = *current;

            if (headYear->array == NULL)
                headYear->array = book;
            else
                previous->next = book;
            previous = book;
            book = NULL;
        }
        current = current->next;
    }
    return headYear;
}

/********************************************/

int load_books(FILE *file) {
    if (file == NULL)
        return 1;

    fread(head, sizeof(BookArray), 1, file);
    fread(head->array, sizeof(Book), head->length, file);
    return 0; 
}

int store_books(FILE *file) {
    if (file == NULL)
        return 1;

    fwrite(head->array, sizeof(Book), head->length, file);
    fwrite(head, sizeof(BookArray), 1, file);
    return 0;
}

/********************************************/

int add_book(Book book) {
    create_book(current);
    create_book(previous);

    current = head->array;
    while (current != NULL) {
        
        current = current->next;
    }
    current = &book;
    book.next = NULL;
    book.id = current->id + 1;
    head->length += 1;
    FILE *file = fopen("books.txt", "w");
    store_books(file);
    return 0;
}


int remove_book(Book book) {
    create_book(previous);
    create_book(current);

    current = head->array;
    while (current->next != NULL) {
        if (book.id == current->id) {
            previous->next = current->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
    head->length -= 1;
    FILE *file = fopen("books.txt", "w");
    store_books(file);
    return 0;
}

void add_a_book () {
    create_book(book);

    puts("Title: ");
    book->title = my_gets();
    puts("Author: ");
    book->authors = my_gets();
    puts("Year: ");
    book->year = atoi(my_gets());
    puts("Copies: ");
    book->copies = atoi(my_gets());

    add_book(*book);
}

void remove_a_book () {
    int id;
    create_book(current);

    puts("Enter the id of the book to remove: ");
    scanf("%d", &id);
    getchar();

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





