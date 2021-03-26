#ifndef GLOBAL_MANAGEMENT_GUARD__H 
#define GLOBAL_MANAGEMENT_GUARD__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define puts(s) fputs(s, stdout)

char *my_gets (void);

void init (void);

void end (void);



#endif

