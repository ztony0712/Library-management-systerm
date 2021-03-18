#include "user_management.h"
#include "interface.h"





void register_user () {
    create_user(userHead);
    create_user(current);
    char *name, *code1, *code2;

    FILE *userFile = fopen("users.txt", "r");
    if (load_user(userFile) == 1)
        puts("No such file\n");
    
    
    puts("Enter user name:");

    loop_r:
    gets(name);
    current = userHead->next;
    while (current->next != NULL) {
        if (current->name == name) {
            puts("This name is in use. Try another name.\n");
            goto loop_r;
        }
        current = current->next;
    }

    

    while (1) {
        puts("Enter password (more than 8 digits):");
        gets(code1);
        puts("Enter password again (more than 8 digits):");
        gets(code2);
        if (code1 == code2)
            break;
        puts("The passwords are inconsistent.");
    }


    create_user(new);
    new->name = name;
    new->password = code1;
    
    current->next = new;

    // fclose(userFile);
    // if (store_user(userFile) == 1)
    //     puts("No such file\n");

    puts("Account created successfully!");
    return;
}





void login_user() {
    create_user(current);
    char *name, *password, *code1, *code2;

    FILE *userFile = fopen("users.txt", "r");
    if (load_users(userFile) == 1)
        puts("No such file\n");
    


    loop_l:
    puts("Enter user name: ");
    gets(name);
    puts("Enter password: ");
    gets(password);

    if (strstr(name, "librarian") != NULL && strstr(password, "librarian") != NULL) {
        status = 2;
        return;
    }

    current = userHead->next;
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
    create_user(current);

    if (file == NULL)
        return 1;

    current = userHead;
    while (current->next != NULL) {
        fread(current, sizeof(User), 1, file);
        current = current->next;
    }
    return 0; 
}

int store_users(FILE *file) {
    create_user(current);

    if (file == NULL)
        return 1;

    current = userHead;
    while (current->next != NULL) {
        fwrite(current, sizeof(User), 1, file);
        current = current->next;
    }
    return 0;
}





