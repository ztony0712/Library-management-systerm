#include "user_management.h"



static void register_user () {
    create_user(current);
    char *name, *code1, *code2;
    load_user();
    
    
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
    store_user(userHead);

    puts("Account created successfully!");

}





static void login_user() {
    create_user(current);
    char *name, *password, *code1, *code2;
    load_user();


    loop_l:
    puts("Enter user name: ");
    gets(name);
    puts("Enter password: ");
    gets(password);

    if (name == "librarian" && password == "librarian") {
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
                goto loop_l
            }
            

            
        } else if (current->next != NULL) {
            puts("Account not exist!\n");
            goto loop_l;
        }
        current = current->next;
    }

}