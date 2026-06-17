//Problem 1365 : How many number are smaller than current number
// leetcode : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
//Difficulty : Easy 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int count[101] = {0};
        for (int num : nums) {
            count[num]++;
        }
        
        int runningSum = 0;
        for (int i = 0; i <= 100; i++) {
            int temp = count[i];
            count[i] = runningSum;
            runningSum += temp;
        }
        
     
        vector<int> result;
        for (int num : nums) {
            result.push_back(count[num]);
        }
        
        return result;
    }
};