#include <iostream>
#include <vector>
#include <set>

using spipii = std::set<std::pair<int, std::pair<int, int>>>;
using vvi = std::vector<std::vector<int>>;
using vi = std::vector<int>;

int get_parent(int vertex, vi& parent_in_this_tree) {
	if (parent_in_this_tree[vertex] == -1) return vertex;
	return parent_in_this_tree[vertex] = get_parent(parent_in_this_tree[vertex], parent_in_this_tree);
}

void unite_vertex(int vertex1, int vertex2, vi& parent_in_this_tree, vi& size_tree) {
	vertex1 = get_parent(vertex1, parent_in_this_tree);
	vertex2 = get_parent(vertex2, parent_in_this_tree); // vertex2 != vertex1
	if (size_tree[vertex1] < size_tree[vertex2]) std::swap(vertex2, vertex1);
	parent_in_this_tree[vertex2] = vertex1;
	size_tree[vertex1] += size_tree[vertex2];
}

long long algorithm_Kruscala(int n, spipii& edges) {
	long long answer = 0;
	vi parent_in_this_tree(n, -1);
	vi size_tree(n, 1);
	auto it = edges.begin();
	for (int i = 0; i < edges.size(); ++i, ++it) {
		auto iter = *it;
		int vertex1 = iter.second.first, vertex2 = iter.second.second;
		if (get_parent(vertex1, parent_in_this_tree) != get_parent(vertex2, parent_in_this_tree)) {
			unite_vertex(vertex1, vertex2, parent_in_this_tree, size_tree);
			answer += iter.first;
		}
	}
	return answer;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	spipii edges;
	for (int i = 0; i < m; ++i) {
		int vertex1, vertex2, cost;
		std::cin >> vertex1 >> vertex2 >> cost;
		edges.insert({ cost, {vertex1 - 1, vertex2 - 1} });
	}
	std::cout << algorithm_Kruscala(n, edges);
}
