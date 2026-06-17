// Problem 169 : Majority Element
// Leetcode : https://leetcode.com/problems/majority-element/
// Difficulty : Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major_num = 0;
        int count = 0;
        
        for (int num : nums) {
            // If count falls to 0, pick the current number as the new candidate
            if (count == 0) {
                major_num = num;
            }
            
            // Increment count if it matches the candidate, otherwise decrement
            count += (num == major_num) ? 1 : -1;
        }
        
        return major_num;
    }
};