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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int preIndex = 0;

        function<TreeNode*(int, int)> build = [&](int left, int right) -> TreeNode* {
            if (left > right) return nullptr;

            TreeNode* root = new TreeNode(preorder[preIndex++]);
            int mid = mp[root->val];

            root->left = build(left, mid - 1);
            root->right = build(mid + 1, right);

            return root;
        };

        return build(0, inorder.size() - 1);
    }
};
