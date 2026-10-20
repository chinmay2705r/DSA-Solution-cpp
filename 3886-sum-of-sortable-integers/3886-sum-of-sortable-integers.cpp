class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        int total_sum = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool is_valid = true;

            for (int i = 0; i < n; i += k) {
                if (sorted_nums[i] == sorted_nums[i + k - 1]) {
                    for (int j = 0; j < k; ++j) {
                        if (nums[i + j] != sorted_nums[i]) {
                            is_valid = false;
                            break;
                        }
                    }
                    if (!is_valid) break;
                    continue;
                }
                int offset = -1;
                for (int j = 0; j < k; ++j) {
                    if (nums[i + j] == sorted_nums[i] && nums[i + (j + 1) % k] != sorted_nums[i]) {
                        int count = 0;
                        while (sorted_nums[i + count] == sorted_nums[i]) {
                            count++;
                        }
                        offset = (j - count + 1 + k) % k;
                        break;
                    }
                }

                if (offset == -1) {
                    is_valid = false;
                    break;
                }
                for (int j = 0; j < k; ++j) {
                    if (nums[i + (offset + j) % k] != sorted_nums[i + j]) {
                        is_valid = false;
                        break;
                    }
                }

                if (!is_valid) break;
            }

            if (is_valid) {
                total_sum += k;
            }
        }

        return total_sum;
    }
};