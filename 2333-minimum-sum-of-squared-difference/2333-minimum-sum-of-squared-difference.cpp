class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<long long> count(100001, 0);
        for (int i = 0; i < n; ++i) {
            count[abs(nums1[i] - nums2[i])]++;
        }
        for (int d = 100000; d > 0 && k > 0; --d) {
            if (count[d] == 0) continue;

            long long take = min(k, count[d]);
            count[d] -= take;
            count[d - 1] += take;
            k -= take;
        }
        long long ans = 0;
        for (long long d = 1; d <= 100000; ++d) {
            if (count[d] > 0) {
                ans += count[d] * d * d;
            }
        }

        return ans;
    }
};