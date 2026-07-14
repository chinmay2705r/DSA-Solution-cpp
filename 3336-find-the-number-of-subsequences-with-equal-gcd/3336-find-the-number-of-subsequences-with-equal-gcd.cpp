class Solution {
    int memo[201][201][201];
    int n;
    const int MOD = 1e9 + 7;

    // Standard helper for Greatest Common Divisor
    int getGCD(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        return std::gcd(a, b);
    }

    int solve(int idx, int g1, int g2, vector<int>& nums) {
        // Base case: processed all elements
        if (idx == n) {
            // Both must be non-empty (g1 > 0) and have equal GCD
            return (g1 == g2 && g1 > 0) ? 1 : 0;
        }

        // Return cached result if already computed
        if (memo[idx][g1][g2] != -1) {
            return memo[idx][g1][g2];
        }

        // Choice 1: Skip the current element
        long long ans = solve(idx + 1, g1, g2, nums);

        // Choice 2: Include in seq1
        ans = (ans + solve(idx + 1, getGCD(g1, nums[idx]), g2, nums)) % MOD;

        // Choice 3: Include in seq2
        ans = (ans + solve(idx + 1, g1, getGCD(g2, nums[idx]), nums)) % MOD;

        return memo[idx][g1][g2] = ans;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(memo, -1, sizeof(memo));
        
        // Start from index 0, both subsequences initially empty (GCD = 0)
        return solve(0, 0, 0, nums);
    }
};