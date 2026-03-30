class MinStack {
private:
    // 使用 long long 避免溢位
    std::vector<long long> st; 
    long long min;
    
public:
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            st.push_back(0);
            min = val;
        } else {
            // 存入差值：val - min
            st.push_back((long long)val - min);
            if (val < min) {
                min = val; // 更新最小值
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long tmp = st.back();
        st.pop_back();
        
        // 如果 tmp < 0，說明 pop 掉的是當時的最小值，要還原先前的 min
        if (tmp < 0) {
            min = min - tmp;
        }    
    }
    
    int top() {
        long long tmp = st.back();
        if (tmp >= 0) {
            return (int)(tmp + min);
        } else {
            // 如果 tmp < 0，說明當前的 min 就是當初 push 進來的 val
            return (int)min;
        }
    }
    
    int getMin() {
        return (int)min;
    }
};