#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *right;
	struct node *left;
} bst_node;

bst_node* create_node(int val){
	bst_node *node = (bst_node*) malloc(sizeof(bst_node));
	node-> data = val;
	node->right, node->left= NULL;
	return node;
}

void insert(bst_node **nodeptr, int val){
	if(!*nodeptr){
		*nodeptr = create_node(val);
		return;
	}
	if(val<(*nodeptr)->data) insert(&((*nodeptr)->left), val);
	else insert(&((*nodeptr)->right), val);	
}

void pre_order(bst_node **nodeptr){
	if(!*nodeptr) {
		return;
	}
	fprintf(stdout, "===> %i", (*nodeptr)->data);
	pre_order(&((*nodeptr)->left));
	pre_order(&((*nodeptr)->right));
}

void in_order(bst_node **nodeptr){
	if(!*nodeptr) {
		return;
	}
	in_order(&((*nodeptr)->left));
	fprintf(stdout, "===> %i", (*nodeptr)->data);
	in_order(&((*nodeptr)->right));
}

int min_element(bst_node **nodeptr) {
	if (!*nodeptr) {
		printf("Tree is empty.");
		return -1;
	}
	else if ((*nodeptr)->left == NULL) {
	return (*nodeptr)->data;
	}
	return min_element(&(*nodeptr)->left);
}

int max_element(bst_node **nodeptr) {
	if (!*nodeptr) {
		printf("Tree is empty");
		return -1;
	}
	else if ((*nodeptr)->right == NULL) {
		return (*nodeptr)->data;
	}
	return  max_element(&(*nodeptr)->right);
}
void post_order(bst_node **nodeptr){
	if(!*nodeptr) {
		return;
	}
	post_order(&((*nodeptr)->left));
	post_order(&((*nodeptr)->right));
	fprintf(stdout, "===> %i", (*nodeptr)->data);
}

void mem_free(bst_node **nodeptr) {
	if (!*nodeptr) {
		return;
	}
	mem_free(&(*nodeptr)->left);
	mem_free(&(*nodeptr)->right);
	free(*nodeptr);
	*nodeptr = NULL;
}

int main (){
	bst_node *root = NULL;
	for(int i=0; i<7;i++) {
		const int val[] = {50, 30, 70, 20, 40, 60, 80};
		insert(&root, val[i]);
	}
	
	pre_order(&root);
	puts("");
	in_order(&root);
	puts("");
	post_order(&root);
	puts("\n-----------------------------------");
	printf("The minimum value ====> %d\n",min_element(&root));
	printf("The maximum value ====> %d\n",max_element(&root));
	mem_free(&(root));
	return 0;
}
