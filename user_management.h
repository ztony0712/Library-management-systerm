#ifndef USER_MANAGEMENT_GUARD__H 
#define USER_MANAGEMENT_GUARD__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define create_user(p) User *p = (User*) malloc (sizeof(User));memset(p, 0, sizeof(User));

typedef struct _User {
        char name[21]; //User name
        char password[21]; //User password
        unsigned int idContainer[5]; // borrowed ID
        struct _User *next; //Pointer to next user
}User;




int store_users(FILE *file);
int load_users(FILE *file);


void register_user(void);
void login_user(void);


#endif
