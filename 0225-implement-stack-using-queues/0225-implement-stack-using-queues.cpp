class MyStack {
public:
    //commented ,ethod is also right,but we can implement queue using only one queue
    queue<int>q1;
        // queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
      // q2.push(x);
      //   while(!q1.empty()){
      //       q2.push(q1.front());
      //       q1.pop();
      //   }
      //   queue<int>temp;
      //   temp=q1;
      //   q1=q2;
      //   q2=temp;
        
        q1.push(x);
        for(int i=0;i<q1.size()-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int ans=q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
         return q1.front();
    }
    
    bool empty() {
        if(q1.empty())return true;
        return false;
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