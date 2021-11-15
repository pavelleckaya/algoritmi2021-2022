    #include <iostream>
    #include <cstdio>
    #include <stack>
    #include <string>
    #include <cstring>
     
    struct Node {
    	int num;
    	Node* link = nullptr;
    };
     
    class Stack {
    public:
	~Stack(){
	    this->Clear();
	}
    	void Push( int n ) {
    		new_element = new Node();
    		new_element->num = n;
    		new_element->link = last_link;
    		last_link = new_element;
    		std::cout << "ok" << '\n';
    		size += 1;
    	}
    	void Pop() {
    		if (size == 0) {
    			std::cout << "error" << '\n';
    		}
    		else {
    			std::cout << last_link->num << '\n';
    			link_delete = last_link;
    			last_link = last_link->link;
    			size -= 1;
    			delete link_delete;
    		}
    	}
    	void Back() {
    		if (size == 0) {
    			std::cout << "error" << '\n';
    		}
    		else {
    			std::cout << last_link->num << '\n';
    		}
    	}
    	void Size() {
    		std::cout << size << '\n';
    	}
    	void Clear() {
    		while (size!=0) {
    			link_delete = last_link;
    			last_link = last_link->link;
    			delete link_delete;
    			size -= 1;
    		}
    	}
    private:
    	int size = 0;
    	Node* new_element = new Node();
    	Node* last_link = new_element->link;
    	Node* link_delete = nullptr;
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
    		}
    		if (str == "pop") {
    			stack.Pop();
    		}
    		if (str == "back") {
    			stack.Back();
    		}
    		if (str == "size") {
    			stack.Size();
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
