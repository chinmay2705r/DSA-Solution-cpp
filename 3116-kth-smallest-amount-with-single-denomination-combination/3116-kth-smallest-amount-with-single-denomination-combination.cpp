class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto count = [&](long long target) {
            long long total = 0;

            for (int mask = 1; mask < (1 << n); ++mask) {
                long long currentLcm = 1;
                int bits = 0;
                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        bits++;
                        currentLcm = std::lcm(currentLcm, (long long)coins[i]);
                    }
                }
                
                long long terms = target / currentLcm;
                if (bits % 2 == 1) {
                    total += terms;
                } else {
                    total -= terms;
                }
            }
            return total;
        };

        long long left = 1;
        long long right = 1LL * *min_element(coins.begin(), coins.end()) * k;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (count(mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};