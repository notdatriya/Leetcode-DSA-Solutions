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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mpp;
   vector<int>ans;
if(root==NULL)return ans;
   queue<pair<TreeNode*,int>>q;
   q.push({root, 0});
   while(!q.empty()){
       auto temp=q.front();
       q.pop();
       TreeNode*node=temp.first;
       int vertical=temp.second;
        if(mpp.find(vertical)==mpp.end()){
            mpp[vertical]=node->val;
        }

        if(node->right)q.push({node->right,vertical+1});
       if(node->left)q.push({node->left,vertical+1});
   }

   for(auto it:mpp){
       ans.push_back(it.second);
   }
   return ans;
    }
};