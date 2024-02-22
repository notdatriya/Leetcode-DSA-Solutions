class Solution {
public:
    
    bool dotrust(int p1,int p2,vector<vector<int>>&trust){
        for(int i=0;i<trust.size();i++){
            if(trust[i][0]==p1 && trust[i][1]==p2){
                return true;
            }
        }
        return false;
        
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        
        
        stack<int>st;
        
        for(int i=1;i<=n;i++){
            st.push(i);
        }
        
        while(st.size()>=2){
            int p1=st.top();
            st.pop();
            int p2=st.top();
            st.pop();
            
            if(dotrust(p1,p2,trust)){
                st.push(p2);
            }
            else{
                st.push(p1);
            }
        }
        
        int person=st.top();
        st.pop();
        
    for(int i=1;i<=n;i++){
        if((i!=person && dotrust(person,i,trust)) || (i!=person && !dotrust(i,person,trust))){
            return -1;
        }
    }
        return person;
    }
};