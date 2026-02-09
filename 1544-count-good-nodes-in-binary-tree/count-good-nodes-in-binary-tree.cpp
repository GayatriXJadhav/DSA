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
    void CountNodes(TreeNode* root, int maxi,int &cnt){
        if(root==NULL) return ;
        maxi=max(maxi,root->val);
        if(root->val>=maxi) cnt++;
        CountNodes(root->left,maxi,cnt);
        CountNodes(root->right,maxi,cnt);
    }
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN,cnt=0;
        CountNodes(root,maxi,cnt);
        return cnt;
    }
};