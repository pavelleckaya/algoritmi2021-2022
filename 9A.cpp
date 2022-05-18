#include <iostream>
#include <vector>
#include <set>

using vvpi = std::vector<std::vector<std::pair<int, int>>>;
using vvi = std::vector<std::vector<int>>;
using vi = std::vector<int>;

long long algorithm_Prima(int n, vvpi& edges) {
	long long answer = 0;
	vi use(n);
	vi vetex_to_cost(n, 1000001);
	for (auto el : edges[0]) {
		vetex_to_cost[el.first] = el.second;
	}
	use[0] = -1;
	int count_v = 1;
	while (count_v != n) {
		count_v += 1;
		int min_edge = 1000001;
		int vertex_min_edge = -1;
		for (int i = 0; i < n; ++i) {
			if (vetex_to_cost[i] < min_edge && use[i] != -1) {
				min_edge = vetex_to_cost[i];
				vertex_min_edge = i;
			}
		}
		answer += min_edge;
		for (auto el :edges[vertex_min_edge]) {
			vetex_to_cost[el.first] = std::min(el.second, vetex_to_cost[el.first]);
		}
		use[vertex_min_edge] = -1;
	}
	return answer;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vvpi edges(n);
	for (int i = 0; i < m; ++i) {
		int vertex1, vertex2, cost;
		std::cin >> vertex1 >> vertex2 >> cost;
		edges[vertex1 - 1].push_back({ vertex2 - 1, cost });
		edges[vertex2 - 1].push_back({ vertex1 - 1, cost });
	}
	std::cout << algorithm_Prima(n, edges);
}
