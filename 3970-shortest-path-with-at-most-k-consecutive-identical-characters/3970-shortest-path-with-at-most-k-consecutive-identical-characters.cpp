class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));

        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d > dist[u][cnt]) continue;

            if (u == n - 1) return d;

            for (const auto& [v, w] : adj[u]) {
                int next_cnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (next_cnt <= k && d + w < dist[v][next_cnt]) {
                    dist[v][next_cnt] = d + w;
                    pq.push({d + w, v, next_cnt});
                }
            }
        }

        return -1;
    }
};