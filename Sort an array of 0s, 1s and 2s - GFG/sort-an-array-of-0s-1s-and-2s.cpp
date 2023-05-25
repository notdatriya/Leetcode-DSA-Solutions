//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int at=0;
        int b=0;
        int c=0;
        
        for(int i=0;i<n;i++){
            if(a[i]==0){
                at++;
            }
            else if(a[i]==1){
                b++;
            }
            else{
                c++;
            }
        }
        for(int i=0;i<at;i++){
            a[i]=0;
        }
         for(int i=at;i<at+b;i++){
            a[i]=1;
        }
         for(int i=at+b;i<at+b+c;i++){
            a[i]=2;
        }
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends