#include <stdio.h>
#include<stdlib.h>

typedef struct edges {
    int start; //index of the node the edge starts at
    int stop; //index of the node the edge ends at
}edges;

int main () {
    int vertex[] = {1,2,3,4,5,6,7,8,9,10};
    edges a = {.start=0, .stop = 4};
    edges b = {.start=0, .stop = 5};
    edges c = {.start=0, .stop = 8};
    edges d = {.start = 1, .stop = 5};
    edges e = {.start = 1, .stop = 6};
    edges f = {.start = 1, .stop = 7};
    edges g = {.start = 1, .stop = 9};
    edges h = {.start = 2, .stop = 8};
    edges i = {.start = 2, .stop = 5};
    edges j = {.start = 2, .stop = 3};
    edges k = {.start = 2, .stop = 6};
    edges l = {.start = 3, .stop = 4};
    edges m = {.start = 3, .stop = 7};
    edges n = {.start = 3, .stop = 9};
    edges o = {.start = 4, .stop = 5};
    edges p = {.start = 5, .stop = 8};
    edges q = {.start = 5, .stop = 6};
    edges r = {.start = 5, .stop = 9};
    edges s = {.start = 7, .stop = 9};



    edges *edge[] = {
        &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n , &o, &p, &q, &r, &s
    };

    for (int x=0; x< 19; x++) {

    }

    return 0;
}
