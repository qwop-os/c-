#include<iostream>
using std::cout;
using std::endl;
typedef struct stacknode {
	int data;
	stacknode* next;
}*linkstack_ptr;
typedef struct linkstack {
	linkstack_ptr top;
	int count;
};
void push(linkstack* s, int e)  {
	linkstack_ptr p = new stacknode();
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count++;
}
void pop(linkstack* s, int* e) {
	linkstack_ptr p;
	*e = s->top->data;
	p = s->top;
	s->top = s->top->next;
	delete p;
}
int main() {
	//linkstack* s = new linkstack();(1)
	linkstack s;//(2)
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = i;
	}
	for (auto i : a) {
		push(&s, i);
	}
	int e;
	for (auto i: a) {
		pop(&s, &e);
		cout << e << " ";
	}
}