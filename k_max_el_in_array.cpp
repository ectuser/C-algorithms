#include <cstdlib>
#include <iostream>
using namespace std;

void heapBottom(int *a, int begin, int end) {
	int now = begin;
	int left = begin * 2 + 1;
	while (left <= end) {
		if (left < end && a[left] > a[left + 1]) {
			left++;
		}
		if (a[now] > a[left]) {
			swap(a[left], a[now]);
			now = left;
			left = 2 * left + 1;
		}
		else {
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, el; cin >> n >> k;
	int *a = new int[k];
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	for (int i = k / 2; i >= 0; i--) {
		heapBottom(a, i, k - 1);
	}
	for (int i = 0; i < n - k; i++) {
		cin >> el;
		// cout << el << endl;
		if (el > a[0]) {
			a[0] = el;
			for (int i = k / 2; i >= 0; i--) {
				heapBottom(a, i, k - 1);
			}
		}
	}
	cout << a[0];
	return 0;
}