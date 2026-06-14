// Problem : Longest Substring Without Repeating Characters
// Difficulty : Medium 
// Leetcode : https://leetcode.com/problems/longest-substring-without-repeating-characters

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> charIndex(128, -1);
        
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
        
            if (charIndex[currentChar] >= left) {
                left = charIndex[currentChar] + 1;
            }
        
            charIndex[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
