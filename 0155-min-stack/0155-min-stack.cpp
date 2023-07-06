class MinStack {
public:
    stack<pair<int,int>>s1;

    MinStack() {
    }
    
    void push(int val) {
        if(!s1.empty()){
       s1.push({val,min(s1.top().second,val)});
        }
        else{
            s1.push({val,val});
        }
//         while(!s2.empty() && s2.top()>=s1.top()){
//             s2.pop();
//         }
//         if(s2.empty()){
//              s2.push(s1.top()); 
//         }
        
    }
    
    void pop() {
        
           
        if(!s1.empty()){
      //    int c=s1.top();
      // if(!s2.empty() && s2.top()==c){
      //       s2.pop();
      //   }
            s1.pop();
            return;
           
        }
       
        
    }
    
    int top() {
        if(!s1.empty()){
        return s1.top().first;
        }
        return NULL;
    }
    
    int getMin() {
        return s1.top().second;
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