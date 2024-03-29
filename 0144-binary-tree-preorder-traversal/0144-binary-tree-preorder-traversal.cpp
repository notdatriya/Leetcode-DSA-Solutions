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
    vector<int> preorderTraversal(TreeNode* root) {
        //root-left-right;
        // stack<TreeNode*>st;
        // vector<int>ans;
        // if(root==NULL) return ans;
        // TreeNode* node=root;
        // st.push(node);
        // while(!st.empty()){
        //     node=st.top();
        //     ans.push_back(node->val);
        //     st.pop();
        //     if(node->right!=NULL)st.push(node->right);  
        //     if(node->left!=NULL)st.push(node->left);
        // }
        // return ans;
        
        
        
        //m-2 morris preorder
        
        vector<int>ans;
        TreeNode* curr=root;
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};