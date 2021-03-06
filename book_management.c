#include "global_management.h"
#include "book_management.h"

extern BookArray *head;

void puts_books(Book *current) {
    puts("id  \ttitle");
    for (int i = 0; i < 27; ++i)
        puts(" ");
    puts("authors");
    for (int i = 0; i < 17; ++i)
        puts(" ");
    puts("year\tcopies\n");



    for(; current != NULL; current = current->next)
        printf("%04u\t%-30s\t%-20s\t%-4u\t%-3u\n", \
        current->id, current->title, current->authors,\
        current->year, current->copies);
    for (int i = 0; i < 80; ++i)
        puts("-");
    puts("\n");
}

void display_all_books() {
    Book *current = head->array;

    if (current == NULL)
        puts("No books in library!\n");
    else
        puts_books(current);
    puts("(Press enter to confirm)");
    getchar();
    puts("**********************************************************\n");
}

/********************************************/

void display_of_search(BookArray *headArray) {
    if (headArray->array == NULL)
        puts("No such a book!\n");
    
    else {
        Book *current = headArray->array;
        puts_books(current);
    }
    puts("(Press enter to confirm)");
    getchar();
    puts("**********************************************************\n");
}

void search_for_books() {
    char *title, *author;
    unsigned int year;


    int option = 4;
    

    do {
    puts("\n1. Search by title\n2. Search by author\n3. Search by year\n4. Return to previous\n(Enter number to choose rule of search)\nChoice: ");
    char *answer = my_gets();
    option = atoi(answer);
    free(answer);
    puts("**********************************************************\n");
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
    Book *current = head->array;
    Book *currentTitle = NULL;
    create_book_head(headTitle);


    if (current == NULL)
        puts("No books in library!");
    else {
        for (; current != NULL; current = current->next) {
            if (strstr(current->title, title) != NULL) {
                create_book(book);
                *book = *current;
                book->next = NULL;

                if (headTitle->array == NULL)
                    currentTitle = headTitle->array = book;
                else
                    currentTitle->next = book;
                book = NULL;
            }
        }
    }
    return headTitle;
}


BookArray* find_book_by_author (const char *authors) {
    Book *current = head->array;
    Book *currentAuthor = NULL;
    create_book_head(headAuthor);


    if (current == NULL)
        puts("No books in library!");
    else {
        for (; current != NULL; current = current->next) {
            if (strstr(current->authors, authors) != NULL) {
                create_book(book);
                *book = *current;
                book->next = NULL;

                if (headAuthor->array == NULL)
                    currentAuthor = headAuthor->array = book;
                else
                    currentAuthor->next = book;
                book = NULL;
            }
        }
    }
    return headAuthor;
}


BookArray* find_book_by_year (unsigned int year) {
    Book *current = head->array;
    Book *currentYear = NULL;
    create_book_head(headYear);


    if (current == NULL)
        puts("No books in library!");
    else {
        for (; current != NULL; current = current->next) {
            if (year == current->year) {
                create_book(book);
                *book = *current;
                book->next = NULL;

                if (headYear->array == NULL)
                    currentYear = headYear->array = book;
                else
                    currentYear->next = book;
                book = NULL;
            }
        }
    }
    return headYear;
}

/********************************************/

int load_books(FILE *file) {
    Book *previous = NULL;
    if (file == NULL) 
        return 1;   

    rewind(file);
    fscanf(file, "%u\n", &(head->length));


    for (int i = 0; i < head->length; ++i) {
        create_book(book);
        book->title = (char*) malloc(sizeof(char));
        book->authors = (char*) malloc(sizeof(char));
        fscanf(file, "%u\t%s\t\t%s\t%u\t%u\n", &(book->id), book->title, book->authors, &(book->year), &(book->copies));
        if (head->array == NULL)
            previous = head->array = book;
        else
            previous->next = book;
        book->next = NULL;
        previous = book;
    }
    previous = NULL;

    fclose(file);
    return 0;
}

int store_books(FILE *file) {
    if (file == NULL)
        return 1;
    rewind(file);
    fprintf(file, "%u\n", head->length);

    Book *current = head->array;
    if (head->array != NULL)
        for (; current != NULL; current = current->next)
            fprintf(file, "%04u\t%-30s\t%-20s\t%-4u\t%-2u\n", current->id, current->title, current->authors, current->year, current->copies);
    
    fclose(file);
    return 0;
}

/********************************************/

int add_book(Book *book) {
    Book *current = head->array;

    if (head->array != NULL)
        for (; current->next != NULL; current = current->next);
    
    for (Book *idChanger = head->array; idChanger != NULL; idChanger = idChanger->next) {
        srand((int)time(0));
        do {
            book->id = rand() % 1000 + 1;
        } while (idChanger->id == book->id);
            
    }
    // if (head->array == NULL)
    //     book->id = 1;
    // else
    //     book->id = current->id + 1;
    head->length += 1;
    book->next = NULL;

    if (head->array == NULL)
        head->array = book;
    else
        current->next = book;
    // FILE *file = fopen("books.txt", "wt+");
    // store_books(file);
    return 0;
}


int remove_book(Book *book) {
    int result = 1;
    Book *current = head->array, *previous = head->array;

    if (head->array == NULL)
        puts("No books in library!\n");

    else {
        for (; current != NULL; current = current->next) {        

            if (current->id == book->id) {
                if (current == head->array)
                    head->array = current->next;
                else
                    previous->next = current->next;
                free(current);
                break;
            }
            previous = current;
        }
        if (current != NULL) {
            head->length -= 1;
            result = 0;
        }
    }

    
    // FILE *file = fopen("books.txt", "w");
    // store_books(file);
    return result;
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

    if (add_book(book) == 0)
        puts("Book added successfully!\n");
    else
        puts("Book added failed!\n");
    book = NULL;
    puts("(Press enter to confirm)");
    getchar();
    puts("**********************************************************\n");


    
}


void remove_a_book () {
    create_book(book);

    Book *current = head->array;
    puts_books(current);
    puts("Enter the id of the book to remove: ");
    book->id = atoi(my_gets());

    if (!remove_book(book))
        puts("Book removed successfully!\n");

    else
        puts("No such a book!\n");
    free(book);
    puts("(Press enter to confirm)");
    getchar();
    puts("**********************************************************\n");


    return;
}



