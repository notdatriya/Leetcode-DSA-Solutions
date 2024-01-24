/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool ispal(vector<int>&path){
//         unordered_map<int,int>mpp;
//         for(auto i:path){
//             mpp[i]++;
//         }
        
//         int oddcount=0;
//         for(auto val:mpp){
//             if(val.second %2!=0){
//                 oddcount++;
//             }
//         }
        
//        if(oddcount<=1)return true;
//         return false;
//     }
    
    int solve(TreeNode* root,int pathfreq){
        if(root==NULL)return 0;
        
        // path.push_back(root->val);
        cout<<pathfreq<<endl;
        pathfreq^=(1<<root->val);
                cout<<pathfreq<<endl;
            
        
        if(!root->left && !root->right){
            //if there will be all even numbers, pathfreq -1 will be have 
            return (pathfreq & (pathfreq-1))==0; 
            // path.pop_back();
            // return count;
        }
        
        
        int left=solve(root->left,pathfreq);
        int right=solve(root->right,pathfreq);
        // path.pop_back();
        return left+right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        // int count=0;
        // vector<int>path;
        // count=solve(root,path,count);
        return solve(root,0);
    }
};