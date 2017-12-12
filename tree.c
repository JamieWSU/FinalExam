#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"


void addNodeToTree(tNodep *top, tNodep new) {
	if (*top==NULL) 
			*top = new;
	else
		if (new->score > (*top)->score) 
			addNodeToTree(&((*top)->left),new);
		else
			addNodeToTree(&((*top)->right),new);
}

void addToTree(tNodep *top, char *name, int score) {
	tNodep tmp = malloc(sizeof(struct tNode));
	if (tmp) {
		tmp->name = strdup(name);
		tmp->score = score;
		tmp->left = NULL;
		tmp->right = NULL;
		addNodeToTree(top,tmp);
	}
	else
		fprintf(stderr,"Error allocating memory");
}
void inOrderTreeTraverse(tNodep top,void (*func)(tNodep)) {
	if (top) {
		inOrderTreeTraverse(top->left,func);
		func(top);
		inOrderTreeTraverse(top->right,func);
	}
	return;
}
void leafFirstTreeTraverse(tNodep top,void (*func)(tNodep)) {
	if (top) {
		leafFirstTreeTraverse(top->left,func);
		func(top);
	}
}
void freeNode(tNodep node) {
	free(node->name);
	free(node);
}
void freeTree(tNodep top) {
	leafFirstTreeTraverse(top,freeNode);
    free(top->name);
    free(top);
}
