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
//     void solve(TreeNode* root,int low,int high,int &sum){
//         if(root==NULL)return ;
//         if(root->val>=low && root->val<=high){
//             sum+=root->val;
//         }
//        solve(root->left,low,high,sum);
//         solve(root->right,low,high,sum);
        
//     }
    
    int solve(TreeNode* root, int low,int high){
        if(root==NULL)return 0;
        int currvalue=0;
         if(root->val>=low && root->val<=high){
            currvalue=root->val;
        }
        return currvalue+solve(root->left,low,high)+solve(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        // int sum=0;
     // solve(root,low,high,sum);
        // return sum;
        return solve(root,low,high);
        
    }
};