#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#pragma once

int acs_alog(int a, int b);
long long acs_big_alog(long long a, long long b);

char* acs_add(char *a, char *b);
void acs_creplace(char *v, char a, char b);
// char* acs_sreplace(char *v, char *a, char *b);
char* acs_printint(int a);
int acs_parseint(char *a);
char* acs_big_printint(long long a);
char* acs_toobig_printint(unsigned long long a);
long long acs_big_parseint(char *a);
char* acs_cp(char *a);
struct acs_spliter {
    char *s;
    int sz;
    int p;
    int end;
};
typedef struct acs_spliter acs_spliter;
acs_spliter* acs_spliter_init(char* str);
void acs_spliter_free(acs_spliter* self);
char* acs_spliter_char(acs_spliter* self, char split);
char* acs_spliter_string(acs_spliter* self, char *split);
char* acs_milloc(char *str);
