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
class BSTIterator{
    private:
  stack<TreeNode*>st;
    //decOrder-true  - before;
    //decOrder-false - after;
    bool decOrder=true;
void pushInStack(TreeNode* root){
    
        while(root!=NULL){
            st.push(root);
            if(!decOrder){
            root=root->left;
            }
            else{
                root=root->right;
            }
        }
    }
    public:
    BSTIterator(TreeNode* root,bool isRev){
        decOrder=isRev;
        pushInStack(root);
    }
    
     int next() {
        TreeNode* node=st.top();
        st.pop();
        if(!decOrder){
            pushInStack(node->right);
        }
         else{
             pushInStack(node->left);
         }
        return node->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k)return true;
            else if(i+j>k){
                j=r.next();
            }
            else{
                i=l.next();
            }
        }
        return false;

    }
};