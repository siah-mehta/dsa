class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), rank(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };

        for (auto& e : edges) {
            int u = find(e[0]);
            int v = find(e[1]);

            if (u == v) return e;

            if (rank[u] < rank[v]) swap(u, v);
            parent[v] = u;

            if (rank[u] == rank[v]) rank[u]++;
        }

        return {};
    }
};