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
    void sumLeaves(TreeNode *root, int &sum,int ans,int &cnt){
        if(root==NULL) return ;
        cnt++;
        if(cnt==ans){
            sum+=root->val;
        }
        if(root->left) {
            sumLeaves(root->left,sum,ans,cnt);
        }
        if(root->right){
            sumLeaves(root->right,sum,ans,cnt);
        }
        cnt--;
    }
    int height(TreeNode *root){
        if(root==NULL) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return 1 + max(lh,rh);
    }
    int deepestLeavesSum(TreeNode* root) {
        int ans=height(root);
        int sum=0,cnt=0;
        sumLeaves(root,sum,ans,cnt);
        return sum;
    }
};