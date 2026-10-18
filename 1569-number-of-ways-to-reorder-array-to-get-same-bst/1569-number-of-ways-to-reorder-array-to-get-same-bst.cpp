class Solution {
private:
    long long MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    void precomputeComb(int n) {
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
    }

    long long dfs(const vector<int>& nums) {
        int m = nums.size();
        if (m <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];

        for (int i = 1; i < m; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long left_ways = dfs(left);
        long long right_ways = dfs(right);

        int L = left.size();
        int R = right.size();

        long long res = (comb[L + R][L] * left_ways) % MOD;
        res = (res * right_ways) % MOD;

        return res;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precomputeComb(n);
        
        long long total = dfs(nums);
        return (total - 1 + MOD) % MOD;
    }
};