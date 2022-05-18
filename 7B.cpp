#include <iostream>
#include <vector>

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

void dfs(int vertex, int& timer, vvi& input, vi& tin, vi& tout) {
    tin[vertex] = timer++;
    for (int to : input[vertex]) {
        dfs(to, timer, input, tin, tout);
    }
    tout[vertex] = timer++;
}

int main()
{
    int n;
    std::cin >> n;
    vvi tree(n);
    int root = 1000000000;
    for (int i = 0; i < n; ++i) {
        int vertex;
        std::cin >> vertex;
        if (vertex == 0) {
            root = i;
        }
        else {
            tree[vertex - 1].push_back(i);
        }
    }
    int timer = 0;
    vi tin(n);
    vi tout(n);
    dfs(root, timer, tree, tin, tout);
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int vertex_parent, vertex_son;
        std::cin >> vertex_parent >> vertex_son;
        if (tin[vertex_son - 1] >= tin[vertex_parent - 1] && tout[vertex_son - 1] <= tout[vertex_parent - 1]) {
            std::cout << "1\n";
        }
        else {
            std::cout << "0\n";
        }
    }
}
