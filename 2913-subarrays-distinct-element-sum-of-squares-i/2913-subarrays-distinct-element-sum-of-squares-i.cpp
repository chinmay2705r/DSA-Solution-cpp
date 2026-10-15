class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> unique_elements;
            for (int j = i; j < n; ++j) {
                unique_elements.insert(nums[j]);
                int distinct_count = unique_elements.size();
                total_sum += distinct_count * distinct_count;
            }
        }

        return total_sum;
    }
};