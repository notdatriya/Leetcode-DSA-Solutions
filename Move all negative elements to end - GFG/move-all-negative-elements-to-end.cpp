//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        int c1=0;
        int c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                c1++;
            }
            else{
                c2++;
            }
        }
        int arr2[n];
        int j=c2;
        int k=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                arr2[k++]=arr[i];
            }
            else{
                arr2[j++]=arr[i];
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=arr2[i];
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends