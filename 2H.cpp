#include <iostream>
#include <cmath>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    std::vector<std::vector<int> > LSD(n, std::vector<int> (8));
    for(int i = 0; i < n; ++i){
        long long num;
	std::cin >> num;
        for(int j = 0; j < 8; ++j){
	    LSD[i][j] = num % 256;
	    num /= 256; 
	}
    }
    for(int j = 0; j < 8; ++j){
	std::vector<std::vector<int> > ans(n, std::vector<int> (8));
        std::vector<int> cnt(256);
        for(int i = 0; i < n; ++i){
	    cnt[LSD[i][j]]++;
        } 
        for(int i = 1; i < 256; ++i){
            cnt[i] += cnt[i-1];
        }
    
        for(int i = n - 1; i >= 0; --i){
	    ans[--cnt[LSD[i][j]]] = LSD[i];
	}
	LSD = ans;
    }
    for(int j = 0; j < n; ++j){
	long long num = 0;
        for(int i = 0; i < 8; ++i){
	    num += (LSD[j][i] * (std::pow(256,i)));     
	}
	std::cout << num << ' ';
    }
}
