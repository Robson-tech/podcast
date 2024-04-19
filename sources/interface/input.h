#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

typedef struct input Input;

char* getTextInput(Input *input);
Input* criarInput(const int type);
void inserirCaractere(Input *const input, const char c);

#endif
