class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        vector<vector<vector<pair<int, int>>>> go(
            m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-1, -1}))
        );

        for (int r = m - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                
                if (c + 1 < n) {
                    if (grid[r][c + 1] == 0) {
                        go[r][c][0] = {r, c + 1};
                    } else {
                        go[r][c][0] = go[r][c + 1][1];
                    }
                }

                if (r + 1 < m) {
                    if (grid[r + 1][c] == 0) {
                        go[r][c][1] = {r + 1, c};
                    } else { 
                        go[r][c][1] = go[r + 1][c][0];
                    }
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dp[r][c] == 0) continue;

                auto [r_right, c_right] = go[r][c][0];
                if (r_right != -1 && c_right != -1) {
                    dp[r_right][c_right] = (dp[r_right][c_right] + dp[r][c]) % MOD;
                }

                auto [r_down, c_down] = go[r][c][1];
                if (r_down != -1 && c_down != -1) {
                    dp[r_down][c_down] = (dp[r_down][c_down] + dp[r][c]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};