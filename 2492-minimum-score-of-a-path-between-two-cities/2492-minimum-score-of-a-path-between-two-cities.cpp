class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
      
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }
        
        queue<int> q;
        vector<bool> visited(n + 1, false);
        
        q.push(1);
        visited[1] = true;
        
        int min_score = INT_MAX;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int dist = edge.second;
                
                
                min_score = min(min_score, dist);
                
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        
        return min_score;
    }
};