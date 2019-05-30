#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	const int MAX_NUMBER = 1000000000;
	int n, s, f; cin >> n >> s >> f;
	s--; f--;
	
	int *visited = new int[n];
	int *dist = new int[n];

	int **M = new int*[n];
	for (int i = 0; i < n; i++) {
		M[i] = new int[n];
		visited[i] = 0;
		dist[i] = MAX_NUMBER;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> M[i][j];

	dist[s] = 0;
	visited[s] = 1;
	queue<int> q;

	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {
			if (visited[i] == 0 && M[v][i] >= 0 && dist[i] > M[v][i] + dist[v] && v != i) {
				dist[i] = M[v][i] + dist[v];
				q.push(i);
			}
		}
	}
	if (dist[f] == MAX_NUMBER)
		cout << -1;
	else
		cout << dist[f];

	return 0;
}