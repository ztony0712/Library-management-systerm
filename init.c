 


void {
    // open bookfile
    FILE *bookFile;
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
}