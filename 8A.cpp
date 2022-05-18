#include <iostream>
#include <vector>
#include <deque>

using str = std::string;
using vpii = std::vector<std::pair<int, int>>;

 vpii where_can_go(std::pair<int, int> s) {
	vpii where;
	int start_first_coord = s.first;
	int start_second_coord = s.second;
	if (start_first_coord + 2 < 8 && start_second_coord + 1 < 8) {
		where.push_back({ start_first_coord + 2, start_second_coord + 1 });
	}
	if (start_first_coord + 2 < 8 && start_second_coord - 1 >= 0) {
		where.push_back({ start_first_coord + 2, start_second_coord - 1 });
	}
	if (start_first_coord + 1 < 8 && start_second_coord + 2 < 8) {
		where.push_back({ start_first_coord + 1, start_second_coord + 2 });
	}
	if (start_first_coord + 1 < 8 && start_second_coord - 2 >= 0) {
		where.push_back({ start_first_coord + 1, start_second_coord - 2 });
	}
	if (start_first_coord - 1 >= 0 && start_second_coord + 2 < 8) {
		where.push_back({ start_first_coord - 1, start_second_coord + 2 });
	}
	if (start_first_coord - 1 >= 0 && start_second_coord - 2 >= 0) {
		where.push_back({ start_first_coord - 1, start_second_coord - 2 });
	}
	if (start_first_coord - 2 >= 0 && start_second_coord + 1 < 8) {
		where.push_back({ start_first_coord - 2, start_second_coord + 1 });
	}
	if (start_first_coord - 2 >= 0 && start_second_coord - 1 >= 0) {
		where.push_back({ start_first_coord - 2, start_second_coord - 1 });
	}
	return where;
}

std::vector<std::string> bfs(str start, str finish) {
	int start_first_coord = start[0] - 'a';
	int start_second_coord = start[1] - '1';
	int finish_first_coord = finish[0] - 'a';
	int finish_second_coord = finish[1] - '1';
	
	std::vector<std::vector<int>> dist(8, std::vector<int>(8));
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			dist[i][j] = 1000;
		}
	}
	dist[start_first_coord][start_second_coord] = 0;


	std::deque<std::pair<int, int>> vertexs;
	vertexs.push_back({start_first_coord, start_second_coord});
	
	std::vector<std::vector<std::pair<int, int>>> parents(8, std::vector < std::pair<int, int>>(8));
	
	while(!vertexs.empty()) {
		auto vertex = vertexs.front();
		vpii where_can_go_ = where_can_go(vertex);
		vertexs.pop_front();
		for (auto where_vertex : where_can_go_) {
			if (dist[where_vertex.first][where_vertex.second] == 1000) {
				parents[where_vertex.first][where_vertex.second] = vertex;
				dist[where_vertex.first][where_vertex.second] = dist[vertex.first][vertex.second] + 1;
				vertexs.push_back(where_vertex);
			}
			if (where_vertex == std::pair<int, int>{ finish_first_coord, finish_second_coord }) {
				break;
			}
		}
	}
	std::vector<std::pair<int, int>> ans(dist[finish_first_coord][finish_second_coord] + 1);
	std::pair<int, int> son = {finish_first_coord, finish_second_coord};
	ans[ans.size() - 1] = son;
	for (int i = ans.size() - 2; i >= 0; --i) {
		ans[i] = parents[son.first][son.second];
		son = parents[son.first][son.second];
	}
	ans[0] = son;
	std::vector<std::string> answer(ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		answer[i] = (char)(ans[i].first + 'a');
		answer[i] += (char)(ans[i].second + '1');
	}
	return answer;
}

int main() {
	str start, finish;
	std::cin >> start >> finish;
	std::vector<std::string> answer = bfs(start, finish);
	for (int i = 0; i < answer.size(); ++i) {
		std::cout << answer[i] << '\n';
	}
}
