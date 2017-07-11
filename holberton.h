#ifndef HOLBER_H
#define HOLBER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

/* helper_functions.c */
int _strcmp(char *s1, char *s2);
int str_eval(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

/* helper2.c */
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);

#endif /* HOLBER_H */
