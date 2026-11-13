class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        
        deque<pair<long long, int>> dq;
        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            long long val = nums[l];
            int cnt = 1;
            while (!dq.empty() && dq.front().first < val) {
                auto [block_val, block_cnt] = dq.front();
                dq.pop_front();
                cost += (val - block_val) * block_cnt;
                cnt += block_cnt;
            }
            dq.push_front({val, cnt});
            while (cost > k) {
                auto& [back_val, back_cnt] = dq.back();
                cost -= (back_val - nums[r]);
                back_cnt--;
                if (back_cnt == 0) {
                    dq.pop_back();
                }
                r--;
            }
            ans += (r - l + 1);
        }

        return ans;
    }
};