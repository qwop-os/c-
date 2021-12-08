#include <iostream>
using std::cout;
using std::cin;
using std::endl;
typedef struct node {
	int data;
	struct node* next;
}*node_ptr;

int main() {
	int n;
	cin >> n;
	node_ptr head = NULL;
	node_ptr tail = NULL;
	int data;
	for (auto i = 0; i < n; i++) {
		node_ptr n = new node();
		cin >> data;
		n->data = data;
		n->next = NULL;
		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			tail->next = n;
			tail = tail->next;
		}

	}
	node_ptr cur = head;
	node_ptr pru = nullptr;
//删除指定的值
	int del;
	cin >> del;
	while (cur) {
		if (cur->data == del)
		{
			if (cur == head) {
				head = cur->next;
				cur = head;
			}
			else {
				pru ->next= cur->next;
				cur = pru->next;
			}
			n--;
		}
		else {
			pru = cur;
			cur = cur->next;
		}
	}
	cur = head;
	while (cur)
	{
		cout << cur->data<<" ";
		cur = cur->next;
	}
	cur = head;
	while (cur)
	{
		node_ptr a = cur;
		cur = cur->next;
		delete(a);
	}
	cout << endl;
	cout << n;
	return 0;
}
