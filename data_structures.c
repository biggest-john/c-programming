#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
	char *name;
	char *opens;
	char *closes;
	struct island *next;
}island;

void display_island_det(island *start){
	island *i = start;
	for(;i != NULL; i = i->next){
		printf("Name: %s\nOpen: %s-%s\n", i->name, i->opens, i->closes);
	}
}

void release_island_mem(island *start){
	island *i = start; 
	island *next = NULL;

	for(; i != NULL; i = next){
		next = i -> next;
		free( i -> name);
		free(i);
	}
}

island* create_island(char *name){
	island *i = malloc(sizeof(island));
	i->name = strdup(name); // this copies the name valu into some location on the heap
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;

	return i;
}

int main(){
	// dynamically creating and setting next island in the linked list from stdin
	island *start = NULL;
	island *intermediate = NULL;
	island *next = NULL;
	char name[80];

	for(; fgets(name,sizeof(name), stdin) != NULL; intermediate = next){
		next = create_island(name);
		if(start == NULL) start = next; // could have cut this out, but let's have a ref for a start point.
		if(intermediate != NULL){
			intermediate -> next = next;
		}
	}
	
	// this is where the start pointer shines, "helping to pin-point the start of the node for display and memory freedom."
	display_island_det(start);
	release_island_mem(start);

	return 0;
}
