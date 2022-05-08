#include <iostream>
#include <vector>

int NOPP(int N, int M, std::vector<int>& array_N, std::vector<int>& array_M){
	std::vector<std::vector<int> > dp(N + 1, std::vector<int>(M + 1)); // дп на поиск нопа
	for (int i = 1; i < N + 1; ++i) {
		for (int j = 1; j < M + 1; ++j) {
			if (array_N[i - 1] == array_M[j - 1]) {
				dp[i][j] =  dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[N][M];

}

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> array_N(N); // первая последовательность для поиска нопа
	for (int i = 0; i < N; ++i) {
		std::cin >> array_N[i];
	}
	int M;
	std::cin >> M;
	std::vector<int> array_M(M); // вторая последовательность
	for (int i = 0; i < M; ++i) {
		std::cin >> array_M[i];
	}
	std::cout << NOPP(N, M, array_N, array_M);
}
