#include "book_management.h"
#include "user_management.h"
#include "book_use.h"

int status;
BookArray *head;
User *userHead;
User *loggedUser;




// A self-designed gets function which could input strings with spaces
char* my_gets() {
    char * line = malloc(2), * line_head = line, *found;
    char ch;
    // Clear the input cache
    fflush(stdin); 

    // realloc space for every character
    while(1) {
     ch = fgetc(stdin);
     line_head = realloc (line_head, 1);
     if((*line++ = ch) == '\n')
         break;
    }

    //replace final '\n' to '\0'
    found = strchr(line_head, '\n');
    if (found)
        *found = '\0';


    return line_head;
}


void init() {
    
    // init status code
    status = 0;
    // init book head pointer
    head = (BookArray*) malloc (sizeof(BookArray));
    memset(head, 0, sizeof(BookArray));
    // init administrator account
    userHead = (User*) malloc (sizeof(User));
    memset(userHead, 0, sizeof(User));
    // init book head pointer and file;
    // strcpy(userHead->name, "librarian");
    // strcpy(userHead->password, "librarian");
    // int numUser = 1;
    // FILE *file = fopen("users.bin", "wb+");
    // fwrite(&numUser, sizeof(int), 1, file);
    // fwrite(userHead, sizeof(User), 1, file);
    // fclose(file);
    loggedUser = (User*) malloc (sizeof(User));
    memset(loggedUser, 0, sizeof(User));

    // open bookfile
    FILE *file;
    file = fopen("books.txt", "r");
    if (load_books(file) == 1)
        puts("No such file!");
    else
        puts("Books loaded.");

    // open userfile
    file = fopen("users.bin", "rb");
    if (load_users(file) == 1)
        puts("No user file!\nYou can only log in as librarian!");
    else
        puts("Users loaded.");
    fclose(file);
    file = NULL;


}

void end() {
    // close bookfile
    FILE *file;
    file = fopen("books.txt", "w");
    if (store_books(file) == 1)
        puts("No such file!");
    else
        puts("Books stored.");
    fclose(file);

    // open userfile
    file = fopen("users.bin", "wr");
    if (store_users(file) == 1)
        puts("No user file!");
    else
        puts("Users stored.");
    fclose(file);
    file = NULL;

    // free book

    // free user

}



