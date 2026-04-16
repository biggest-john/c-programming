#include <stdio.h>

int main() {
    int drinks[] = {4,2,3};
    int *pDrinks = drinks;

    char arrayString[] = "This is the string array";

    char *pString = arrayString;

    printf("This is use of pointer arithmetic--> %i\n", *(pDrinks + 1));
    printf("This is me shifting the values of the string to be printed-->  %s\n", pString+1);

    return 0;
}
