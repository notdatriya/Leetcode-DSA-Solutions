class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        
//         int i=0;
//         int n=fruits.size();
//         int maxcount=0;
//         map<int,int>basket;
        
//         for(int j=0;j<n;j++){
            
//         basket[fruits[j]]++;
            
//             while(basket.size()>2){
//                 int count=basket[fruits[i]];
//                 if(count==1){
//                     basket.erase(fruits[i]);
//                 }
//                 else{
//                     basket[fruits[i]]--;
//                 }
//                 i++;
//             }
            
//             maxcount=max(maxcount,j-i+1);
//         }
//         return maxcount;
        
        
        
        
//         int l=0;
//         int r=0;
//         int n=fruits.size();
//         map<int,int>mpp;
//         int maxi=0;
//         while(r<n){
//             mpp[fruits[r]]++;
            
//             if(mpp.size()>2){
//                 while(mpp.size()>2){
//                     mpp[fruits[l]]--;
//                     if(mpp[fruits[l]]==0){
//                         mpp.erase(fruits[l]);
//                     }
//                     l++;
//                 }
//             }
            
//             if(mpp.size()<=2){
//                 maxi=max(maxi,r-l+1);
//             }
//             r++;
//         }
        
//         return maxi;
        
        
        
        
        
        
        
        
        
        
        //m-2 more optimal
        
         int l=0;
        int r=0;
        int n=fruits.size();
        map<int,int>mpp;
        int maxi=0;
        while(r<n){
            mpp[fruits[r]]++;
            
            if(mpp.size()>2){
                // while(mpp.size()>2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0){
                        mpp.erase(fruits[l]);
                    }
                    l++;
                // }
            }
            
            if(mpp.size()<=2){
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        
        return maxi;
        
        
    }
};