
class Solution {
public:
    struct TrieNode {
        TrieNode* child[2] = {nullptr, nullptr};
    };

    class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode();
        }

        void insert(int num) {
            TrieNode* node = root;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if (!node->child[bit]) {
                    node->child[bit] = new TrieNode();
                }

                node = node->child[bit];
            }
        }

        int getMax(int num) {
            TrieNode* node = root;
            int ans = 0;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                int opposite = 1 - bit;

                if (node->child[opposite]) {
                    ans |= (1 << i);
                    node = node->child[opposite];
                } else {
                    node = node->child[bit];
                }
            }

            return ans;
        }
    };

    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for (int num : nums) {
            trie.insert(num);
        }

        int maxi = 0;

        for (int num : nums) {
            maxi = max(maxi, trie.getMax(num));
        }

        return maxi;
    }
};
