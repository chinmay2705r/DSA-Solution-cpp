class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sorted;
        sorted.reserve(n);
        for (int i = 0; i < n; ++i) {
            sorted.push_back({nums[i], i});
        }
        sort(sorted.begin(), sorted.end());
        vector<int> sorted_pos(n);
        for (int i = 0; i < n; ++i) {
            sorted_pos[sorted[i].second] = i;
        }
        int LOG = 18;
        vector<vector<int>> up(n, vector<int>(LOG));
        
        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && sorted[r].first - sorted[l].first <= maxDiff) {
                r++;
            }
            up[l][0] = r - 1;
        }
        
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                int next_node = up[i][j - 1];
                up[i][j] = up[next_node == i ? i : next_node][j - 1];
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = sorted_pos[q[0]];
            int v = sorted_pos[q[1]];
            
            if (u == v) {
                answer.push_back(0);
                continue;
            }
            if (u > v) swap(u, v);
            int distance = 0;
            for (int j = LOG - 1; j >= 0; --j) {
                if (up[u][j] < v && up[u][j] != u) {
                    u = up[u][j];
                    distance += (1 << j);
                }
            }
            if (up[u][0] >= v) {
                answer.push_back(distance + 1);
            } else {
                answer.push_back(-1); 
            }
        }
        
        return answer;
    }
};