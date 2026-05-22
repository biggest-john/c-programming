#include <stdio.h>
#include <stdlib.h>


typedef union{
	int age;
	float height;
	short donation;
} description;


int main (){
	/*the first method*/
	description p = {24};
	printf("I am %f years old.\n", p.age);

	/*the second method*/
	description q = {.donation=300};
	printf("You donated only %i\n", q.donation);
	return 0;

	/*the third method*/
	description z;
	z.height = 27.3;
	printf("Your height is %f\n", z.height );
	return 0;
}
