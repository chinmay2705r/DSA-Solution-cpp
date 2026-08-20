class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        const int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(3, -INF));

        for (int i = 0; i < m; ++i) {
            vector<vector<int>> next_dp(n, vector<int>(3, -INF));

            for (int j = 0; j < n; ++j) {
                int val = coins[i][j];

                for (int k = 0; k <= 2; ++k) {

                    int prevMax = -INF;
                    if (i > 0) prevMax = max(prevMax, dp[j][k]);
                    if (j > 0) prevMax = max(prevMax, next_dp[j - 1][k]);

                    if (i == 0 && j == 0) prevMax = 0;

                    if (prevMax != -INF) {
 
                        next_dp[j][k] = max(next_dp[j][k], prevMax + val);

                        if (val < 0 && k > 0) {
                            int prevNeutral = -INF;
                            if (i > 0) prevNeutral = max(prevNeutral, dp[j][k - 1]);
                            if (j > 0) prevNeutral = max(prevNeutral, next_dp[j - 1][k - 1]);
                            if (i == 0 && j == 0) prevNeutral = 0;

                            if (prevNeutral != -INF) {
                                next_dp[j][k] = max(next_dp[j][k], prevNeutral);
                            }
                        }
                    }
                }
            }
            dp = move(next_dp);
        }

        return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};