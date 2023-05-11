#ifndef WHICH_H
#define WHICH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void    free_array(char **str);
int     count_words(char *str, char *c);
char    **split(char *str, char *c);
char    *join(char *s1, char *s2);
char    *is_file_in_path(char *file, char **dirs);

#endif