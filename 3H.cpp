#include <iostream>
#include <vector>

using std::vector;

int degree(int n){
	int k = 0;
	while((1 << k) <= n){
		k += 1;
	}
	return k - 1;
}

std::pair<int, int> k1_k2_stat(int k1, int k2, int k3, int k4, vector<int>& n){
	if(k1 == k2){
		if(n[k3] < n[k4]){
			k2 = k3;
		}
		else{
			k2 = k4;
		}
	}
	else{
		if(n[k1] < n[k2]){
			if(n[k3] < n[k2]){
				k2 = k3;
			}
		}
		else{
			if(n[k4] < n[k1]){
				k1 = k2;
				k2 = k4;
			}
			else{
				k3 = k1;
				k1 = k2;
				k2 = k3;
			}
		}
	}
	return {k1, k2};
}

int main(){
	int n, m;
	std::cin >> n >> m;
	int k = degree(n);
    vector<vector<std::pair<int, int> > > all(k + 1);
	vector<int> nul(n);
	for(int i = 0; i < n; ++i){
		int num;
		std::cin >> num;
		nul[i] = num;
	}
	for(int i = 0; i < n - 1; ++i){
		int k1 = i, k2 = i + 1;
		if(nul[k1] > nul[k2]){
			k1 = i + 1;
			k2 = i;
		}
		all[1].push_back({k1, k2});
	}
	for(int i = 2; i <= k; ++i){
		for(int j = 0; j < n - 1; ++j){
			int p = j + (1 << (i - 1));
			if(p + (1 << (i - 1)) <= n){
				int k1 = all[i - 1][j].first, k2 = all[i - 1][p].first, k3 = all[i - 1][j].second, k4 = all[i - 1][p].second;
				all[i].push_back(k1_k2_stat(k1, k2, k3, k4, nul));
			}
		}
	}
	for(int i = 0; i < m; ++i){
		int x, y;
		std::cin >> x >> y;
		int s = degree(y - x + 1);
		int k1 = all[s][x - 1].first, k2 = all[s][y - (1 << s)].first, k3 = all[s][x - 1].second, k4 = all[s][y - (1 << s)].second;
		std::pair<int, int> l = k1_k2_stat(k1, k2, k3, k4, nul);
		std::cout << nul[l.second] << '\n';
	}
}
