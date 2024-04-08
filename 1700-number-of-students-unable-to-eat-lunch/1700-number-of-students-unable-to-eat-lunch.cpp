class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
      queue<int> q;
                stack<int>st;

        int n=students.size();
        for (int i=0;i<n;i++) {
            
            st.push(sandwiches[n-i-1]);
            q.push(students[i]);
        }
        
        
        int lastserved=0;
        
        while(!q.empty() && lastserved<q.size()){
            int stu=q.front();
            int sand=st.top();
            if(stu==sand){
                st.pop();
                q.pop();
                lastserved=0;
                
            }
            else{
                q.push(stu);
                q.pop();
                lastserved++;
            }
        }
        
        return q.size();
    }
};