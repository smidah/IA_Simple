#ifndef LIB_H
#define LIB_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>



void    my_putchar(char c);
int     my_putstr(char* str);
void    my_put_nbr(int n);
int	    my_getnbr(char *str);


#endif /* LIB_H */
