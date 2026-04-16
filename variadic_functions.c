#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
int sum_of_int(int count, ...){
	int total = 0;
	va_list ap;
	va_start(ap, count);
	int i;
	for(i=0;i<count; i++){
		total = total + va_arg(ap, int);
	}
	va_end(ap);
	return total;
}

int main(){
	int value = sum_of_int(6, 25, 409, 308, 23, 5,67);
	printf("the answer is %d\n", value);
	return 0;
}
