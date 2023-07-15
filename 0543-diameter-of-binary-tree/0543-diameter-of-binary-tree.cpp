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
    
    int solve(TreeNode* node,int &maxi){
        if(node==NULL){
            return 0;
        }
        
        int lh=solve(node->left,maxi);
        int rh=solve(node->right,maxi);
        maxi=max(maxi,lh+rh);
        return 1+ max(lh,rh);
    }
    
//     int maxi=0;
//     int findh(TreeNode* root){
//         if(root==NULL)return 0;
        
//         int lh=findh(root->left);
//         int rh=findh(root->right);
//         return 1+max(lh,rh);
//     }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        solve(root,maxi);
        return maxi;
        
        
        //m-2 less optimized
//         if(root==NULL)return 0;
//         int lh=findh(root->left);
//         int rh=findh(root->right);
//         maxi=max(maxi,lh+rh);
//         diameterOfBinaryTree(root->left);
//         diameterOfBinaryTree(root->right);
        
//         return maxi;

    }
};