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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;

        function<TreeNode*(int)> build = [&](int bound) -> TreeNode* {
            if (i == preorder.size() || preorder[i] > bound) {
                return nullptr;
            }

            TreeNode* root = new TreeNode(preorder[i++]);
            root->left = build(root->val);
            root->right = build(bound);

            return root;
        };

        return build(INT_MAX);
    }
};
