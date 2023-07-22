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
    
    bool isLeaf(TreeNode* node){
        return (!node->left && !node->right);
    }
    
    void solve(TreeNode*root,vector<string>&ans,string path){
        if(!root){
            return;
        }
      
        
        if(isLeaf(root)){
            cout<<"before path leaf"<<path<<endl;
              path+=to_string(root->val);
         cout<<"After path leaf"<<path<<endl;
            ans.push_back(path);
            return;
        }
        
                    cout<<"before path"<<path<<endl;
        path+=to_string(root->val)+"->";
                    cout<<"After path"<<path<<endl;
        solve(root->left,ans,path);
        solve(root->right,ans,path);
        // path.erase(path.end()-1);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path;
        if(root==NULL)return ans;
        solve(root,ans,path);
        return ans;
       
    }
};