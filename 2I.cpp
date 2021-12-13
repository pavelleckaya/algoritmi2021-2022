#include <iostream>
#include <vector>
#include <algorithm>

int med(std::vector<int>& midl, int size){
	for(int j = 0; j < size - 1; ++j){
		for(int i = j + 1; i < size; ++i){
			if(midl[j] > midl[i]){
				std::swap(midl[i], midl[j]);
			}
		}
	}
	return midl[size/2];
}

int kth(std::vector<int>& A,int left, int right){
    if(right - left == 0){
		return A[0];
	}
	int size = right - left + 1;
	std::vector<int> midl;
    std::vector<int> five_el(5);
    int remains = size / 5, the_whole_part = (size % 5) ;
    for(int i = 0; i < remains; ++i){
        for(int j = 0; j < 5; ++j){
            five_el[j] = A[left + 5 * i + j];
    	}
        midl.push_back(med(five_el, 5));
    }
    five_el.resize(the_whole_part);
    for(int j = 0; j < the_whole_part; ++j){
        five_el[j] = A[right + 1 - the_whole_part + j];
    }
	midl.push_back(med(five_el, the_whole_part));
    return kth(midl, 0, midl.size() - 1);
}

void Partition(int mid, std::vector<int>& A,int& equall, int& left, int& right){
	if(left - right == 1){
		return;
	}
    int left1 = left; 
	while(left != right){
         if(A[left] > mid){
		 	std::swap(A[left], A[right]);
			right--;
		 }
		 else{
			left++;
		 }
    }
	if(A[right] > mid){
		left--;
	}
	else{
		right++;
	}
	while(left != left1){
		if(A[left1] == mid){
			std::swap(A[left], A[left1]);
			left--;
			equall++;
		}
		else{
			left1++;
		}
	}
	if(A[left] == mid){
		left--;
		equall++;
	}
}

int QuickSelect(std::vector<int>& A,int k){
    if(A.size() == 1){
    	return A[0];
    }
    int left = 0, right = A.size() - 1;
	while(left != right){
		int mid = kth(A, left, right);
		int left1 = left;
		int right1 = right;
		int equall = 0;
		Partition(mid, A, equall, left, right);
		if(left + 1 >= k){
			right = left;
			left = left1;
		}
		else if(left + equall + 1 >= k){
			return A[left + equall];
		}
		else{
			left = right;
			right = right1;
		}
	}
	return A[left];
}


std::vector<int> QuickSort(std::vector<int>& A){
    if(A.size() == 1){
        return A;
    }
	if(A.size() == 2){
		if(A[0] > A[1]){
			std::swap(A[0], A[1]);
		}
		return A;
	}
    int mid = QuickSelect(A, (A.size() + 1)/ 2);
    int equall = 0;
	int left = 0; 
	int right = A.size() - 1;
    Partition(mid, A, equall, left, right);
    int j = 0;
	std::vector<int> mid_less(left + 1), mid_equally(equall), mid_more(A.size() - right);
	while(j != left + 1){
		mid_less[j] = A[j];
		j++;
	}
	while(j != left + 1 + equall){
		mid_equally[j - left - 1] = A[j];
		j++;
	}
	while(j != A.size()){
		mid_more[j - right] = A[j];
		j++;
	}
	mid_less = QuickSort(mid_less);
    int l1 = mid_less.size();
    for(int i = 0; i < l1; ++i){
        A[i] = mid_less[i];
    }
    int l2 = mid_equally.size();
    for(int i = 0; i < l2; ++i ){
        A[i + l1] = mid_equally[i];
    }
    mid_more = QuickSort(mid_more);
    for(int i = 0; i < mid_more.size(); ++i){
        A[i + l1 + l2] = mid_more[i];
    }
    return A;
}
 
int main(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);
        int n;
        std::cin >> n;
        std::vector <int> quick(n);
        for(int i = 0; i < n; ++i){
            std::cin >> quick[i];
		}
		std::vector<int> All = QuickSort(quick);
		for(int i = 0; i < All.size(); ++i){
	    std::cout << All[i] << ' ';
}
 
}
