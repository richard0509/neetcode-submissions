class MinStack {
private:
    vector<int> st;
    vector<int> mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (mini.size() == 0) {
            mini.push_back(val);
        } else {
            int min = val < mini.back() ? val : mini.back();
            mini.push_back(min);
        }
        this->st.push_back(val);
    }
    
    void pop() {
        this->st.pop_back();
        this->mini.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return this->mini.back();
    }
};
