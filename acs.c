#include "acs.h"

int acs_alog(int a, int b)
{
    int i = 0;
    while (a > 0) {
        a /= b;
        i++;
    }
    return i;
}

long long acs_big_alog(long long a, long long b)
{
    long long i = 0;
    while (a > 0) {
        a /= b;
        i++;
    }
    return i;
}

char *acs_add(char *a, char *b)
{
    char *o = malloc(strlen(a)+strlen(b)+1);
    sprintf(o, "%s%s", a, b);
    return o;
}

char *acs_substr(char *a, int start, int end)
{   /*
       a        start       end
       |          |          |
       0  1   2   3  4   5   6
       
       returns 3,4,5 from a
    */
    char *b = malloc(end-start+1);
    memcpy(b, a+start, end-start);
    b[end-start] = 0;
    return b;
}

void acs_creplace(char *v, char a, char b) {
    int s = strlen(v);
    for (int i = 0; i < s; i++) {
        if (v[i] == a)
            v[i] = b;
    }
}

char* acs_printint(int a) {
    char n = 0;
    if (a < 0) {
        n = 1;
        a = -a;
    }
    int S = acs_alog(a, 10);
    char *s = malloc(S);
    int p = 0;
    if (n) {
        s[0] = '-';
        p--;
    }
    while (a > 0) {
        s[S-1-p] = 0x30 + a % 10;
        a /= 10;
        p++;
    }
    return s;
}

int acs_parseint(char *a) {
    return atoi(a);
}

char *acs_big_printint(long long a)
{
    long long S = acs_big_alog(a, 10);
    char *s = malloc(S);
    int p = 0;
    while (a > 0) {
        s[S-1-p] = 0x30 + a % 10;
        a /= 10;
        p++;
    }
    return s;
}

char *acs_toobig_printint(unsigned long long a)
{
    unsigned long long S = acs_big_alog(a, 10);
    char *s = malloc(S);
    int p = 0;
    while (a > 0) {
        s[S-1-p] = 0x30 + a % 10;
        a /= 10;
        p++;
    }
    return s;
}

long long acs_big_parseint(char *a)
{
    long long v = 0;
    int i = 0;
    for (;;) {
        if (a[i] == 0)
            break;
        if (a[i] >= 0x30 || a[i] <= 0x39) {
            v *= 10;
            v += a[i] - 0x30;
        }
        i++;
    }
    return v;
}

char *acs_cp(char *a)
{
    int s = strlen(a);
    char *o = malloc(s);
    memcpy(o, a, s);
    return o;
}

acs_spliter* acs_spliter_init(char *str)
{
    acs_spliter* o = malloc(sizeof(acs_spliter)*1);
    o->s = str;
    o->p = 0;
    o->sz = strlen(str);
    o->end = 0;
    return o;
}

void acs_spliter_free(acs_spliter* self) {
    free(self->s);
    free(self);
}

char *acs_spliter_char(acs_spliter *self, char split)
{
    char *o = malloc(self->sz);
    memset(o, 0, self->sz);
    int i = self->p;
    for (;;) {
        if (i >= self->sz) {
            self->end = 1;
            return acs_milloc(o);
        }
        if (self->s[i] == split) {
            i++;
            break;
        }
        o[i-self->p] = self->s[i];
        i++;
    }
    self->p = i;
    return acs_milloc(o);
}

char *acs_spliter_string(acs_spliter *self, char *split)
{
    char *o = malloc(self->sz);
    int S = strlen(split);
    memset(o, 0, self->sz);
    int i = self->p;
    for (;;) {
        if (i >= self->sz) {
            self->end = 1;
            return acs_milloc(o);
        }
        if (self->s[i] == split[0]) {
            char res = 0;
            for (int j = 0; j < S; j++) {
                if (i+j > self->sz - 1 || self->s[i+j] != split[j]) {
                    res = 1;break;
                }
            }
            if (!res) {
                i+=S;
                break;
            }
        }
        o[i-self->p] = self->s[i];
        i++;
    }
    self->p = i;
    return acs_milloc(o);
}

char *acs_milloc(char *str)
{
    char* o = acs_cp(str);
    free(str);
    return o;
}
