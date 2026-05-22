#include <stdio.h>
#include <limits.h> /*this provides you with the sizes of int and char*/
#include <float.h> /*provides you with the sizes for float and doubles*/

int main(){
	printf("the value of INT_MAX is %i\n", INT_MAX);
	printf("the value of INT_MIN is %i\n", INT_MIN);
	printf("the size of an int is %zi bytes.\n", sizeof(int));

	printf("the value of FLT_MAX is %f\n", FLT_MAX);
	printf("the value of FLT_MIN is %f\n", FLT_MIN);
	printf("the size of an float is %zi bytes.\n", sizeof(float));

}
