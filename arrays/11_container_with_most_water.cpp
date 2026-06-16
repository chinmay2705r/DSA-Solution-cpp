// Problem 11 : Container With Most Water
// Leetcode : https://leetcode.com/problems/container-with-most-water/
// Difficulty : Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int currentHeight = min(height[left], height[right]);
            int currentWidth = right - left;
            int currentWater = currentHeight * currentWidth;
            
            maxWater = max(maxWater, currentWater);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};