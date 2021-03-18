#include "book_management.h"



static void display_all_books() {
    create_book(current);

    current = head->array;
    while (current->next != NULL) {
        puts(current);
        current = current->next;
    }
    return;
}

static void search_for_books() {
    char *title, *author, *year;
    int option = 4;
    puts("(Enter number to chose rule of search\n1. Search by title\n2. Search by author\n3. Search by year\n4. Return to previous\nChoice:");
    scanf("%d", &option);
    do {
    switch (option) {
            case 1:
                gets(title);
                find_book_by_title(title);
                break;
            case 2:
                gets(author);
                find_book_by_author(author);
                break;
            case 3:
                gets(year);
                find_book_by_year(year);
                break;
            case 4:
                break;
            default:
                printf("Please enter a valid option\n");
        }
    } while (option != 4);
    return;
}

int load_books(FILE *file) {
    if (file == NULL) {
        printf("No such file\n");
        return 1;
    }

    fread(head, sizeof(BookArray), 1, file);
    fread(head->array, sizeof(Book), head->length, file);
    return 0; 
}

int store_books(FILE *file) {
    if (file == NULL) {
        printf("No such file\n");
        return 1;
    }

    fwrite(head->array, sizeof(Book), head->length, file);
    fwrite(head, sizeof(BookArray), 1, file);
    return 0;
}

int add_book(Book book) {
    create_book(current);

    current = head->array;
    while (current->next != NULL)
        current = current->next;
    current->next = &book;
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

BookArray find_book_by_title (const char *title) {
    create_book(current);
    create_book(previous);
    create_book(currentTitle);
    create_book_head(headTitle)

    current = head->array;
    currentTitle = headTitle->array;

    while (current->next != NULL) {
        if (strstr(title, current->title) != NULL) {
            currentTitle = (Book *) malloc (sizeof(Book));
            *currentTitle = *current;

            if (headTitle->array == NULL)
                headTitle->array = currentTitle;
            else
                previous->next = currentTitle;
            current->next = NULL;
            previous = current;
        }
        current = current->next;
    }
    return *headTitle;
}


BookArray find_book_by_author (const char *authors) {
    create_book(current);
    create_book(previous);
    create_book(currentAuthors);
    create_book_head(headAuthors)

    current = head->array;
    currentAuthors = headAuthors->array;

    while (current->next != NULL) {
        if (strstr(authors, current->authors) != NULL) {
            currentAuthors = (Book *) malloc (sizeof(Book));
            *currentAuthors = *current;

            if (headAuthors->array == NULL)
                headAuthors->array = currentAuthors;
            else
                previous->next = currentAuthors;
            current->next = NULL;
            previous = current;
        }
        current = current->next;
    }
    return *headAuthors;
}


BookArray find_book_by_year (unsigned int year) {
    create_book(current);
    create_book(previous);
    create_book(currentYear);
    create_book_head(headYear)

    current = head->array;
    currentYear = headYear->array;

    while (current->next != NULL) {
        if (year == current->year) {
            currentYear = (Book *) malloc (sizeof(Book));
            *currentYear = *current;

            if (headYear->array == NULL)
                headYear->array = currentYear;
            else
                previous->next = currentYear;
            current->next = NULL;
            previous = current;
        }
        current = current->next;
    }
    return *headYear;
}




