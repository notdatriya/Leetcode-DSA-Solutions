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
     TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
  
    
    void inorderr(TreeNode* root){
        if(root==NULL)return ;
        inorderr(root->left);
        // if(val1==NULL && root->val<=prev->val){
        //     val1=root;
        // }
        // else if(val1!=NULL && root->val<=prev->val){
        //     val2=root;
        // }
        
        if(prev!=NULL && root->val<=prev->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorderr(root->right);
    }
    
   
    void recoverTree(TreeNode* root) {
        first=last=middle=prev=NULL;
           // prev= new TreeNode(INT_MIN);
        inorderr(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle)swap(first->val,middle->val);
        
    }
};