class MyStack {
private:
    std::queue<int> q1; 
    std::queue<int> q2; // opposite

public:
    MyStack() {
        
    }
    
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
            // we have to save the size before going to loop
            // becuase if we use (int i = 0; i < q1.size(); i++)
            // q1.size() is changing through the loop
            int size = q1.size();
            for (int i = 0; i < size; i++) {
                int tmp = q1.front();
                q2.push(tmp);
                q1.pop();
            }
            q1 = q2;
            std::queue<int> empty;
            std::swap(q2, empty);
        }
    }
    
    int pop() {
        int tmp = q1.front();
        q1.pop();
        return tmp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */