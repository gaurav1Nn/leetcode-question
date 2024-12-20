class MinStack {
public:

    stack<int> st;
    stack<int> helper;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(helper.size()==0 || val<helper.top()){
            helper.push(val);
            
        }
        else helper.push(helper.top());
    }
    
    void pop() {
        st.pop();
        helper.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return helper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */