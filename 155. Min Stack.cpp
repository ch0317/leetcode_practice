class MinStack {
stack<pair<int,int>> min_st;
    
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        int min_val = 0;
        if(min_st.empty()){
            min_val = x;
            min_st.push(pair<int,int>(x,min_val));
        }
        else{
            min_val = std::min(min_st.top().second, x);
            min_st.push(pair<int,int>(x,min_val));
        }
    }
    
    void pop() {
        min_st.pop();
    }
    
    int top() {
        return min_st.top().first;
    }
    
    int getMin() {
        return min_st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */