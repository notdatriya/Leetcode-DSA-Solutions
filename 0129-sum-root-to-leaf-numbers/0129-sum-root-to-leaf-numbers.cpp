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
    void solve(TreeNode* node, int &sum,string path){
         if(!node->left && !node->right){
             path+=to_string(node->val);
             sum+=stoi(path);
             cout<<sum<<" ";
             return;
         }
        
        path+=to_string(node->val);
        
       if(node->left) solve(node->left,sum,path);
       if(node->right) solve(node->right,sum,path);
        
    
    }
    int sumNumbers(TreeNode* root) {
       
        int sum=0;
        string path="";
        solve(root,sum,path);
        return sum;
    }
};