class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                if (i + 2 * M >= n) {
                    memo[i][M] = suffixSum[i];
                } else {
                    int maxStones = 0;
                    for (int X = 1; X <= 2 * M; ++X) {
                        int nextM = max(M, X);
                        int opponentStones = memo[i + X][nextM];
                        maxStones = max(maxStones, suffixSum[i] - opponentStones);
                    }
                    memo[i][M] = maxStones;
                }
            }
        }

        return memo[0][1];
    }
};