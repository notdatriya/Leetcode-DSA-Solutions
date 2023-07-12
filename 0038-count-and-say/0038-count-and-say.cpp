class Solution {
public:
    
string solve(string num){
        char currnum= num[0];
    int freq=1;
    string ans;
    for(int i=1;i<num.length();i++){
        if(num[i]==currnum){
            freq++;
        }
        else{
            char count=(char)('0'+freq);
            ans.push_back(count);
            ans.push_back(currnum);
            currnum=num[i];
            freq=1;
        }
    }
    
    char count=(char)('0'+freq);
            ans.push_back(count);
            ans.push_back(currnum);
    
    return ans;
    }
    
    
    string countAndSay(int n) {
        string num="1";
        for(int i=0;i<n-1;i++){
            num=solve(num);
        }
        return num;
    }
};