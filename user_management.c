#include "user_management.h"
#include "interface.h"

extern int status;
extern User *userHead;

void register_user () {
    User *current = userHead;
    char *name, *code1, *code2;

    FILE *userFile = fopen("users.bin", "wb+");
    // if (load_users(userFile) == 1) {
    //     puts("No such file\n");
    //     return;
    // }
    
    
    puts("Enter user name:");

    loop_r:
    name = my_gets();
    current = userHead;
    for (; current != NULL; current = current->next) {
        if (current->name == name) {
            puts("This name is in use. Try another name.\n");
            goto loop_r;
        }
    }

    

    while (1) {
        puts("Enter password (more than 8 digits):");
        code1 = my_gets();
        puts("Enter password again (more than 8 digits):");
        code2 = my_gets();
        if (strcmp(code1, code2) == 0)
            break;
        puts("The passwords are inconsistent.");
    }


    create_user(new);
    new->name = name;
    new->password = code1;
    
    current = new;

    if (store_users(userFile) == 1){
        puts("No such file\n");
        return;
    }

    fclose(userFile);

    puts("Account created successfully!");
    return;
}





void login_user() {
    create_user(userHead);
    create_user(current);
    char *password, *name;


    FILE *userFile = fopen("users.txt", "r");
    if (load_users(userFile) == 1)
        puts("No such file\n");
    


    loop_l:
    puts("Enter user name: ");
    name = my_gets();
    puts("Enter password: ");
    password = my_gets();

    if (strcmp(name, "librarian") == 0 && strcmp(password, "librarian") == 0) {
        status = 2;
        return;
    }

    current = userHead;
    while (1) {
        if (current->name == name) {
            if (current->password == password) {
                puts("Account logged successfully!\n");
                status = 1;
                return;
            }
            else {
                puts("Wrong password!\n");
                goto loop_l;
            }
            

            
        } else if (current->next != NULL) {
            puts("Account not exist!\n");
            goto loop_l;
        }
        current = current->next;
    }
    return;
}

/********************************************/
/********************************************/

int load_users(FILE *file) {
    User *current;
    int result = 1;

    if (file == NULL)
        puts("No user file!");
    else {
        current = userHead;
        current->next = (User*) malloc(sizeof(User));
        while (!feof(file)) {
            fread(current, sizeof(User), 1, file);
            current = current->next;
        }
        current = NULL;
        result = 0;
    }
    
    return result;
}

int store_users(FILE *file) {
    User *current;
    int result = 1;

    if (file == NULL)
        puts("No user file!");

    else {
        current = userHead;
        for (; current != NULL; current = current->next)
            fwrite(current, sizeof(User), 1, file);
        result = 0;
    }
    return result;
}





