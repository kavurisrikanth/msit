/*
Is it possible to typecast a struct into a union (or vice versa)?
Kavuri Srikanth
*/

#include <stdio.h>
#include <stdlib.h>

// Created a struct.
struct test_struct {
    int a;
    float b;
    // float c;
};

// Created a union.
union test_union {
    int a;
    float b;
    // char c;
};

int main(void) {
    
    /* Using pointers.
        This seems to be OK. */
    struct test_struct *s = calloc(1, sizeof(struct test_struct));
    s->b = 12.5;
    s->a = 10;
    printf("%d %.2f\n", s->a, s->b);
    
    union test_union *u = (union test_union *)s;
    printf("%d %f\n", u->a, u->b);
    free(u);
    
    /* Using non-pointer variables.
       This is throwing a compilation error, but it isn't explicitly telling me that the cast is not allowed. */
    // struct test_struct s;
    // s.a = 10;
    // s.b = 12.5;
    // printf("%d %.2f\n", s.a, s.b);

    //union test_union u = (union test_union)s;
    //printf("%d\n", u.a);
    // printf("%d %f\n", u.a, u.b);
    
    return 0;
}
