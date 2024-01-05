/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void make_parent( map<TreeNode*,TreeNode*>&mpp,TreeNode* root){
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
        
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mpp;
        make_parent(mpp,root);
        
        queue<TreeNode*>q;
        map<TreeNode*,bool>vis;
        
        vis[target]=true;
        int level=0;
        q.push(target);
        while(!q.empty()){
            int size=q.size();
            if(level==k)break;
                level++;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                
                if(temp->left && !vis[temp->left]){
                    vis[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right && !vis[temp->right]){
                    vis[temp->right]=true;
                    q.push(temp->right);
                }
                if(mpp[temp] && !vis[mpp[temp]]){
                    vis[mpp[temp]]=true;
                    q.push(mpp[temp]);
                }
            }
        }
            
            vector<int>ans;
            while(!q.empty()){
                TreeNode* node=q.front();
                q.pop();
                ans.push_back(node->val);
            }
            return ans;
        
    }
};