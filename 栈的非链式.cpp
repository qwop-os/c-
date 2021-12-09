/*
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
const int length = 10;

typedef struct {
	int* base;
	int* top;
	int stacksize;
}sqstack;

void initstack(sqstack* s) {
	s->base = new int[length];
	s->top = s->base;
	s->stacksize = length;
}

void push(sqstack* s, int e) {
	*(s->top) = e;
	s->top++;
}
void pop(sqstack* s, int* e) {
	if (s->top == s->base)
		return;
	*e = *--(s->top);
}
void clear(sqstack* s) {
	s->top = s->base;
}

void destorystack(sqstack* s) {
	int i,len;
	len = s->stacksize;
	//free(s->base);
	delete[] s->base;
	s->base = s->top = nullptr;
	s->stacksize = 0;
}

int  stack_length(sqstack* s) {
	return s->top - s->base;
}

int main() {
	sqstack s;
	initstack(&s);
	int a[10];
	for (int i=0; i < 10; i++) {
		a[i] = i;
	}
	for (auto i : a) {
		cout << i << " " << &i << endl;
		push(&s, i);
	}
	destorystack(&s);
	
	int e;
	
	for (auto i : a) {
		pop(&s, &e);
		cout << e << " ";
	}
	
	return 0;
}*/