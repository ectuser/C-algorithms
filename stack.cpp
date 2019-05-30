#include <iostream>
#include <string>
using namespace std;

struct  Element {
	char val;
	Element *next;
};
class Stack
{
	Element *pbeg;
public:
	Stack() { pbeg = NULL; }
	~Stack();
	void push(char val);
	void show();
	char pop();
	bool check();
};

bool Stack::check() {
	Element *now = pbeg;
	if (now == NULL)
		return true;
	else
		return false;
}

void Stack::push(char val) {
	Element *ptr = new Element;
	ptr->val = val; ptr->next = pbeg;
	pbeg = ptr;
}
void Stack::show() {
	Element *temp = pbeg;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}
Stack::~Stack()
{
	Element *ptr;
	while (pbeg != NULL)
	{
		ptr = pbeg; pbeg = pbeg->next;
		delete ptr;
	}
}

char Stack::pop()
{
	if (!pbeg) return -1;
	Element *ptr = pbeg;
	char val = pbeg->val;
	pbeg = pbeg->next;
	delete ptr;
	return val;
}

bool check(char a, char b) {
	if (a == '[' && b == ']')
		return true;
	if (a == '(' && b == ')')
		return true;
	if (a == '{' && b == '}')
		return true;
	if (a == '<' && b == '>')
		return true;
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string str;
	Stack first;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '[' || str[i] == '(' || str[i] == '{' || str[i] == '<')
			first.push(str[i]);
		else {
			char open = first.pop(), close = str[i];
			if (check(open, close) == false) {
				cout << 0;
				return 0;
			}
		}
	}
	if (first.check() == true)
		cout << 1;
	else
		cout << 0;
	return 0;
}