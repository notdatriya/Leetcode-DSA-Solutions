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
    
    TreeNode* solve(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,map<int,int>&mpp){
        if(prestart>preend ||instart>inend)return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int rootInInorder=mpp[root->val];
        int leftnum=rootInInorder-instart;
root->left= solve(preorder,prestart+1,prestart+leftnum,inorder,instart,rootInInorder-1,mpp);
        
root->right=solve(preorder,prestart+leftnum+1,preend,inorder,rootInInorder+1,inend,mpp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }
};