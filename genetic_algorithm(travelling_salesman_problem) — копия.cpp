
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <regex>
#include <cstdlib>

using namespace std;

struct City {
	double x, y;
};

int main() {
	cout << fixed << setprecision(7);
	cout.flush();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, vertex_1, vertex_2; cin >> n;
	int amount = 100; // кол-во особей первоначально
	double **w = new double*[n];
	int **path = new int*[amount];
	for (int i = 0; i < amount; i++) {
		path[i] = new int[n + 1];
		for (int j = 0; j < n; j++)
			path[i][j] = -1;
	}
	int *visited = new int[n];
	City *cities = new City[n];

	// коорд в матрицу весов
	for (int i = 0; i < n; i++)
		cin >> cities[i].x >> cities[i].y;
	for (int i = 0; i < n; i++) {
		w[i] = new double[n];
		visited[i] = 0;
		for (int j = 0; j < n; j++) {
			double x1 = cities[i].x, y1 = cities[i].y;
			double x2 = cities[j].x, y2 = cities[j].y;
			w[i][j] = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
			// cout << i + 1 << " -> " << j + 1 << ": " << w[i][j] << endl;
		}
	}
	// создание первоначальной популяции 
	for (int i = 0; i < amount; i++) {
		int start_pos = rand() % n;
		path[i][0] = start_pos;
		for (int j = 1; j < n; j++) {
			int next_pos;
			while (true) {
				bool cond = true;
				next_pos = rand() % n;
				for (int k = 0; k < n; k++) {
					if (k != j) {
						if (next_pos == path[i][k] || next_pos == path[i][0]) {
							cond = false;
							break;
						}
					}
				}
				if (cond == true)
					break;
			}
			path[i][j] = next_pos;
		}
		path[i][n] = start_pos;
	}
	// считаем длину каждой особи
	double best_individual = 1000000000, worst_individual = -1;
	int number_best_individual, number_worst_individual;
	for (int i = 0; i < amount; i++) {
		double SUM = 0;
		for (int j = 1; j <= n; j++) {
			SUM += w[path[i][j - 1]][path[i][j]];
		}
		if (SUM < best_individual) {
			best_individual = SUM;
			number_best_individual = i;
		}
		if (SUM > worst_individual) {
			worst_individual = SUM;
			number_worst_individual = i;
		}
	}
	
	for (int st = 0; st < 1000; st++){
	// while (clock() < 0.99 * CLOCKS_PER_SEC) {
		// мутация
		int random_point_1 = rand() % n;
		int random_point_2 = rand() % n;
		while (random_point_1 == random_point_2)
		 	random_point_2 = rand() % n;
		for (int h = 0; h <= n; h++)
			path[number_worst_individual][h] = path[number_best_individual][h];
		swap(path[number_worst_individual][random_point_1], path[number_worst_individual][random_point_2]);
		path[number_worst_individual][n] = path[number_worst_individual][0];

		// лучший и худший варианты 
		best_individual = 100000000; worst_individual = -1;

		for (int i = 0; i < amount; i++) {

			double SUM = 0;
			for (int j = 1; j <= n; j++) {
				SUM += w[path[i][j - 1]][path[i][j]];
			}
			if (SUM < best_individual) {
				best_individual = SUM;
				number_best_individual = i;
			}
			if (SUM > worst_individual) {
				worst_individual = SUM;
				number_worst_individual = i;
			}
		}
		if (number_best_individual == number_worst_individual) {
			cout << best_individual << endl;
			for (int g = 0; g < n; g++)
				cout << path[number_best_individual][g] + 1 << " ";
			return 0;
		}
	}
	cout << best_individual << endl;
	for (int g = 0; g < n; g++)
		cout << path[number_best_individual][g] + 1 << " ";
	return 0;
}