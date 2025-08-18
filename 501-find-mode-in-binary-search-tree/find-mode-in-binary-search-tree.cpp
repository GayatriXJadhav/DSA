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
    vector<int> findMode(TreeNode* root) {
      inorder(root);
      return modes;

    }
    private:
    int current_val=0;
    int current_count=0;
    int max_val=0;
    vector<int>modes;
    void inorder(TreeNode *node){
        if(!node) return ;

        inorder(node->left);

        current_count=(node->val==current_val) ? current_count + 1:1;
        if(current_count==max_val){
          modes.push_back(node->val);
        }
        else if(current_count>max_val){
            max_val=current_count;
            modes={node->val};
        }
        current_val=node->val;
        inorder(node->right);
    }
};