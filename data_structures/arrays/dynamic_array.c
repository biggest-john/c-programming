#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int *data;
	size_t size;
	size_t capacity;
} DynArray;


DynArray create_array(size_t capacity){
	DynArray arr;
	arr.data = malloc(sizeof(int) * capacity);
	arr.size = 0;
	arr.capacity = capacity;

	return arr;
}

void append(DynArray *arr, int val){
	// be weary of the fact that we are using post increment. Be mindful of the zero indexing as well.
	if(arr->size == arr->capacity){
		arr->capacity *= 2;
		arr->data = realloc(arr->data, sizeof(int) * arr-> capacity);
	}
	arr->data[arr->size] = val;
	arr->size++;
}
int insert(DynArray *arr, size_t index, int val){
	/*returns 1 if index is within bound and -1 if index is out of bound*/
	if(index < arr->size){
		if(arr->size < arr->capacity){ //current size has to be less than the capacity to avoid trying to push beyond the the capacity bound
			for(int i = arr->size - 1;i>=index;i--){
				arr->data[i+1] = arr->data[i];
			}
			arr->data[index] = val;
			arr->size = arr->size + 1;	
			return 1;
		}
	}
	return -1;
}

void free_array(DynArray *arr){
	free(arr->data);
}

int main(){
	DynArray arr = create_array(5);
	append(&arr,5);	
	append(&arr,34);
	append(&arr,22);
	append(&arr, 12);
	
	int i;
	for(i=0; i<arr.size;i++){
		printf("index -> %d......element -> %d\n", i, arr.data[i]);
	}

	insert(&arr, 2, 100);
	for(i=0; i<arr.size;i++){
		printf("index -> %d......element -> %d\n", i, arr.data[i]);
	}

	free_array(&arr);
	return 0;
}
