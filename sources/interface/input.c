#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

struct input {
	char *text;
	int type;
	int length;
	int pointer;
};

Input* criarInput(int type, int length) {
	Input *novo = NULL;
	novo = (Input*) malloc(sizeof(Input));
	if(novo) {
		strcpy(novo->text, "");
		novo->type = type;
		novo->length = length;
		novo->pointer = -1;
	}
	return novo;
}
