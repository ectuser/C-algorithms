#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <regex>
#include <cstdlib>

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cout.flush();
	double t_min = 0.000001, t_max = 100000, e, x, new_x;
	x = (double)(rand()) / RAND_MAX * 50 - 25;
	cout << "? " << x << endl;
	cin >> e;
	int i = 1;
	while (t_max > t_min) {
		for (int i = 0; i < 100; i++) {
			new_x = x + (double)(rand()) / RAND_MAX * 50 - 25;
			cout << "? " << new_x << endl;
			double new_e;
			cin >> new_e;
			double delta_e = new_e - e;
			if (delta_e <= 0) {
				x = new_x;
				e = new_e;
			}
			else {
				double p = exp(-delta_e / t_max);
				double val = (double)(rand()) / RAND_MAX;
				if (val <= p) {
					x = new_x;
					e = new_e;
				}
			}
		}
		t_max = t_max * 0.8;
		i++;
	}
	cout << "! " << x << endl;
	return 0;
}