//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        
        //brute force solution is to just use two loops, findall the subarrays and find the max
        // better soln is to use hashmaps, we will iterate for every element and check the
        //sum upto that array, if the sum is equal to k, len will be index i and if its greater than
        //maxlength, we will update maxlength, if its not equal to k, then we will check , if their
        // exists a sum of this sum -k in the set, so that the sum of the rem array becomes k, thrn
        //we will find the length by i- mpp[rem], and update the maxlength, and store the sum and its
        //index to mpp if that sum does not exist in past, as it will guarantee max length subarray
        
        //here k=0;
        // if the array does not contain negatives, then a more optimal approach can exist
        map<long long,int>mpp;
        long long sum=0;
        int mlength=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                mlength=max(mlength,i+1);
            }
            long long rem=sum-0;
            if(mpp.find(rem)!=mpp.end()){
               int length=i-mpp[rem];
               mlength=max(mlength,length);
            }
            if(mpp.find(sum)==mpp.end())
            mpp[sum]=i;
        }
        return mlength;
    }
    
    
    //Optimal approach if the array contains only positives and zeroes
    
    // int left=0; int right=0;
    // long long sum=0;
    // int maxlen=0;
    // while(right<n){
    //     while(left<=right && sum>k){
    //         sum-=A[left];
    //         left++;
    //     }
    //     if(sum==k){
    //         maxlen=max(maxlen,right-left+1);
    //     }
    //     right++;
    //     if(right<n)sum+=A[right];
    // }

};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends