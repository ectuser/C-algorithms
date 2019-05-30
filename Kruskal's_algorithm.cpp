#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
using namespace std;

struct Edge {
	int first, second, weight;
};

void sort(Edge *edges, int l, int r) {
	int pastL = l, pastR = r;
	int randNumb = rand() % (r - l) + l;
	int el = edges[randNumb].weight;
	while (l < r) {
		while (edges[l].weight < el) {
			l++;
		}
		while (edges[r].weight > el) {
			r--;
		}
		if (l <= r) {
			swap(edges[l], edges[r]);
			l++; r--;
		}
	}
	if (pastL < r) {
		sort(edges, pastL, r);
	}
	if (l < pastR) {
		sort(edges, l, pastR);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m; cin >> n >> m;
	Edge *edges = new Edge[m];

	int **ans_matrix = new int*[n];
	for (int i = 0; i < m; i++)
		cin >> edges[i].first >> edges[i].second >> edges[i].weight;
	sort(edges, 0, m - 1);
	
	int *comp = new int[n];
	for (int i = 0; i < n; i++) {
		comp[i] = i;
		ans_matrix[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans_matrix[i][j] = 0;
	
	int full_weight = 0;
	for (int i = 0; i < m; i++) {
		if (comp[edges[i].first] != comp[edges[i].second]) {
			// cout << edges[i].first << " " << edges[i].second << " " << edges[i].weight << endl;
			if (ans_matrix[edges[i].first - 1][edges[i].second - 1] != edges[i].weight) {
				full_weight += edges[i].weight;
				ans_matrix[edges[i].first - 1][edges[i].second - 1] = edges[i].weight;
				ans_matrix[edges[i].second - 1][edges[i].first - 1] = edges[i].weight;
			}


			for (int j = 0; j < n; j++)
				if (comp[j] == comp[edges[i].second])
					comp[j] = comp[edges[i].first];
		}
	}
	cout << full_weight << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << ans_matrix[i][j] << " ";
		cout << endl;
	}
	return 0;
}