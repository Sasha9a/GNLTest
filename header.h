#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define WHITE   "\033[1;37m"

void    *testing(char *s, size_t size, int (*f)(int, char**));
void    *testing_bonus(char *s, char *s1, char *s2, char *s3, size_t size, int (*f)(int, char**));

#endif