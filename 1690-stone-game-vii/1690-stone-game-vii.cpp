class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; ++i){
            prefix[i + 1] = prefix[i] +stones[i];
        }
        vector<vector<int>> dp(n, vector<int>(n,0));

        for(int len = 2; len <= n; ++len){
            for(int i = 0; i <= n - len; ++i){
                int j = i + len - 1;
            
                int takeLeft = (prefix[j + 1]- prefix[i + 1]) - dp[i + 1][j];

                int takeRight = (prefix[j] - prefix[i]) - dp[i][j - 1];

                dp[i][j] = max(takeLeft, takeRight);
            }    
        }
        return dp[0][n - 1];   
    }
};