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
    vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*>st;
//         vector<int>inorder;
//         TreeNode* node=root;
//         //left-root-right
       
//         while(true){
//          if(node!=NULL){
//              st.push(node);
//              node=node->left;
//          }
//             else{
//                 if(st.empty())break;
//                 node=st.top();
//                 st.pop();
//                 inorder.push_back(node->val);
//                 node=node->right;
//             }
            
//         }
//         return inorder;
        
        
        //m-2 morris inorder traversal  time-O(n) and space=O(1)
        
        TreeNode* curr=root;
        vector<int>inorder;
        while(curr){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                //mark left subtree ka rightmost thread pointing curr root
                TreeNode* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
        
        
    }
};