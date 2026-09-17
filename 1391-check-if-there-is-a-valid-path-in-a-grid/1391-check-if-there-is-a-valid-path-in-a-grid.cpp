class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        const int DIRS[4] = {1, 2, 4, 8};
        const int OPP[4]  = {2, 1, 8, 4};
        const int DR[4]   = {-1, 1, 0, 0};
        const int DC[4]   = {0, 0, -1, 1};

        const int STREET_MASK[7] = {0, 12, 3, 6, 10, 5, 9};

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = -grid[0][0];
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return true;

            int curr_mask = STREET_MASK[-grid[r][c]];

            for (int i = 0; i < 4; ++i) {

                if (curr_mask & DIRS[i]) {
                    int nr = r + DR[i];
                    int nc = c + DC[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                        int next_mask = STREET_MASK[grid[nr][nc]];

                        if (next_mask & OPP[i]) {
                            grid[nr][nc] = -grid[nr][nc]; 
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        return false;
    }
};