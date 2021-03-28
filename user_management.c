#include "global_management.h"
#include "user_management.h"

extern int status;
extern User *userHead;
extern User *loggedUser;
int numUser = 0;

void register_user () {
    User *current = userHead;
    char *name, *code1, *code2;

    // FILE *userFile = fopen("users.bin", "rb");
    // if (load_users(userFile) == 1) {
    //     puts("No such file\n");
    //     return;
    // }
    

    do {
        puts("Enter user name (8-20): ");
        name = my_gets();
    } while (strlen(name) < 8 || strlen(name) > 20);

    for (; current != NULL; current = current->next) {
        if (strcmp(name, current->name) == 0 || strcmp(name, "librarian") == 0) {
            puts("This name is in use. Try another name.\n");
            return;
        }
    }


    while (1) {
        do {
            puts("Enter password (8-20): ");
            code1 = my_gets();
        } while (strlen(code1) < 8 || strlen(code1) > 20);
        do {
            puts("Enter password again (8-20): ");
            code2 = my_gets();
        } while (strlen(code2) < 8 || strlen(code2) > 20);
        if (strcmp(code1, code2) == 0)
            break;
        puts("The passwords are inconsistent.");
    }


    create_user(new);
    strcpy(new->name, name);
    strcpy(new->password, code1);

    
    for (current = userHead; current->next != NULL; current = current->next);
    current->next = new;
    memset(current->idContainer, 0, 5);
    numUser += 1;

    // userFile = fopen("users.bin", "wb");
    // if (store_users(userFile) == 1) {
    //     puts("No such file\n");
    //     return;
    // }


    new = NULL;
    current = NULL;

    puts("Account created successfully!\n");
    puts("(Press enter to confirm)");
    getchar();
    puts("**********************************************************");

    return;
}





void login_user() {

    User *current;
    char *password, *name;


    // FILE *userFile = fopen("users.bin", "rb");
    // if (load_users(userFile) == 1)
    //     puts("No user file.\nYou can only log in as librarian.");
    // fclose(userFile);
    


    
    do {
        puts("Enter user name (8-20): ");
        name = my_gets();
    } while (strlen(name) < 8 || strlen(name) > 20);
    
    do {
        puts("Enter password (8-20): ");
        password = my_gets();
    } while (strlen(password) < 8 || strlen(password) > 20);

    if (strcmp(name, "librarian") == 0 && strcmp(password, "librarian") == 0) {
        status = 2;
        return;
    }

    current = userHead;
    for (; current != NULL; current = current->next) {
        
        if (!strcmp(name, current->name)) {
            if (!strcmp(password, current->password)) {
                loggedUser = current;
                puts("Account logged successfully!\n");
                status = 1;
                return;
            }
            else {
                puts("Wrong password!\n");
                return;
            }
        }
    }
    puts("Account not exist!\n");
    return;
}

/********************************************/
/********************************************/

int load_users(FILE *file) {
    User *previous;
    userHead = NULL;
    int result = 1;
    

    if (file == NULL)
        result = 1;
    else {
        rewind(file);
        fread(&numUser, sizeof(int), 1, file);
        previous = userHead;
        for (int i = 0; i < numUser; ++i) {

            create_user(current);
            fread(current, sizeof(User), 1, file);
            if (userHead == NULL)
                previous = userHead = current;
            else
                previous->next = current;
            
            previous = current;
            
        }
        previous = NULL;
        result = 0;
    }
    fclose(file);
    return result;
}

int store_users(FILE *file) {
    User *current;
    int result = 1;

    if (file == NULL)
        puts("No user file!");

    else {
        rewind(file);
        fwrite(&numUser, sizeof(int), 1, file);
        current = userHead;
        for (; current != NULL; current = current->next)
            fwrite(current, sizeof(User), 1, file);
        result = 0;
    }
    fclose(file);
    return result;
}





