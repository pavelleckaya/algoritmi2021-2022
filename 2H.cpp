#include <iostream>
#include <cmath>
#include <vector>

int element_LSD(std::vector<long long>& LSD, int j, int i){
	long long num = LSD[i];
	for(int z = 0; z < j; ++z){
		num /= 256;
	}
	return num % 256;

}

void LSD_sort(std::vector<long long>& LSD, int n){ 
	int def = 256;
	int size = 8;
    for(int j = 0; j < size; ++j){
		std::vector<long long> ans(n);
        std::vector<int> cnt(def);
        for(int i = 0; i < n; ++i){
      		int k = element_LSD(LSD, j, i);
			cnt[k]++;			
		}
        for(int i = 1; i < def; ++i){
            cnt[i] += cnt[i-1];
        }
    
        for(int i = n - 1; i >= 0; --i){
	    	int k = element_LSD(LSD, j, i);
			ans[--cnt[k]] = LSD[i];
		}
		LSD = ans;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<long long> LSD;
	for(int i = 0; i < n; ++i){
		long long num;
		std::cin >> num;
		LSD.push_back(num);
	}
	LSD_sort(LSD, n);
	for(int j = 0; j < n; ++j){
		std::cout << LSD[j] << ' ';
	}
}
