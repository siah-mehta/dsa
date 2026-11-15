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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;

        function<bool(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return false;

            if (st.count(k - node->val)) return true;

            st.insert(node->val);

            return dfs(node->left) || dfs(node->right);
        };

        return dfs(root);
    }
};
