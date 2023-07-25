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
    
      TreeNode* solve(vector<int>&postorder,int poststart,int postend,vector<int>&inorder,int instart,int inend,map<int,int>&mpp){
        if(poststart>postend ||instart>inend)return NULL;
        TreeNode* root=new TreeNode(postorder[postend]);
        int rootInInorder=mpp[root->val];
        int leftnum=rootInInorder-instart;
root->left= solve(postorder,poststart,poststart+leftnum-1,inorder,instart,rootInInorder-1,mpp);
        
root->right=solve(postorder,poststart+leftnum,postend-1,inorder,rootInInorder+1,inend,mpp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return solve(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }
};