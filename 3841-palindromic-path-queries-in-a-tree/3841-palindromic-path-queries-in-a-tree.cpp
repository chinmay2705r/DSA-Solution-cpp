class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> parent(n, 0), depth(n, 0), heavy(n, -1), head(n, 0), pos(n, 0);
        int cur_pos = 0;

        auto dfs = [&](auto& self, int u, int p, int d) -> int {
            parent[u] = p;
            depth[u] = d;
            int size = 1, max_c_size = 0;

            for (int v : adj[u]) {
                if (v != p) {
                    int c_size = self(self, v, u, d + 1);
                    size += c_size;
                    if (c_size > max_c_size) {
                        max_c_size = c_size;
                        heavy[u] = v;
                    }
                }
            }
            return size;
        };

        auto decompose = [&](auto& self, int u, int h) -> void {
            head[u] = h;
            pos[u] = cur_pos++;

            if (heavy[u] != -1) {
                self(self, heavy[u], h);
            }
            for (int v : adj[u]) {
                if (v != parent[u] && v != heavy[u]) {
                    self(self, v, v);
                }
            }
        };

        dfs(dfs, 0, -1, 0);
        decompose(decompose, 0, 0);

        vector<int> seg(4 * n, 0);

        auto updateSeg = [&](auto& self, int node, int start, int end, int idx, int val) -> void {
            if (start == end) {
                seg[node] = val;
                return;
            }
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                self(self, 2 * node, start, mid, idx, val);
            } else {
                self(self, 2 * node + 1, mid + 1, end, idx, val);
            }
            seg[node] = seg[2 * node] ^ seg[2 * node + 1];
        };

        auto querySeg = [&](auto& self, int node, int start, int end, int l, int r) -> int {
            if (r < start || end < l) return 0;
            if (l <= start && end <= r) return seg[node];
            int mid = (start + end) / 2;
            return self(self, 2 * node, start, mid, l, r) ^ self(self, 2 * node + 1, mid + 1, end, l, r);
        };
        for (int i = 0; i < n; ++i) {
            updateSeg(updateSeg, 1, 0, n - 1, pos[i], 1 << (s[i] - 'a'));
        }
        auto queryPath = [&](int a, int b) -> int {
            int res = 0;
            while (head[a] != head[b]) {
                if (depth[head[a]] < depth[head[b]]) swap(a, b);
                res ^= querySeg(querySeg, 1, 0, n - 1, pos[head[a]], pos[a]);
                a = parent[head[a]];
            }
            if (depth[a] > depth[b]) swap(a, b);
            res ^= querySeg(querySeg, 1, 0, n - 1, pos[a], pos[b]);
            return res;
        };

        vector<bool> ans;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                s[u] = c;
                updateSeg(updateSeg, 1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                int u, v;
                ss >> u >> v;
                int mask = queryPath(u, v);
                ans.push_back((mask == 0) || ((mask & (mask - 1)) == 0));
            }
        }

        return ans;
    }
};