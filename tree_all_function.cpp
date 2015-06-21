#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  Node
{
	int key;
	Node *left,*right;
}Node;

void insertKey(int key, Node **tree);
Node *findMin(Node * tree);
void deleteKey(int key, Node **tree);
void print_tree(Node *tree);
int countElement(Node *root);
int countleaf(Node *root);
int is_bal(Node *root);
int max(int x,int y);
int depth (Node *root);
int _print_t(Node *tree, int is_left, int offset, int depth, char s[][255]);
int main(){
	Node *root=NULL;
	for (int i = 0; i < 10; i++) { 
		int ikey = (rand() % 20) + 1;
		printf("Inserted element with key %d \n", ikey);
		insertKey(ikey, &root);   
	}
	//This tree struction.This function is thanks to Alex and  Miro
	print_tree(root);

	printf("Height on tree %d \n",depth(root));
	printf("Count of element %d \n",countElement(root));
	printf("Count of leaf %d \n",countleaf(root));
}
void insertKey(int key, Node **tree){
	if(NULL == *tree){
		*tree= (Node *)malloc(sizeof(**tree));
		(*tree)->key=key;
		(*tree)->left=NULL;
		(*tree)->right=NULL;
	}else if((*tree)->key<key) {
		insertKey(key,&(*tree)->right);
	}else if((*tree)->key>key){
		insertKey(key,&(*tree)->left);
	}else 
		fprintf(stderr, "Element is already in tree\n"); 
}
int _print_t(Node *tree, int is_left, int offset, int depth, char s[20][255])
{

	char b[20];

	int width = 5; 

	int i; 

	int left, right;

	if (!tree) return 0;

	sprintf(b, "(%03d)", tree->key);

	left  = _print_t(tree->left,  1, offset, depth + 1, s);

	right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

	for (i = 0; i < width; i++)

		s[2 * depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (i = 0; i < width + right; i++)

			s[2 * depth - 1][offset + left + width/2 + i] = '-';

		s[2 * depth - 1][offset + left + width/2] = '+';

		s[2 * depth - 1][offset + left + width + right + width/2] = '+';

	} else if (depth && !is_left) {

		for (i = 0; i < left + width; i++)

			s[2 * depth - 1][offset - width/2 + i] = '-';

		s[2 * depth - 1][offset + left + width/2] = '+';

		s[2 * depth - 1][offset - width/2 - 1] = '+';

	}

	return left + width + right;

}

void print_tree(Node *tree)

{ 

	int i;

	char s[20][255];

	for (i = 0; i < 20; i++)

		sprintf(s[i], "%80s", " ");

	_print_t(tree, 0, 0, 0, s);

	for (i = 0; i < 20; i++)

		printf("%s\n", s[i]);

}

Node *findMin(Node *tree){
	while(tree->left!=NULL)tree=tree->left;
	return tree;
}
void deleteKey(int key,  Node **T) {
	if (NULL == *T) {
		fprintf(stderr,"The tip, which must be switched off, is missing!\n");
	} else {
		if (key < (*T)->key)
			deleteKey(key, &(*T)->left);
		else if (key > (*T)->key)
			deleteKey(key, &(*T)->right);
		else  /* Element exclusion is found */
			if ((*T)->left && (*T)->right) {
				/* tip has two successor */
				/* Located tip for Exchange*/
				Node *replace = findMin((*T)->right);
				(*T)->key = replace->key;
				deleteKey((*T)->key, &(*T)->right);
				/* tip off */
			}
			else {
				/* element has zero or one subtrees */
				Node *temp = *T;
				if ((*T)->left)
					*T = (*T)->left;
				else
					*T = (*T)->right;
				free(temp);
			}
	} }
int countElement(Node *root)
{
	if (root != NULL) 
		return (1 + countElement(root->left) + countElement(root->right));
	else return 0;
}
int countleaf(Node *root){
	if(root == NULL)       
    return 0;
	 if(root->left == NULL && root->right==NULL)      
    return 1;            
		 else
	 return countleaf(root->left)+
			 countleaf(root->right); 
}
int max(int x,int y)

{
	if (x > y)
		return x;
	else return y;
}
int depth (Node *root)
{
	if (root != NULL)
		return (1 + max(depth(root->left), depth(root->right)));
	else return 0;

}
int is_bal(Node *root){
	int k;
	if(root!=NULL){
	k = abs(depth(root->left)-depth(root->right));
	return k<=1 && depth(root->left)&&depth(root->right);
	}
	else return 1;
}