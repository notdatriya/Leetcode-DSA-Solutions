class Solution {
public:
    
    int solve(int i,string &s,int sign,long ans){
        if(sign*ans>=INT_MAX)return INT_MAX;
        if(sign*ans<=INT_MIN)return INT_MIN;
        // cout<<"hello";
        if(s[i]==' ' || !isdigit(s[i]))return sign*ans;
        return solve(i+1,s,sign,ans*10+(s[i]-'0'));
        
    }
    int myAtoi(string s) {
//         if(s.length()==0)return 0;
//         long ans=0;
//         char t;
        
//         int i=0;
//         while(i<s.size() && s[i]==' ' ){
//             i++;
//         }
//         s=s.substr(i);
//         int sign=1;
//         if(s[0]=='-')sign=-1;
//         i=(s[0]=='+' || s[0]=='-')?1:0;
        
//        while(i<s.length()){
//            if(s[i]==' '|| !isdigit(s[i])){
//                break;
//            }
           
//                ans=ans*10+s[i]-'0';
           
//            if(sign==-1 && -1*ans<INT_MIN) return INT_MIN;
//            if(sign==1 &&  ans>INT_MAX) return INT_MAX;
//            i++;
//        }
        
     
//         return sign*ans;
        
        
      //recursive
        if(s.size()==0)return 0;
        long ans=0;
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        // cout<<i<<" ";
        int sign=1;
         int flag=0;
        if(s[i]=='-'){
            sign=-1;
            i++;
            flag++;
        }
        if(s[i]=='+'){
            sign=1;
            i++;
            flag++;
    
        }
        cout<<i<<" ";
         if(flag>1)return 0;
        
        return solve(i,s,sign,ans);
    }
};