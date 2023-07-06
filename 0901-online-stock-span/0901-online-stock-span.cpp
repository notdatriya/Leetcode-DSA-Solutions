class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
    }
    
    int next(int price) {
//         int count=0;
//         int maxcount=0;
//         arr.push_back(price);
//         for(int i=arr.size()-1;i>=0;i--){
//             if(arr[i]>price){
//                 count=0;
//                 break;
//             }
//          else{
//              count++;
//              maxcount=max(maxcount,count);
//          }
//         }
         
//         return maxcount;
        
        
        //m-2
        int count=1;
        while(!st.empty() && st.top().first<=price){
            count+=st.top().second;
            st.pop();
        }
        st.push({price,count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */