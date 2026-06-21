// Problem 1840 : Maximum Building height 
// Leetcode : https://leetcode.com/problems/maximum-building-height/
// Difficulty : Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
       
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // 2. Left-to-Right Scan (Cap acceleration from start)
        for (int i = 1; i < m; i++) {
            int width = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + width);
        }
        for (int i = m - 2; i >= 0; i--) {
            int width = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + width);
        }
        int maxHeight = 0;
        for (int i = 0; i < m - 1; i++) {
            int x1 = restrictions[i][0], h1 = restrictions[i][1];
            int x2 = restrictions[i + 1][0], h2 = restrictions[i + 1][1];
            
            int midPeak = (h1 + h2 + (x2 - x1)) / 2;
            maxHeight = max(maxHeight, midPeak);
        }
        int lastIdx = restrictions.back()[0];
        int lastHeight = restrictions.back()[1];
        maxHeight = max(maxHeight, lastHeight + (n - lastIdx));
        
        return maxHeight;
    }
};