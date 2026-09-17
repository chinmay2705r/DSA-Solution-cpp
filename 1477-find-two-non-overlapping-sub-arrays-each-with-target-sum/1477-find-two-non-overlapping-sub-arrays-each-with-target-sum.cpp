class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX);
        
        int current_sum = 0;
        int left = 0;
        int ans = INT_MAX;
        int best_so_far = INT_MAX;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }

            if (current_sum == target) {
                int current_len = right - left + 1;

                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = min(ans, min_len[left - 1] + current_len);
                }

                best_so_far = min(best_so_far, current_len);
            }
            if (right > 0) {
                min_len[right] = min(min_len[right - 1], best_so_far);
            } else {
                min_len[right] = best_so_far;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};