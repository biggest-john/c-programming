#include <stdio.h>
#include <stdlib.h>

/*void printing_val(char *pStr) {
    printf("%s", pStr);
}*/

void test(char *m){
	printf("%i\n", sizeof(*m));
	printf("%s", m);
}

int main() {
    /*char *str = "Hello, my name is John.";
    printing_val(str)*/
	/*char *str = "Hello my name is john";
	test(str);
	printf("\n %p \n", str);*/
	int nums[5];
	//printf("%i", 3[nums]);
	puts("input a sequence of integers.");
	scanf("%5i", nums);
	for(int i = 0; i<5;i++){
		printf("%i", nums[i]);
	}
}
