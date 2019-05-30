#include <iostream>
using namespace std;

struct  Element {
	int val;
	Element *next;
};
class List
{
	Element *pbeg, *pend, *pcurpos;
public:
	List() { pend = pbeg = pcurpos = NULL; }
	// ~List();
	void show();
	void push_back(int val);
	void swap(int a, int b);
};
void List::push_back(int val) {
	Element *pnew = new Element;
	pnew->val = val;
	pnew->next = NULL;
	if (!pbeg)
		pbeg = pend = pnew;
	else
		pend->next = pnew; pend = pnew;

}
void List::show() {
	Element *temp = pbeg;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}

void List::swap(int a, int b) {
	Element *pcur = pbeg, *temp = pbeg, *first = pbeg, *second = pbeg;
	Element *prevFirst = NULL, *prevSecond = NULL, *prev = NULL;
	int count = 0;
	if (pbeg == NULL)
		return;
	while (pcur != NULL) {
		if (pcur->val == a)
			if (count == 0)
				count = 1;
		if (pcur->val == b) {
			if (count == 0)
				count = 2;
		}
		pcur = pcur->next;
	}
	if (count == 2) {
		int temp1 = a;
		a = b;
		b = temp1;
	}

	pcur = pbeg;
	if (pcur->val == a) {
		// меняем первый элемент списка и другой данный
		while (pcur != NULL) {
			if (pcur->val == b) {
				second = pcur;
				prevSecond = prev;
				break;
			}

			prev = pcur;
			pcur = pcur->next;
		}
		prevSecond->next = pbeg;
		temp = pbeg->next;
		pbeg->next = second->next;
		second->next = temp;
		pbeg = second;
		return;
	}

	while (pcur != NULL) {
		if (pcur->val == a) {
			first = pcur;
			prevFirst = prev;
		}
		if (pcur->val == b) {
			second = pcur;
			prevSecond = prev;
		}
		prev = pcur;
		pcur = pcur->next;
	}
	pcur = pbeg;
	int condition = 0;
	for (; pcur; pcur = pcur->next) {
		if (pcur->val == b) {
			prevSecond->next = first;
			temp = second->next;
			second->next = first->next;
			condition = 1;
		}
		if (condition == 1 && pcur->val == a) {
			prevFirst->next = second;
			first->next = temp;
		}
	}


}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	List first;
	int a, b, c; cin >> a >> b;
	while (cin >> c) {
		first.push_back(a);
		a = b;
		b = c;
	}
	int fNumber = a, sNumber = b;
	first.swap(fNumber, sNumber);
	first.show();
	return 0;
}