#include <cstdlib>
#include <iostream>
using namespace std;

void qs(int *a, int l, int r) {
	int pastL = l, pastR = r;
	// int mid = (l + r) / 2;
	int randNumb = rand() % (r - l) + l;
	int el = a[randNumb];
	while (l < r) {
		// cout << mid << " " << el << " " << l << " " << a[l] << " " << r << " " << a[r] << endl;
		while (a[l] < el) {
			l++;
		}
		while (a[r] > el) {
			r--;
		}
		if (l <= r) {
			swap(a[l], a[r]);
			l++; r--;
		}
	}
	if (pastL < r) {
		qs(a, pastL, r);
	}
	if (l < pastR) {
		qs(a, l, pastR);
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
	qs(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}