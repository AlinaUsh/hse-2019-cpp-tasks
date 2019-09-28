#include "str.h"

#include<stdio.h>

char* my_strcpy(char* restrict dest, const char* restrict source){
    char* result = dest;
    while (*source){
        *dest = *source;
        ++source;
        ++dest;
    }
    *dest = '\0';
    return result;
}

char *my_strcat(char* restrict dst, const char* restrict src){
    if (src == NULL)
        return dst;
    char* result = dst;
    while (*dst){
        ++dst;
    }
    while (*src){
        *dst = *src;
        ++dst;
        ++src;
    }
    *dst = '\0';
    return result;
}

int my_strcmp(const char *first_str, const char *second_str){
    while ((*first_str && *second_str) && *first_str == *second_str){
        ++first_str;
        ++second_str;
    }
    return *first_str - *second_str;
}

int my_strlen(const char *str){
    int len = 0;
    while (*str){
        len++;
        ++str;
    }
    return len;
}

