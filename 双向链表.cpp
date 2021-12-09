#include<iostream>
using std::cout;
using std::cin;
using std::endl;
typedef struct double_node {
	char data;
	double_node* next;
	double_node* prior;
}*node_ptr;

int initlist(node_ptr *l) {
	node_ptr p, q;
	int i;
	*l = new double_node();
	(*l)->next = nullptr;
	(*l)->prior = nullptr;
	p = *l;
	for (i = 0; i < 26; i++) {
		q = new double_node();
		q ->data = 'A' + i;
		q->prior = p;
		q->next = p->next;
		p->next = q;
		p = q;
	}
	p->next = (*l)->next;
	(*l)->next->prior = p;
	return 0;

}
//¿­ÈöÃÜÂë
void caesar(node_ptr*l,int i) {
	if (i>0)
	{
		while (i > 0)
		{
			*l = (*l)->next;
			i--;
	} }
	if (i<0)
	{
		while (i < 0) {
			*l = (*l)->next;
			i++;
	} }

}
int main() {
	node_ptr l;
	int n, i;
	cin >> n;
	initlist(&l);
	caesar(&l, n);
	for (i=0; i < 26; i++) {
		l = l ->next;
		cout << l->data;
	}
	
	return 0;
}