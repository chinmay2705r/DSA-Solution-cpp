
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int prefix_sum = 0;
        int even_count = 1;
        int odd_count = 0;

        for (int num : arr) {
            prefix_sum += num;
            if (prefix_sum % 2 == 1) {
                ans = (ans + even_count) % MOD;
                odd_count++;
            } else {
                ans = (ans + odd_count) % MOD;
                even_count++;
            }
        }

        return ans;
    }
};