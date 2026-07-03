class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        
        
        vector<long long> dp(n, 0);
        dp[0] = 1; // Starting position
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (obstacleGrid[r][c] == 1) {
                    dp[c] = 0; 
                } else if (c > 0) {
                    
                    dp[c] += dp[c - 1];
                }
            }
        }
        
        return dp[n - 1];
    }
};