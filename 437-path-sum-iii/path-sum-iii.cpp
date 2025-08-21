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
    int dfs(TreeNode* root, int targetSum,vector<long long>&path){
        if(!root) return 0;
        path.push_back(root->val);
        long long sum=0;
        int count=0;
        for(int i=path.size()-1;i>=0;i--){
            sum+=path[i];
            if(sum==targetSum) count++;
        }
        count+=dfs(root->left,targetSum,path);
        count+=dfs(root->right,targetSum,path);
        path.pop_back();
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
       vector<long long>path;
       return dfs(root,targetSum,path);

    }
};