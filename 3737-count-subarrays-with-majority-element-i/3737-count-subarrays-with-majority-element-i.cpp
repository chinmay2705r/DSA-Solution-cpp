class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int balance = 0;
            for (int j = i; j < n; ++j) {
                balance += (nums[j] == target) ? 1 : -1;
                if (balance > 0) {
                    count++;
                }
            }
        }
        return count;
    }
};