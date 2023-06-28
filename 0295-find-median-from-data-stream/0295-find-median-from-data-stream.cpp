class MedianFinder {
public:
    priority_queue<int>maxleft;
       priority_queue<int,vector<int>, greater<int>>minright;
    
    MedianFinder() {
       
    }
    
    void addNum(int num) {
       if(maxleft.empty()|| num<maxleft.top()){
            maxleft.push(num);
        }
        else{
            minright.push(num);
        }
        
        //either both will have equal elements or left will have one more in case of odd numbers
        if(maxleft.size()>minright.size()+1){
            int temp=maxleft.top();
            maxleft.pop();
            minright.push(temp);
            
        }
        if(minright.size()>maxleft.size()){
            int temp=minright.top();
             minright.pop();
            maxleft.push(temp);
           
        }
    }
    
    double findMedian() {
      if(maxleft.size()==minright.size()){
          return double(double(maxleft.top()+minright.top())/2);
      }
        else{
            return maxleft.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */