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
    void solve(TreeNode* root, map<TreeNode*,TreeNode*>&mpp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
        
    }
    
   TreeNode* findnode(TreeNode* root, int start) {
    if(root->val==start)return root;
       TreeNode* left=NULL;
       TreeNode* right=NULL;
       if(root->left)left=findnode(root->left,start);
    if(root->right)right=findnode(root->right,start);
    if(left)return left;
    else return right;
}
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mpp;
        solve(root,mpp);
        
        TreeNode* startnode=findnode(root,start);
        
        map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(startnode);
        vis[startnode]=true;
        int t=0;
        int flag=0;
        while(!q.empty()){
            int size=q.size();
            flag=0;
            for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=NULL && !vis[temp->left]){
                vis[temp->left]=true;
                q.push(temp->left);
                flag=1;
            }
            if(temp->right!=NULL && !vis[temp->right]){
                vis[temp->right]=true;
                q.push(temp->right);
                flag=1;
            }
            if(mpp.find(temp)!=mpp.end() && !vis[mpp[temp]]){
                vis[mpp[temp]]=true;
                q.push(mpp[temp]);
                flag=1;
            }
            }
            if(flag==1){
            t++;
            }
        }
        return t;
        
    }
};