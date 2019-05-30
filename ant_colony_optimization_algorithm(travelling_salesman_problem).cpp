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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, vertex_1, vertex_2; cin >> n;
	double **w = new double*[n];
	double **pher = new double*[n];
	string path = "", string_best_path = "";
	int *visited = new int[n];
	City *cities = new City[n];

	// коорд в матрицу весов
	for (int i = 0; i < n; i++)
	 	cin >> cities[i].x >> cities[i].y;
	for (int i = 0; i < n; i++) {
		w[i] = new double[n];
		pher[i] = new double[n];
		visited[i] = 0;
		for (int j = 0; j < n; j++) {
			double x1 = cities[i].x, y1 = cities[i].y;
			double x2 = cities[j].x, y2 = cities[j].y;
			w[i][j] = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
			// cin >> w[i][j];
			pher[i][j] = 1;
		}
	}

	double
		alpha = 1,
		beta = 1,
		pher_dis = 0.4,
		best_path = 100000000;

	for (int q = 0; q < 1000; q++) {
		path = "";
		for (int k = 0; k < n; k++) {
			visited[k] = 0;
		}
		int i = rand() % n;
		// int i = 0;

		// первая вершина и добавление ее к пути
		vertex_1 = i;
		path += to_string(i + 1) + " ";
		visited[i] = 1;

		// массив для вероятностей
		double *Ps = new double[n];
		for (int k = 0; k < n; k++)
			Ps[k] = 0;

		double SUM = 0;
		while (true){
		// for (int m = 0; m < n; m++) {
			for (int k = 0; k < n; k++)
				Ps[k] = 0;
			/*cout << "visited: " << endl;
			for (int k = 0; k < n; k++)
				cout << k + 1 << ": " << visited[k] << endl;*/

			// подсчитываем вероятность
			double znam = 0;
			for (int j = 0; j < n; j++) {
				if (j != i && w[i][j] != 0 && visited[j] == 0) {
					znam += pher[i][j] / w[i][j];
				}
			}
			for (int j = 0; j < n; j++) {
				if (j != i && w[i][j] != 0 && visited[j] == 0) {
					Ps[j] = (pher[i][j] * 1 / w[i][j]) / znam;
				}
			}

			// меняем вероятности на линию вероятностей
			int count = 1;
			for (int j = 1; j < n; j++) {
				if (visited[j] == 0) {
					Ps[j] = Ps[j - count] + Ps[j];
					// cout << "p: " << Ps[j] << endl;
					count = 1;
				}
				else
					count++;
			}

			// генерим рандомное число и определяем, куда на линии вероятности она попадет
			double r = ((double)rand() / (RAND_MAX));
			for (int j = 0; j < n; j++)
				if (visited[j] == 0) {
					// cout << "p: " << Ps[j - 1] << " " << Ps[j] << endl;
					if (r < Ps[j]) {
						SUM += w[i][j];
						vertex_2 = j;

						// испарение феромона
						pher[i][j] = (1 - pher_dis) * pher[i][j] + 1 / SUM;

						i = j;
						visited[i] = 1;
						path += to_string(i + 1) + " ";
						break;
					}
				}

			bool cond = true;
			for (int k = 0; k < n; k++)
				if (visited[k] == 0)
					cond = false;
			if (cond == true)
				break;
		}
		if (w[vertex_2][vertex_1] != 0) {
			SUM += w[vertex_2][vertex_1];
			if (SUM < best_path) {
				best_path = SUM;
				string_best_path = path;
			}
		}
	}
	cout << best_path << endl;
	cout << string_best_path << endl;

	return 0;
}