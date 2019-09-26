#include "str.h"

#include<stdio.h>

char* my_strcpy(char* restrict s1, const char* restrict s2)
{
    char* result = s1;
    while (*s2){
        *s1 = *s2;
        ++s2;
        ++s1;
    }
    *s1 = '\0';
    return result;
}

char *my_strcat(char* restrict s1, const char* restrict s2)
{
    if (s2 == NULL)
        return s1;
    char* result = s1;
    while (*s1){
        ++s1;
    }
    while (*s2){
        *s1 = *s2;
        ++s1;
        ++s2;
    }
    *s1 = '\0';
    return result;
}

int my_strcmp(const char *s1, const char *s2)
{
    while ((*s1 && *s2) && *s1 == *s2)
    {
        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}

int my_strlen(const char *s)
{
    int len = 0;
    while (*s)
    {
        len++;
        ++s;
    }
    return len;
}

