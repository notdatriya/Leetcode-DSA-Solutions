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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        int d=0;
        while(!q.empty()){
            int size=q.size();
            d++;
            if(d==depth)break;
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                
                 if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
                
                if(d==depth-1){
                    TreeNode* left=node->left;
                    TreeNode* right=node->right;
                    node->left=new TreeNode(val);
                    node->right=new TreeNode(val);
                    node->left->left=left;
                    node->right->right=right;
                }
                
               
            }
            
        }
        
        return root;
        
    }
};