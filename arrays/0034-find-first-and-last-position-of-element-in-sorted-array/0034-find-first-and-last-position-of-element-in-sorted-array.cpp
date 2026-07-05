#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int low = 0, high = nums.size() - 1;
        int bound = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                bound = mid; // Record candidate index
                if (isFirst) high = mid - 1; // Keep searching left
                else low = mid + 1;          // Keep searching right
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return bound;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if (first == -1) return {-1, -1}; 
        int last = findBound(nums, target, false);
        return {first, last};
    }
};