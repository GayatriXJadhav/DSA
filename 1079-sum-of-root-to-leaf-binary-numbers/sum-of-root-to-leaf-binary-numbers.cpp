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
    int sum(TreeNode *root, int current){
        if(!root) return 0;
        current=current*2 + root->val;
        if(!root->left && !root->right) return current;
        return sum(root->left,current)+sum(root->right,current);
    }
    int sumRootToLeaf(TreeNode* root) {
         int current=0;
        int ans=sum(root,current);
        return ans;
    }
};