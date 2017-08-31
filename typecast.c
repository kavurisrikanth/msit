#include <stdio.h>
#include <stdlib.h>

struct test_struct {
    int a;
    float b;
    // float c;
};

union test_union {
    int a;
    float b;
    // char c;
};

int main(void) {
    struct test_struct *s = calloc(1, sizeof(struct test_struct));
    s->b = 12.5;
    s->a = 10;
    printf("%d %.2f\n", s->a, s->b);
    
    // struct test_struct s;
    // s.a = 10;
    // s.b = 12.5;
    // printf("%d %.2f\n", s.a, s.b);
    

    union test_union u2;
    u2.a = 20;
    struct test_struct s2 = (struct test_struct)u2;
    printf("%d\n", s2.a);

    union test_union u = (union test_union)s;
    printf("%d\n", u.a);
    // printf("%d %f\n", u.a, u.b);
    
    // union test_union *u = (union test_union *)s;
    // printf("%d %f\n", u->a, u->b);
    
    // free(u);
    
    // printf("%d\n", u.a);
    
    return 0;
}