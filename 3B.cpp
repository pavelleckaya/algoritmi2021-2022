#include <iostream>
#include <vector>
using std::vector;

class Fenvik{
private:
	vector<int> array_fenvik;
public:
	Fenvik(const vector<int>&);

	~Fenvik(){}

	int getSum(int, int, vector<int>&);

	void update(int, int);
};

int f(int i){
	return i & (i + 1);
}

int g(int i){
	return i | (i + 1);
}

Fenvik::Fenvik(const vector<int>& array): array_fenvik(array.size()){
	vector<int> pref(array.size());
	pref[0] = array[0];
	for(int i = 1; i < array.size(); ++i){
		i%2==0 ? pref[i] = pref[i - 1] + array[i] : pref[i] = pref[i - 1] - array[i];
	}
	for(int i = 0; i < array.size(); ++i){
		if(f(i) == 0){
			array_fenvik[i] = pref[i];
		}
		else{
			array_fenvik[i] = pref[i] - pref[f(i) - 1];
		}
	}
}

int Fenvik::getSum(int left,int right, vector<int>& array){
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

void Fenvik::update(int pos, int del){
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
	for(int i = 0; i < n; ++i){
		std::cin >> array[i];
	}
	Fenvik fenvik(array);
	int m;
	std::cin >> m;
	for(int i = 0; i < m; ++i){
		int flag;
		int x, y;
		std::cin >> flag >> x >> y;
		if(flag == 0){
			int del = y - array[--x];
			array[x] = y;
			fenvik.update(x, del);	
		}
		else{
			std::cout << fenvik.getSum(--x, --y, array) << '\n';
		}
	}
}
