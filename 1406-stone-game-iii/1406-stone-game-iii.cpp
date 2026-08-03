class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int maxDiff = INT_MIN;
            int currentSum = 0;
            for (int k = 0; k < 3 && i + k < n; ++k) {
                currentSum += stoneValue[i + k];
                int nextDiff = dp[i + k + 1];
                maxDiff = max(maxDiff, currentSum - nextDiff);
            }

            dp[i] = maxDiff;
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};