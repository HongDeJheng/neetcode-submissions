class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minVal = val;
        if (!st.empty()) {
            minVal = min(st.back().second, val);
        }

        st.push_back({val, minVal});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }

private:
    vector<pair<int, int>> st;
};
