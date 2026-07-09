class MyStack {
public:
     queue<int> st;
    
    MyStack() {
        
         
    }
    
    void push(int x) {
       
        st.push(x);
        int n =st.size();
        for ( int i =0 ; i <n-1 ;i++ ){
            
            int a = st.front();
            st.pop();
            st.push(a);

        }
    }
    
    int pop() {
        int a = st.front();
        st.pop();
        return a ;
    }
    
    int top() {
        return st.front();
    }
    
    bool empty() {
        return st.empty();
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