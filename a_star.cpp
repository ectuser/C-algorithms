#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <regex>
#include <cstdlib>

using namespace std;

int manhattan_distance(int x1, int y1, int x2, int y2) {
	return x2 - x1 + y2 - y1;
}

struct Point {
	int visited, to_watch, dist_from_start, func, parent_x, parent_y;
};

struct Coords {
	int x, y;
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m; cin >> n >> m;
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1--; y1--; x2--; y2--;
	swap(x1, y1); swap(x2, y2);

	Point **points = new Point*[n];
	int move_x[] = { -1, 0, 1, 0 };
	int move_y[] = { 0, 1, 0, -1 };

	int **matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
		points[i] = new Point[m];
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
			points[i][j].visited = 0;
			points[i][j].to_watch = 0;
			points[i][j].dist_from_start = 10000000;
			points[i][j].func = 100000000;

		}
	}

	points[x1][y1].to_watch = 1;
	points[x1][y1].parent_x = 0;
	points[x1][y1].parent_y = 0;
	points[x1][y1].dist_from_start = 0;
	points[x1][y1].func = points[x1][y1].dist_from_start + manhattan_distance(x1, y1, x2, y2);

	while (true) {
		bool cond = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (points[i][j].to_watch == 0) {
					cond = false;
					break;
				}
		if (cond == true)
			break;

		int min_vertex = 10000000000;
		int x, y;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (points[i][j].to_watch == 1 && points[i][j].func < min_vertex) {
					min_vertex = points[i][j].func;
					x = i; y = j;
				}
		if (x == x2 && y == y2) {
			break;
		}

		points[x][y].to_watch = 0;
		points[x][y].visited = 1;

		for (int move = 0; move < 4; move++) {
			if (x + move_x[move] < n && 
				x + move_x[move] >= 0 && 
				y + move_y[move] < m && 
				y + move_y[move] >= 0) {
				
				int new_x = x + move_x[move],
					new_y = y + move_y[move];

				if (matrix[new_x][new_y] != -1) {
					int tentative_score = points[x][y].dist_from_start + 1;
					
					if (points[new_x][new_y].visited == 1 && tentative_score >= points[new_x][new_y].dist_from_start)
						continue;
					if (points[new_x][new_y].visited == 0 || tentative_score < points[new_x][new_y].dist_from_start) {
						points[new_x][new_y].parent_x = x; points[new_x][new_y].parent_y = y;
						points[new_x][new_y].dist_from_start = tentative_score;
						points[new_x][new_y].func = points[new_x][new_y].dist_from_start + manhattan_distance(new_x, new_y, x2, y2);
						points[new_x][new_y].to_watch = 1;
					}
				}
			}
		}
	}
	Coords answers[100000];
	int x = x2, y = y2;
	int answer = 1;
	while (x != x1 || y != y1) {
		answers[answer].x = x + 1;
		answers[answer].y = y + 1;
		int new_x = points[x][y].parent_x;
		int new_y = points[x][y].parent_y;

		x = new_x; y = new_y;
		answer++;
	}
	answers[answer].x = x1 + 1;
	answers[answer].y = y1 + 1;
	cout << answer << endl;;
	for (int i = answer; i > 0; i--) {
		cout << answers[i].y << " " << answers[i].x << endl;
	}
	return 0;
}