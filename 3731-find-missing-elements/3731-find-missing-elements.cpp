class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = nums[0];
        int maxVal = nums[0];
        unordered_set<int> present;

        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
            present.insert(num);
        }

        vector<int> missing;
        for (int curr = minVal; curr <= maxVal; ++curr) {
            if (present.find(curr) == present.end()) {
                missing.push_back(curr);
            }
        }

        return missing;
    }
};
