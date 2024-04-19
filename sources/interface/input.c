#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

struct input {
	char *text;
	int type;
	int length;
};

char* getTextInput(Input *input) {return (input) ? input->text : NULL;}

Input* criarInput(const int type) {
	Input *novo = NULL;
	novo = (Input*) malloc(sizeof(Input));
	if(novo) {
		novo->text = NULL;
		novo->type = type;
		novo->length = 0;
	}
	return novo;
}

void inserirCaractere(Input *const input, const char c) {
	if(input) {
		if(input->text == NULL) {
			input->text = (char*) calloc(2, sizeof(char));
			input->text[0] = c;
		} else {
			input->text = (char*) realloc(input->text, sizeof(char) * (input->length + 2));
			input->text[input->length] = c;
		}
		input->length++;
		input->text[input->length] = '\0';
	}
}
