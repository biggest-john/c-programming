#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int  width;
	int height;
}rectangle;

int compare_areas(const void* a, const void* b){
	rectangle *p_a = (rectangle*) a;
	rectangle *p_b = (rectangle*) b;
	int area_a = (p_a->width) * (p_a->height);
	int area_b = (p_b->width) * (p_b->height);

	return area_a - area_b;
}

int main(){
	char arr[] = "my name is John Martins";
	char **p = arr;
	return 0;
}
