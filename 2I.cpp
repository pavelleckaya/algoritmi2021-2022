#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> kth(std::vector<int>& A){
    std::vector<int> midl;
    std::vector<int> five_el(5);
    int remains = A.size() / 5, the_whole_part = (A.size() % 5) ;
    for(int i = 0; i < remains; ++i){
        for(int j = 0; j < 5; ++j){
            five_el[j] = A[5 * i + j];
    }
        sort(five_el.begin(), five_el.end());
        midl.push_back(five_el[2]);
    }
    five_el.resize(the_whole_part);
    for(int j = 0; j < the_whole_part; ++j){
        five_el[j] = A[A.size() - the_whole_part + j];
    }
    sort(five_el.begin(), five_el.end());
    midl.push_back(five_el[five_el.size() / 2]);
    return midl;
}


void Partition(int mid, std::vector<int>& A, std::vector<int>& mid_less, std::vector<int>& mid_equally, std::vector<int>& mid_more){
     for(int i = 0; i < A.size(); ++i){
        if(A[i] < mid){
            mid_less.push_back(A[i]);
        }
        else if(A[i] == mid){
            mid_equally.push_back(A[i]);
        }
        else{
            mid_more.push_back(A[i]);
        }
    }
}

int QuickSelect(std::vector<int>& A,int k){	
    if(A.size() == 1){
        return A[0];
    }
    std::vector<int> midl = kth(A);
    int mid = QuickSelect(midl, midl.size() / 2);;
    std::vector<int> mid_less, mid_equally, mid_more;
    Partition(mid, A, mid_less, mid_equally, mid_more);
    if(k < mid_less.size()){
        return QuickSelect(mid_less, k);
    }
    else if(k < mid_less.size() + mid_equally.size()){
        return mid_equally[0];
    }
    else{
        return QuickSelect(mid_more, k - mid_less.size() - mid_equally.size());
    }
}
 
std::vector<int> QuickSort(std::vector<int> A){
    if(A.size() == 1){
        return A;
    }
    std::vector<int> midl = kth(A);
    int mid = QuickSelect(midl, midl.size() / 2);
    std::vector<int> All;
    std::vector<int> mid_less, mid_equally, mid_more;
    Partition(mid, A, mid_less, mid_equally, mid_more);
    mid_less = QuickSort(mid_less);
    int l1 = mid_less.size();
    for(int i = 0; i < l1; ++i){
        A[i] = mid_less[i];
    }
    int l2 = mid_equally.size();
    for(int i = 0; i < l2; ++l2 ){
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
