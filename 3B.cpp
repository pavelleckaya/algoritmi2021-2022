#include <iostream>
#include <vector>
using std::vector;

int f(int i){
	return i & (i + 1);
}

int g(int i){
	return i | (i + 1);
}

int getSum(int left,int right, vector<int>& array_fenvik, vector<int>& array){
	int ans1 = 0;
	if(left == right){
		return array[left];
	}
	for(int i = right; i >= 0; i = f(i) - 1){
		ans1 += array_fenvik[i];
	}
	if(left == 0){
		return ans1;
	}
	int ans2 = 0;
	for(int i = left - 1; i >= 0; i = f(i) - 1){
		ans2 += array_fenvik[i];
	}
	if(left % 2 == 0){
		return ans1 - ans2;
	}
	else{
		return ans2 - ans1;
	}
}

void update(int pos, int del, vector<int>& array_fenvik){
	for(int i = pos; i < array_fenvik.size(); i = g(i)){
		if(pos % 2 == 0){
			array_fenvik[i] += del;
		}
		else{
			array_fenvik[i] -= del;
		}
	}
}

int main(){
	int n;
	std::cin >> n;
	vector<int> array(n);
	vector<int> array_fenvik(n);
	for(int i = 0; i < n; ++i){
		std::cin >> array[i];
		update(i, array[i], array_fenvik);
	}
	int m;
	std::cin >> m;
	for(int i = 0; i < m; ++i){
		int flag;
		int x, y;
		std::cin >> flag >> x >> y;
		if(flag == 0){
			int del = y - array[--x];
			array[x] = y;
			update(x, del, array_fenvik);	
		}
		else{
			std::cout << getSum(--x, --y, array_fenvik, array) << '\n';
		}
	}
}
