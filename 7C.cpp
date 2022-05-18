#include <iostream>
#include <vector>
#include <algorithm>
using vvi = std::vector<std::vector<int>>;
using vi = std::vector<int>;

void print(vvi& one) {
    for (int i = 0; i < one.size(); ++i) {
        for (int j = 0; j < one[i].size(); ++j) {
            std::cout << one[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void print(const vi& one) {
    for (int i = 0; i < one.size(); ++i) {
        std::cout << one[i] << ' ';
    }
}

void dfs(int vertex, int parent, int& timer, vvi& arr, vi& parents, vi& tin, vi& tout, vi& collor, bool& ans, vi& answer_arr) {
    tin[vertex] = timer++;
    collor[vertex] = 1;
    parents[vertex] = parent;
    for (int to : arr[vertex]) {
        if (ans == 1) {
            return;
        }
        else if (collor[to] == 1) {
            int extra_vertex = vertex;
            int extra_parent = parent;
            answer_arr.push_back(extra_vertex + 1);
            while (extra_vertex != to) {
                extra_vertex = extra_parent;
                answer_arr.push_back(extra_vertex + 1);
                extra_parent = parents[extra_parent];
            }
            reverse(answer_arr.begin(), answer_arr.end());
            ans = true;
            return;
        }
        else if (collor[to] == 2) {
            continue;
        }
        else {
            dfs(to, vertex, timer, arr, parents, tin, tout, collor, ans, answer_arr);
        }
    }
    tout[vertex] = timer++;
    collor[vertex] = 2;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    vvi edges(n);
    for (int i = 0; i < m; ++i) {
        int vertex1, vertex2;
        std::cin >> vertex1 >> vertex2;
        edges[vertex1 - 1].push_back(vertex2 - 1);
    }
    int timer = 0;
    vi tin(n);
    vi tout(n);
    vi color(n);
    vi parents(n);
    vi answer_arr;
    bool ans = false;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i, -1, timer, edges, parents, tin, tout, color, ans, answer_arr);
            if (ans == true) {
                std::cout << "YES" << '\n';
                print(answer_arr);
                return 0;
            }
        }
    }
    std::cout << "NO";

}
