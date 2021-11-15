#include <string>
#include <iostream>
#include <vector>

struct Binary_heap{
    void insert(long long num){
        heap.push_back({num, number});
	heap_size++;
	number++;
	pointer.push_back(heap_size);
	siftup(heap_size);
    }

    long long getMin(){
	number++;
	pointer.push_back(0);
        return heap[1].first;
    }

    void extractMin(){
	exchange(1,heap_size);
	heap_size--;
	heap.resize(heap_size + 1);
	number++;
	pointer.push_back(0);
        siftdown(1);
    }

    void decreaseKey(long num, long long del){
        heap[pointer[num]].first -= del;
	siftup(pointer[num]);
	number++;
	pointer.push_back(0);
    }

private:
    std::vector<std::pair<long long, long long> > heap = {{0,0}};
    long long heap_size = 0;
    std::vector<long long> pointer = {0};
    long long number = 1;

    void siftup(long long poz){
    	while(poz != 1 && heap[poz].first < heap[poz/2].first){
	    exchange(pointer[heap[poz].second], pointer[heap[poz/2].second]);
	    poz /= 2;
	}	
    } 
    
    void siftdown(long long poz){
        while(poz * 2 <= heap_size){
	    long long poz2 = poz * 2;
	    if(poz2 + 1 <= heap_size && heap[poz2].first > heap[poz2 + 1].first){
	        poz2 += 1;
	    }
	    if(heap[poz].first > heap[poz2].first){
	        exchange(pointer[heap[poz].second], pointer[heap[poz2].second]);
		poz = poz2;
	    }
	    else{
	        return;
	    }
	}

    }

        void exchange(long num1, long num2){
        std::swap(heap[num1], heap[num2]);
	std::swap(pointer[heap[num1].second], pointer[heap[num2].second]);

    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    Binary_heap myheap;
    long long n;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
	std::string request;
        std::cin >> request;
	if(request == "insert"){
	    long long num;
	    std::cin >> num;
 	    myheap.insert(num);
	}
	else if(request == "getMin"){
	    std::cout << myheap.getMin() << '\n';
	}
	else if(request == "extractMin"){
	    myheap.extractMin();
	}
	else if(request == "decreaseKey"){
	    long long num, del;
	    std::cin >> num >> del;
	    myheap.decreaseKey(num, del);
	}
   }
}
