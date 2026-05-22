#include <stdio.h>
#include <stdlib.h>

int right_shift(int value, int n) {
    return value >> n;
}

int left_shift(int value, int n) {
    return value << n;
}

void * get_heap_space(size_t size) {
    void *ptr = malloc(size);

    return ptr;
}

int main () {
    int a = 12 , b = 10;
    printf("%i \n", a & b);
    printf("%i \n", a | b);
    printf("%i \n", a ^ b);
    printf("%i --- %i\n", ~a ,  ~b);

    return 0;
}