#include <iostream>
#include <vector>

using vb = std::vector<bool>;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;

bool augment(int vertex, vb& used, vi& parsoch_vertex_from_right, vvi& edges) {
	if (used[vertex]) return false;
	used[vertex] = true;
	for (int to_vertex : edges[vertex]) {
		if (parsoch_vertex_from_right[to_vertex] == -1 || augment(parsoch_vertex_from_right[to_vertex], used, parsoch_vertex_from_right, edges)) {
			parsoch_vertex_from_right[to_vertex] = vertex;
			return true;
		}
	}
	return false;
}

int parsoch(int n, vvi& edges) {
	vb used(n);
	vi parsoch_vertex_from_right(n);
	used.assign(n, false);
	parsoch_vertex_from_right.assign(n, -1);
	for (int vertex = 0; vertex < n; ++vertex) {
		if (augment(vertex, used, parsoch_vertex_from_right, edges)) {
			used.assign(n, false);
		}
	}
	int count = 0;
	for (int i : parsoch_vertex_from_right) {
		if (i == -1) {
			count += 1;
		}
	}
	return count;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vvi edges(n);
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		std::cin >> v1 >> v2;
		edges[v1 - 1].push_back(v2 - 1);
	}
	
	std::cout << parsoch(n, edges);
}
