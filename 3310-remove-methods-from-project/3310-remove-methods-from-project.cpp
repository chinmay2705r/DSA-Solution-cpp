class Solution {
private:

    void markSuspicious(int u, const vector<vector<int>>& adj, vector<bool>& suspicious) {
        suspicious[u] = true;
        for (int neighbor : adj[u]) {
            if (!suspicious[neighbor]) {
                markSuspicious(neighbor, adj, suspicious);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            int caller = inv[0];
            int callee = inv[1];
            adj[caller].push_back(callee);
        }

        vector<bool> suspicious(n, false);
        markSuspicious(k, adj, suspicious);

        for (const auto& inv : invocations) {
            int caller = inv[0];
            int callee = inv[1];
            
            if (!suspicious[caller] && suspicious[callee]) {
    
                vector<int> allMethods(n);
                for (int i = 0; i < n; ++i) {
                    allMethods[i] = i;
                }
                return allMethods;
            }
        }
        vector<int> remaining;
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) {
                remaining.push_back(i);
            }
        }

        return remaining;
    }
};