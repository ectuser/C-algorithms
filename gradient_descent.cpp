#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
#include <regex>
using namespace std;

int main() {
	cout.flush();
	double x, y, l, fun = 1000000, new_func = 100000000;
	double x1 = 0, y1 = 0;
	l = 0.749000;
	cout << "? 0 0" << endl;
	double eps = 0.000001;
	cin >> x >> y >> fun;
	while(true) {
		x1 = x1 - l * x;
		y1 = y1 - l * y;
		cout << fixed << setprecision(6) << "? " << x1 << " " << y1 << endl;
		if (abs(fun - new_func) <= eps)
			break;
		else {
			fun = new_func;
			cin >> new_func >> x >> y;
		}
	}
	cout << fixed << setprecision(6) << "! " << x1 << " " << y1 << endl;
	return 0;
}