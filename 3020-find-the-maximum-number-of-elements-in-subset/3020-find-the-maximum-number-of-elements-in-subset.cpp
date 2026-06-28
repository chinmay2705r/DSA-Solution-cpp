class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        int maxLen = 0;
        if (counts.count(1)) {
            int oneCount = counts[1];
            if (oneCount % 2 == 0) {
                maxLen = max(maxLen, oneCount - 1);
            } else {
                maxLen = max(maxLen, oneCount);
            }
        }

        for (auto& [val, count] : counts) {
            if (val == 1) continue;

            long long current = val;
            int currentLen = 0;

            while (counts.count(current) && counts[current] >= 2) {
                currentLen += 2;
                current = current * current; 
            }

            if (counts.count(current) && counts[current] >= 1) {
                currentLen += 1;
            } else {
            
                currentLen -= 1;
            }

            maxLen = max(maxLen, currentLen);
        }

        return maxLen;
    }
};