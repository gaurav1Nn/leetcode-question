class MyQueue {
public:
    stack<int> helper;
    stack<int> st;

    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() { // remove at bottom o(n)
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        helper.pop();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    int peek() {  // front what element is presetnt at front
         while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    bool empty() {
        if(st.size()==0) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */