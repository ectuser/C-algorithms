#include <iostream>
using namespace std;

void heapBottom(int *a, int begin, int end) {
	int now = begin;
	int left = begin * 2 + 1;
	while (left <= end) {
		if (left < end && a[left] < a[left + 1]) {
			left++;
		}
		if (a[now] < a[left]) {
			swap(a[left], a[now]);
			now = left;
			left = 2 * left + 1;
		}
		else {
			break;
		}
	}
}

void heapSort(int *a, int n) {
	for (int i = n / 2; i >= 0; i--) {
		heapBottom(a, i, n - 1);
	}
	for (int i = n - 1; i >= 1; i--) {
		swap(a[0], a[i]);
		heapBottom(a, 0, i - 1);
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	heapSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}