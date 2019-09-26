#include<stdio.h>
#include<assert.h>
#include<string.h>
#include "str.h"
#include "test_str.h"

void test_strcpy()
{
    char s[300] = "";
    char* test = s;
    assert(my_strcpy(test, "qwertyuiop") == strcpy(test, "qwertyuiop"));
    return;
}

void test_strcat()
{
    char s[300] = "hell";
    char* test = s;
    assert(my_strcat(test, "hello") == strcat(test, "hello"));
    return;
}

void test_strcmp()
{
    assert(my_strcmp("hell", "hello") < 0);
    assert(my_strcmp("qwertyuiop", "qwertyuiop") == 0);
    assert(my_strcmp("hell1234", "hell") > 0);
    return;
}

void test_strlen()
{
    assert(my_strlen("hell") == strlen("hell"));
    assert(my_strlen("1") == strlen("1"));
    assert(my_strlen("") == strlen(""));
    assert(my_strlen("hello") != strlen("hell"));
    assert(my_strlen("hell") != strlen("hello"));
    return;
}
