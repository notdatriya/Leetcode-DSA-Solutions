class StockSpanner {
public:
    vector<int>arr;
    StockSpanner() {
        arr={};
    }
    
    int next(int price) {
           // if(arr.empty()){
           //      arr.push_back(price);
           //      return 1;
           //  }
        int count=0;
        int maxcount=0;
        arr.push_back(price);
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]>price){
                count=0;
                break;
            }
         else{
             count++;
             maxcount=max(maxcount,count);
         }
        }
         
        return maxcount;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */