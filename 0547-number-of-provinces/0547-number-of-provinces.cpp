class Solution {
public:
    void dfs(int u, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[u] = true;
        for (int v = 0; v < isConnected.size(); v++) {
            if (isConnected[u][v] && !visited[v]) {
                dfs(v, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }

        return provinces;
    }
};