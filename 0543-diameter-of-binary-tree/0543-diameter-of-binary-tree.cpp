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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        function<int(TreeNode*)> height = [&](TreeNode* node) {
            if (!node) return 0;

            int left = height(node->left);
            int right = height(node->right);

            diameter = max(diameter, left + right);

            return 1 + max(left, right);
        };

        height(root);
        return diameter;
    }
};
