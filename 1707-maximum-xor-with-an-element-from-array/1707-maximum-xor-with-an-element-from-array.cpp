
class Solution {
public:
    struct TrieNode {
        TrieNode* child[2];

        TrieNode() {
            child[0] = child[1] = nullptr;
        }
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

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<array<int, 3>> offline;
        int q = queries.size();

        for (int i = 0; i < q; i++) {
            offline.push_back({queries[i][1], queries[i][0], i});
        }

        sort(offline.begin(), offline.end());

        Trie trie;
        vector<int> ans(q, -1);

        int j = 0;

        for (auto& query : offline) {
            int limit = query[0];
            int x = query[1];
            int idx = query[2];

            while (j < nums.size() && nums[j] <= limit) {
                trie.insert(nums[j]);
                j++;
            }

            if (j > 0) {
                ans[idx] = trie.getMax(x);
            }
        }

        return ans;
    }
};
