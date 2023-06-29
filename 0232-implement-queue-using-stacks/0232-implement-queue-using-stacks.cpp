class MyQueue {
public:
    // stack<int>s1;
    // stack<int>s2;
    
    //m-3 optimized- using this, the time complexity of almost all operations will be O(1)
    //that is called amortised O(1)
    
    stack<int>input;
        stack<int>output;
    MyQueue() {
        
    }
    
    void push(int x) {
        // s1.push(x);
        
        //method-2
        //  while(!s1.empty()){
        //     s2.push(s1.top());
        //     s1.pop();
        //  }
        // s1.push(x);
        //      while(!s2.empty()){
        //     s1.push(s2.top());
        //     s2.pop();
        // }
             
        
        //m-3 optimized
        input.push(x);
        
    }
    
    int pop() {
        // while(!s1.empty()){
        //     s2.push(s1.top());
        //     s1.pop();
        // }
        // int ans=s2.top();
        // s2.pop();
        //    while(!s2.empty()){
        //     s1.push(s2.top());
        //     s2.pop();
        // }
        // return ans;
        
        //method-2
        
        // int ans=s1.top();
        // s1.pop();
        // return ans;
        
        //m-3 optimized
        if(!output.empty()){
          int ans=output.top();
            output.pop();
            return ans;
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int ans=output.top();
            output.pop();
            return ans;
        }
        
    }
    
    int peek() {
        //  while(!s1.empty()){
        //     s2.push(s1.top());
        //     s1.pop();
        // }
        // int ans=s2.top();
        //    while(!s2.empty()){
        //     s1.push(s2.top());
        //     s2.pop();
        // }
        // return ans;
        
        //m-2
        
        // return s1.top();
        
        
        //m-3 optimized
         if(!output.empty()){
          return output.top();
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
        
    }
    
    bool empty() {
        if(input.empty() && output.empty()){
            return true;
        }
        return false;
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