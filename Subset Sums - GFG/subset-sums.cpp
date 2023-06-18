// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

void summ(vector<int>&arr,int N,int index,int sum,vector<int>&ans){
  if(index==N){
      ans.push_back(sum);
      return;
  }
  //every element can be included or not,two choices
  //time complexity-O(2^n )+O(2^nlog(2^n))
  //space-O(2^n)
  summ(arr,N,index+1,sum+arr[index],ans);
    summ(arr,N,index+1,sum,ans);

}
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        summ(arr,N,0,0,ans);
        sort(ans.begin(),ans.end());
        return ans;
      
         
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends