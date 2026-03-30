class MinStack {
private:
    std::vector<long long> st;
    long long min;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.size() == 0) {
            st.push_back(0);
            min = val;
        } else {
            st.push_back(val - min);
            if (val < min) {
                min = val;
            }
        }
    }
    
    void pop() {
        auto tmp = st.back();
        st.pop_back();
        if (tmp < 0) {
            min -= tmp;
        }    
    }
    
    int top() {
        auto tmp = st.back();
        if (tmp > 0) {
            return tmp + min;
        } else {
            return min;
        }
    }
    
    int getMin() {
        return min;
    }
};
