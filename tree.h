#ifndef __TREE__
#define __TREE__

typedef struct tNode * tNodep;

struct tNode {
	tNodep left;
	tNodep right;
	char *name;
	int score;
};

void addToTree(tNodep *top, char *name, int score);
void inOrderTreeTraverse(tNodep top,void (*func)(tNodep));
void freeTree(tNodep top);

#endif