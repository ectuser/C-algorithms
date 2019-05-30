#include <iostream>
#include <string>
using namespace std;
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, w; cin >> n >> w;
	int *ws = new int[n + 1];
	int *ps = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> ps[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> ws[i];
	}
	int **a = new int*[n + 1];
	string **answers = new string*[n + 1];
	for (int i = 0; i <= n; i++) {
		a[i] = new int[w + 1];
		answers[i] = new string[w + 1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= w; j++) {
			a[i][j] = 0;
			answers[i][j] = "";
		}
	}
	for (int i = 1; i <= n; i++) {
		bool condition = false;
		for (int j = 0; j <= w; j++) {
			if (ws[i] > j) {
				a[i][j] = a[i - 1][j];
				answers[i][j] += answers[i - 1][j] + " ";
			}
			else {
				int first = a[i - 1][j];
				int second = a[i - 1][j - ws[i]] + ps[i];
				a[i][j] = max(first, second);
				if (second > first) {
					answers[i][j] += answers[i - 1][j - ws[i]] + " " + to_string(i);
				}
				else {
					answers[i][j] += answers[i - 1][j] + " ";
				}
			}
		}
	}
	cout << answers[n][w];
	return 0;
}