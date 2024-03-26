class Solution {
public:
    
    int findmaxarea(vector<int>&heights){
         stack<int>st;  //we will store index
        int n=heights.size();
        int maxarea=0;
        
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int h=heights[st.top()];
                st.pop();
                int width;
                if(st.empty())width=i;
                else{
                    width=i-st.top()-1;
                }
                
                maxarea=max(maxarea,width*h);
            }
            st.push(i);
        }
        return maxarea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
            }
    
            for(auto it:height){
                cout<<it<<" ";
            }
            int area=findmaxarea(height);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};