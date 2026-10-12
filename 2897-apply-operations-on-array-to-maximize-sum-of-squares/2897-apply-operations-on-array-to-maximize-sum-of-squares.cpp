class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bit_count(30, 0);

        for (int num : nums) {
            for (int b = 0; b < 30; ++b) {
                if ((num >> b) & 1) {
                    bit_count[b]++;
                }
            }
        }

        long long total_sum = 0;

        for (int i = 0; i < k; ++i) {
            long long current_num = 0;
            for (int b = 0; b < 30; ++b) {
                if (bit_count[b] > 0) {
                    current_num |= (1LL << b);
                    bit_count[b]--;
                }
            }
            total_sum = (total_sum + (current_num % MOD) * (current_num % MOD)) % MOD;
        }

        return total_sum;
    }
};