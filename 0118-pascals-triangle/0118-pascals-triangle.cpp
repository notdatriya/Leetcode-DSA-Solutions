class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // every element is r-1 C c-1 in pascal triangle
        //for very row and every alement can be found using this - brute forc solution
        //this is n^3 solution
        // for n^2 optimized similar to below written, 
        //for every row
        //for(int col=1,col<row;i++){
        //ans=ans*(row-col);
        //ans=ans/col
        //and push this row in final ans array
    
        vector<vector<int>>result(numRows);
        for(int i=0;i<numRows;i++){
            result[i].resize(i+1);
            result[i][0]=1;
            result[i][i]=1;
            for(int j=1;j<i;j++){
                result[i][j]=result[i-1][j-1]+result[i-1][j];
            }
        }
        return result;
    }
};