/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            int size = q.size();
           
            vector<TreeNode*> level;
            for (int i = 0; i < size; i++) {
                auto it = q.front();
                q.pop();
                level.push_back(it);
                if (it->left) {
                    q.push(it->left);
                }
                if (it->right) {
                    q.push(it->right);
                }
            }
            if (flag) {
                int left = 0, right = level.size() - 1;
                while (left < right) {
                    swap(level[left]->val, level[right]->val);
                    left++;
                    right--;
                }
            }
            flag = !flag;
        }
        return root;
    }
};