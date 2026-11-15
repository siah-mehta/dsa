class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                adj[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> safe;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            safe.push_back(u);

            for (int v : adj[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};