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
    
    void solve(TreeNode* node,string path,string &mini){
        if(node==NULL)return;
        
        if(!node->left && !node->right){
            string currentPath = string(1, 'a' + node->val) + path;
            if(currentPath.compare(mini)<0){
                mini=currentPath;
                return;
            }
        }
        
        if(node->left){
            solve(node->left,string(1,'a'+node->val)+path,mini);
        }
        
        if(node->right){
            solve(node->right, string(1,'a'+ node->val)+path,mini);
        }
        
        
    }
    string smallestFromLeaf(TreeNode* root) {
        
        string path="";
        string mini="~";
        
        solve(root,path,mini);
        return mini;
        
        
    }
};