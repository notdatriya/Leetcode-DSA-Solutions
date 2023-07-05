class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
      int sm[n];
        int la[n];
        stack<int>st;
        
        for(int i=0;i<n;i++){
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    sm[i]=0;
                }
                else{
                    sm[i]=st.top()+1;
                }
                st.push(i);
            
        }
        
        while(!st.empty())st.pop();
        
         for(int i=n-1;i>=0;i--){
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    la[i]=n-1;
                }
                else{
                    la[i]=st.top()-1;
                }
                st.push(i);
             
        }
        int mul=0;
        int maxmul=0;
        for(int i=0;i<n;i++){
            mul=(la[i]-sm[i]+1)*heights[i];
            maxmul=max(mul,maxmul);
        }
        return maxmul;
        
        
        
        
      
      
    }
};