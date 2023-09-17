//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
   void summ(int i,vector<int>&num,int sum,vector<int>&ans){
	if(i==num.size()){
		ans.push_back(sum);
		return;
	}

	sum+=num[i];
	summ(i+1,num,sum,ans);
	sum-=num[i];
	summ(i+1,num,sum,ans);

}

   
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int sum=0;
	vector<int>ans;
	summ(0,arr,sum,ans);
	sort(ans.begin(),ans.end());
	return ans;
	
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends