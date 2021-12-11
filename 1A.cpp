    #include <iostream>
    #include <cstdio>
    #include <stack>
    #include <string>
    #include <cstring>
	#include <climits> 
    struct Node {
    	int num;
    	Node* link = nullptr;
    };
     
    class Stack {
    public:
	~Stack(){
	    Clear();
	}
    	void Push( int n ) {
    		Node* new_element = new Node();
    		new_element->num = n;
    		new_element->link = last_link;
    		last_link = new_element;
    		size += 1;
    	}
    	void Pop() {
    		if (size == 0) {
   				std::cout << "error" << '\n'; 		
			}
    		else {
				std::cout << last_link->num << '\n';
    			Node* link_delete = last_link;
    			last_link = last_link->link;
    			size -= 1;
    			delete link_delete;
    		}
    	}
    	void Back(){
    		if (size == 0) {
				std::cout << "error" << '\n';
    		}
    		else {
				std::cout << last_link->num << '\n';
    		}
    	}
    	int Size() {
    	    return size;
    	}
    	void Clear() {
    		while (size!=0) {
    			Node* link_delete = last_link;
    			last_link = last_link->link;
    			delete link_delete;
    			size -= 1;
    		}
    	}
    private:
    	int size = 0;
    	Node* last_link = new Node();
    };
     
    int main() {
    Stack stack;
	std::string str;
    	std::cin >> str;
    	while (str != "exit") {
    		if (str == "push") {
    			int n;
    			std::cin >> n;
    			stack.Push(n);
				std::cout << "ok" << '\n';
    		}
    		if (str == "pop") {
    			stack.Pop();
    		}
    		if (str == "back") {
    			stack.Back();
    		}
    		if (str == "size") {
    			int size = stack.Size();
				std::cout << size << '\n';
    		}
    		if (str == "clear") {
    			stack.Clear();
				std::cout << "ok" << '\n';
    		}
    		std::cin >> str;
    	}
    	std::cout << "bye";
    	return 0;
    }
