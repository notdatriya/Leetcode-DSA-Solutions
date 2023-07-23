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
    
    int solve(TreeNode* root,int &maxpath){
        if(root==NULL) return 0;
        int lsum=max(0,solve(root->left,maxpath));
        int rsum=max(0,solve(root->right,maxpath));
        maxpath=max(maxpath,lsum+rsum+root->val);
        return root->val +max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxpath=INT_MIN;
        solve(root,maxpath);
        return maxpath;
    }
};