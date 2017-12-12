#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

#define BUFFERSIZE 512

void printTreeNode(tNodep node) {
	printf("%s:%d\n",node->name,node->score);
}

int main(int argc, char *argv[],char *env[]) {
	FILE *input;
	int ret;
	char *buffer = malloc(BUFFERSIZE);
	char *ptr;
	int score;
	tNodep top = NULL;

	if (argc != 2) {
		fprintf(stderr,"Please Supply a grades file as such: %s grades.txt\n",argv[0]);
		exit(1);
	}

	input = fopen(argv[1],"r");
	if (!input) {
		perror("Error opening file");
		exit(2);
	}

	ptr = fgets(buffer,BUFFERSIZE,input);
	while (ptr != NULL) {
		ptr = strchr(buffer,':');
		*(ptr)=0;
		score = atoi(ptr+1);
		addToTree(&top,buffer,score);
		ptr = fgets(buffer,BUFFERSIZE,input);	
	}
	fclose(input);

	inOrderTreeTraverse(top,printTreeNode);
	freeTree(top);
    free(buffer);
	return 0;
}
