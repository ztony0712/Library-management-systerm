#include "interface.h"
#include "user_management.h"
#include "book_management.h"

const BookArray *head;
const User *userHead;
User *loggedUser;
int status;

int main()
{
	start_interface();
    
	return 0;
}
