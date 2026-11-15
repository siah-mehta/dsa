class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) return;

            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;

            if (rank[a] == rank[b]) rank[a]++;
        };

        unordered_map<int, int> rowOwner, colOwner;

        for (int i = 0; i < n; i++) {
            int r = stones[i][0];
            int c = stones[i][1];

            if (rowOwner.count(r)) unite(i, rowOwner[r]);
            else rowOwner[r] = i;

            if (colOwner.count(c)) unite(i, colOwner[c]);
            else colOwner[c] = i;
        }

        unordered_set<int> components;

        for (int i = 0; i < n; i++) {
            components.insert(find(i));
        }

        return n - components.size();
    }
};