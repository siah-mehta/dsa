class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
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

        unordered_map<string, int> emailOwner;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailOwner.count(email)) {
                    unite(i, emailOwner[email]);
                } else {
                    emailOwner[email] = i;
                }
            }
        }

        vector<set<string>> merged(n);

        for (auto& [email, owner] : emailOwner) {
            merged[find(owner)].insert(email);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (merged[i].empty()) continue;

            vector<string> account;
            account.push_back(accounts[i][0]);

            for (const string& email : merged[i]) {
                account.push_back(email);
            }

            ans.push_back(account);
        }

        return ans;
    }
};