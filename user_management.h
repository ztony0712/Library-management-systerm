#ifndef USER_MANAGEMENT_GUARD__H 
#define USER_MANAGEMENT_GUARD__H

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

extern User *userHead;


int store_users(FILE *file);

int load_users(FILE *file);


void register_user();
void login_user();





#endif