class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = nums1[0];
        bool hasOdd = false;

        for (int x : nums1) {
            if (x < minVal) {
                minVal = x;
            }
            if (x % 2 != 0) {
                hasOdd = true;
            }
        }

        return !hasOdd || (minVal % 2 != 0);
    }
};