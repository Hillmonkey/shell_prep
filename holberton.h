#ifndef HOLBER_H
#define HOLBER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFSIZE 1024

/* helper_functions.c */
int _strcmp(char *s1, char *s2);
int str_eval(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

/* helper2.c */
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int init_char_buffer(char *buffer, int bufsize);
int init_Cptr_buffer(char **buffer, int bufsize);

#endif /* HOLBER_H */
