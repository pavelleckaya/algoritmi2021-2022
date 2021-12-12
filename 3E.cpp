    #include <iostream>
    #include <vector>
    struct Node{
    	int left = -1;
    	int right = -1;
    	long long sum = 0;
    };
     
    class  DinamTree{
    private:
    	std::vector<Node> tre;
    public:
    	DinamTree() {
    		tre = std::vector<Node> (2);
    	}
    	void getsum(int, int, long long, int, long long&);
     
    	void push(int, int, int, int);
    };
     
     
    void DinamTree::push(int u, int tl, int tr, int i){
    	if(tl == tr){
    		tre[u].sum += i;
    		return;
    	}
    	int tm = (tl + tr) >> 1;
    	if(i <= tm){
    		if(tre[u].left == -1){
    			tre.push_back({-1, -1, 0});
				tre[u].left = tre.size() - 1;
				if(tre[u].right == -1){
					tre.push_back({-1, -1, 0});
					tre[u].right = tre.size() - 1;
				}

    		}
    		push(tre[u].left, tl, tm, i);
    	}
    	else{
    		if(tre[u].right == -1){
    			tre.push_back({-1, -1, 0});
				tre[u].right = tre.size() - 1;
    			if(tre[u].left == -1){
					tre.push_back({-1, -1, 0});
					tre[u].left = tre.size() - 1;
				}		
    		}
    		push(tre[u].right, tm + 1, tr, i);
    	}
    	tre[u].sum += i;
    }
     
    void DinamTree::getsum(int u, int tl, long long tr, int i, long long& ans){
    	if(tre[u].sum == 0){
			return;
		}
		if(tl == tr){
    		ans += tre[u].sum;
    		return;
    	}
    	int tm = (tl + tr) >> 1;
    	if(i <= tm){
    		getsum(tre[u].left, tl, tm, i, ans);
    	}
    	else{
    		ans += tre[tre[u].left].sum;
    		getsum(tre[u].right, tm + 1, tr, i, ans);
		}
    } 
     
    long long degree(long long n){
    	long long k = 1;
    	while(k < n){
    		k <<= 1;
    	}
    	return k;
    }
     
    int main(){
    	int n;
    	std::cin >> n;
    	DinamTree tree;
    	long long degree_tree = degree(1000000000);
    	for(int i = 0; i < n; ++i) {
    		char c;
    		int  k;
    		std::cin >> c >> k;
    		if(c == '?') {
    			if(k == 0){
    				std::cout << 0 << '\n';
    			}
    			else{
    				long long ans = 0;
    				tree.getsum(1, 1, degree_tree, k, ans);
    				std::cout << ans << '\n';
    			}
    		}
    		else{
    			tree.push(1, 1, degree_tree, k);
    		}
    	}
    }
