#include "book_management.h"
#include "user_management.h"
#include "book_use.h"

int status;
BookArray *head;
User *userHead;
User *loggedUser;




// A self-designed gets function which could input strings with spaces
char* my_gets() {
    char *line = malloc(2), *line_head = line, *found;
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
        puts("No books file!");
    else
        puts("Books loaded.");


    // open userfile
    file = fopen("users.bin", "rb");
    if (load_users(file) == 1)
        puts("No users file!\nYou can only log in as librarian!");
    else
        puts("Users loaded.");
    file = NULL;


// __        __   _
// \ \      / /__| | ___ ___  _ __ ___   ___
//  \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \
//   \ V  V /  __/ | (_| (_) | | | | | |  __/
//    \_/\_/ \___|_|\___\___/|_| |_| |_|\___|

    puts("__        __   _");
    puts("\\ \\      / /__| | ___ ___  _ __ ___   ___");
    puts(" \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\");
    puts("  \\ V  V /  __/ | (_| (_) | | | | | |  __/");
    puts("   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|");


}

void end() {
    // close bookfile
    FILE *file;
    file = fopen("books.txt", "w+");
    if (store_books(file) == 1)
        puts("No books file!");
    else
        puts("Books stored.");

    // open userfile
    file = fopen("users.bin", "wr");
    if (store_users(file) == 1)
        puts("No users file!");
    else
        puts("Users stored.");
    file = NULL;

    // free book
    Book *currentBook = head->array;
    for(; currentBook != NULL; currentBook = currentBook->next)
        free(currentBook);
    free(head);
    
    // free user
    User *currentUser = userHead;
    for(; currentUser != NULL; currentUser = currentUser->next)
        free(currentUser);

}




