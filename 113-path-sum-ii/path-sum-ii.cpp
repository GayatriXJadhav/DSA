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
private:
 vector<vector<int>> findPath(TreeNode *root,int targetSum, int sum,vector<vector<int>>&ans, vector<int>&paths){
    if(!root) return ans;
    sum+=root->val;
    paths.push_back(root->val);
 
    if(!root->left && !root->right){
        if(sum==targetSum){
        ans.push_back(paths);
      
        }   
       
    }
      findPath(root->left,targetSum,sum,ans,paths);
    findPath(root->right,targetSum,sum,ans,paths);
    paths.pop_back();
   
   return ans;
  }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
         vector<int>paths;
        if(!root) return ans;
        int currSum=0;
       findPath(root,targetSum,currSum,ans,paths);

        return ans;

    }
};