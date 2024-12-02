#include "acs.h"

void t1(char** argv) {
    int s = strlen(argv[1]);
    char* value = malloc(s);
    strcpy(value, argv[1]);
    acs_creplace(value, ',', '.');
    acs_spliter* spliter = acs_spliter_init(value);
    for (;;) {
        char *o = acs_spliter_char(spliter, '.');
        printf("next: %s\n", o);
        if (spliter->end) 
            break;
        free(o);
    }
}
void t2(char** argv) {
    int s = strlen(argv[2]);
    char* value = malloc(s);
    strcpy(value, argv[2]);
    acs_creplace(value, ',', '.');
    acs_spliter* spliter = acs_spliter_init(value);
    for (;;) {
        char *o = acs_spliter_string(spliter, "--");
        printf("next: %s\n", o);
        if (spliter->end) 
            break;
        free(o);
    }
}

int main(int argc, char** argv) {
    t1(argv);
    t2(argv);
    printf("print big number: %s\n", acs_toobig_printint(0x1000000000000000ULL));
    printf("print negative number: %s\n", acs_printint(-2));
    printf("substr test: \"%s\"\n", acs_substr("Hello, world", 7, 12));
}