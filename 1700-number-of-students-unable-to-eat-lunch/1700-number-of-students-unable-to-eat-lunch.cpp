class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
//       queue<int> q;
//                 stack<int>st;

//         int n=students.size();
//         for (int i=0;i<n;i++) {
            
//             st.push(sandwiches[n-i-1]);
//             q.push(students[i]);
//         }
        
        
//         int lastserved=0;
        
//         while(!q.empty() && lastserved<q.size()){
//             int stu=q.front();
//             int sand=st.top();
//             if(stu==sand){
//                 st.pop();
//                 q.pop();
//                 lastserved=0;
                
//             }
//             else{
//                 q.push(stu);
//                 q.pop();
//                 lastserved++;
//             }
//         }
        
//         return q.size();
        
        
        
        
        //m-2 countingggg
        
        
        int ccount=0;
        int scount=0;
        
        for(int it:students){
            if(it==0)ccount++;
            else scount++;
        }
        
        
        for(int s:sandwiches){
            if(s==0 && ccount==0)return scount;
            if(s==1 && scount==0)return ccount;
            
            if(s==0)ccount--;
            else{
                scount--;
            }
        }
        return 0;
    }
};