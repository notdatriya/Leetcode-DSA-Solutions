class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // brute force agar sirf 1 and 0 hote ho 0 ki jagah -1 karte and pjir -1 ko 0 end me
        //better soln me ek row or a column array usme if any element is zero mark both //zero,later iterate again if any one of row or column 0 then mark 0
        //for constant time complexity - 1st row and column will be used for marking ,for
        //first column, col0 is used 
        //pehle inn dono rows k alawa iterate karenge then row and last me pehla column coz 
        //col0 change ho skta hai
        
        int row=matrix.size();
        int col=matrix[0].size();
        int col0=1;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                   matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }
    
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]!=0){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
                }
            }
        }
        
        if(matrix[0][0]==0){
            for(int i=0;i<col;i++){
                matrix[0][i]=0;
            }
        }
        
        if(col0==0){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
        
        
        
        
    }      
};