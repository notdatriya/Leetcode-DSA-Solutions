class Solution {
public:
    int romanToInt(string s) {
        // 'I','V','X','L','C','D','M'};
        map<char,int>mpp;
        mpp['I']=1;
        mpp['V']=5;
        mpp['X']=10;
        mpp['L']=50;
        mpp['C']=100;
        mpp['D']=500;
        mpp['M']=1000;


        // int value[]={}
        int ans=mpp[s[s.length()-1]];
        for(int i=s.length()-2;i>=0;i--){
            if(mpp[s[i]]<mpp[s[i+1]]){
                ans=ans-mpp[s[i]];
            }
            else{
                ans+=mpp[s[i]];
            }
        }
        return ans;
    }
};