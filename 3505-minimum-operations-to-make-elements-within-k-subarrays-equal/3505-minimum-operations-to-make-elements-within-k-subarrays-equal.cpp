class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        vector<long long> cost(n, 0);

        multiset<long long> left, right;
        long long sum_left = 0, sum_right = 0;

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                long long val = *it;
                left.erase(it);
                sum_left -= val;
                right.insert(val);
                sum_right += val;
            }
            while (left.size() < right.size()) {
                auto it = right.begin();
                long long val = *it;
                right.erase(it);
                sum_right -= val;
                left.insert(val);
                sum_left += val;
            }
        };

        auto add = [&](long long val) {
            if (left.empty() || val <= *prev(left.end())) {
                left.insert(val);
                sum_left += val;
            } else {
                right.insert(val);
                sum_right += val;
            }
            balance();
        };

        auto remove = [&](long long val) {
            auto it_left = left.find(val);
            if (it_left != left.end()) {
                left.erase(it_left);
                sum_left -= val;
            } else {
                auto it_right = right.find(val);
                right.erase(it_right);
                sum_right -= val;
            }
            balance();
        };

        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                long long median = *prev(left.end());
                cost[i] = (median * left.size() - sum_left) + (sum_right - median * right.size());
            }
        }

        const long long INF = 1e18;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        fill(dp[0].begin(), dp[0].end(), 0);

        for (int j = 1; j <= k; ++j) {
            for (int i = j * x; i <= n; ++i) {
                dp[j][i] = dp[j][i - 1];
                if (dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - 1]);
                }
            }
        }

        return dp[k][n];
    }
};