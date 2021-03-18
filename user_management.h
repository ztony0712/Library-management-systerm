#ifndef BOOK_MANAGEMENT_GUARD__H 
#define BOOK_MANAGEMENT_GUARD__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define create_user(p) User *p = (User*) malloc (sizeof(User));

typedef struct _User {
        unsigned int id; //User ID
        char *name; //User name
        char *password; //User password
        struct _User *next; //Pointer to next user
}User;


void register_user();
void login_user();


#endif