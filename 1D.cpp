    #include <iostream>
    #include <queue>
    #include <stack>
    #include <deque>
     
    class Queuegob {
    	std::deque<int> queue1, queue2;
    public:
    	void Push_priviliged_gob(int numgob) {
    		if (queue1.size() == queue2.size()) {
    			queue1.push_back(numgob);
    		}
    		else {
    			queue2.push_front(numgob);
    		}
    	}
    	void Push__normal_gob(int numgob) {
    		queue2.push_back(numgob);
    		if (queue1.size() < queue2.size()) {
    			queue1.push_back(queue2.front());
    			queue2.pop_front();
    		}
    		
    	}
    	int Pop_gob() {
    		int gobil = queue1.front();
    		queue1.pop_front();
    		if (queue1.size() < queue2.size()) {
    			queue1.push_back(queue2.front());
    			queue2.pop_front();
    		}
			return gobil;
    	}
    };
     
    int main() {
    	std::ios::sync_with_stdio(false);
    	std::cin.tie(NULL);
    	Queuegob och;
    	int n;
    	char znach;
    	std::cin >> n;
    	for (int i = 0;i < n;++i) {
    		std::cin >> znach;
    		if (znach == '*') {
				int numgob;
				std::cin >> numgob;
    			och.Push_priviliged_gob(numgob);	
    		}
    		else if (znach == '-') {
    			int gobil = och.Pop_gob();
				std::cout << gobil << '\n';
    		}
    		else if (znach == '+') {
    			int numgob;
			std::cin >> numgob;
			och.Push__normal_gob(numgob);	
    		}
    	}
    }
