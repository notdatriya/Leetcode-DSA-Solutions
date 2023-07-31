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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)return NULL;
        int i=0;
        TreeNode* root=new TreeNode(preorder[i]);
        cout<<preorder[i]<<endl;
        i++;
        TreeNode* temp=root;

        while(i!=preorder.size()){
            if(preorder[i]>root->val){
                if(root->right==NULL){
                    root->right=new TreeNode(preorder[i]);
                    root=temp;
                            cout<<preorder[i]<<endl;

                    i++;
                }
                else{
                    root=root->right;
                }
            }
            else{
                if(root->left==NULL){
                    root->left=new TreeNode(preorder[i]);
                    root=temp;
                            cout<<preorder[i]<<endl;

                    i++;
                }
                else{
                    root=root->left;
                }
            }
        }
        return temp;
    }
};