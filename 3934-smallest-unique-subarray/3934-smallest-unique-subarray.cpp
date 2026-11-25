
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const uint64_t MOD1 = 1000000007ULL;
        const uint64_t MOD2 = 1000000009ULL;
        const uint64_t BASE1 = 100003ULL;
        const uint64_t BASE2 = 100033ULL;

        vector<uint64_t> pow1(n + 1, 1), pow2(n + 1, 1);
        vector<uint64_t> pref1(n + 1, 0), pref2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pow1[i + 1] = (pow1[i] * BASE1) % MOD1;
            pow2[i + 1] = (pow2[i] * BASE2) % MOD2;
            pref1[i + 1] = (pref1[i] * BASE1 + nums[i]) % MOD1;
            pref2[i + 1] = (pref2[i] * BASE2 + nums[i]) % MOD2;
        }

        auto has_unique = [&](int len) -> bool {
            int count = n - len + 1;
            vector<uint64_t> hashes(count);

            for (int i = 0; i < count; ++i) {
                uint64_t h1 = (pref1[i + len] + MOD1 - (pref1[i] * pow1[len]) % MOD1) % MOD1;
                uint64_t h2 = (pref2[i + len] + MOD2 - (pref2[i] * pow2[len]) % MOD2) % MOD2;
                hashes[i] = (h1 << 32) | h2;
            }

            sort(hashes.begin(), hashes.end());

            for (int i = 0; i < count; ++i) {
                bool diff_prev = (i == 0) || (hashes[i] != hashes[i - 1]);
                bool diff_next = (i == count - 1) || (hashes[i] != hashes[i + 1]);
                if (diff_prev && diff_next) {
                    return true;
                }
            }
            return false;
        };

        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (has_unique(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};