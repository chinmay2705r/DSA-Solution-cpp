class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, 1e18);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            long long min_prev = 1e18;
            for (int k = 1; k <= 3; ++k) {
                if (i - k >= 0) {
                    min_prev = min(min_prev, dp[i - k] + (long long)k * k);
                }
            }
            dp[i] = costs[i - 1] + min_prev;
        }

        return dp[n];
    }
};