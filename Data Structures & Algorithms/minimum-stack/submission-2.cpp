class MinStack {
private:
    stack<pair<int,int>> st;
    int minVal = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(!st.empty())
        minVal = min(st.top().second, val);
        else
        minVal = val;
        st.push({val,minVal});
        
    }
    
    void pop() {
        st.pop();
        
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
        
    }
};
