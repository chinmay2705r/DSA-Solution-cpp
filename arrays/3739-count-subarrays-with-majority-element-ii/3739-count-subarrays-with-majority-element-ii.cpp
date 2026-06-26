#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int val = (nums[i] == target) ? 1 : -1;
            pref[i + 1] = pref[i] + val;
        }
        
        
        vector<int> allValues = pref;
        sort(allValues.begin(), allValues.end());
        allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());
        
        auto getRank = [&](int val) {
            return lower_bound(allValues.begin(), allValues.end(), val) - allValues.begin() + 1;
        };
        
        int m = allValues.size();
        vector<int> bit(m + 1, 0);
        
        auto update = [&](int idx, int delta) {
            for (; idx <= m; idx += idx & -idx) {
                bit[idx] += delta;
            }
        };
        
        auto query = [&](int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx) {
                sum += bit[idx];
            }
            return sum;
        };
        
        
        long long totalSubarrays = 0;
        
        for (int j = 0; j <= n; j++) {
            int currentRank = getRank(pref[j]);
            
            
            totalSubarrays += query(currentRank - 1);
            

            update(currentRank, 1);
        }
        
        return totalSubarrays;
    }
};