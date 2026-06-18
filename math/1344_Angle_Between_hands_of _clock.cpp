// Problem 1344 : Angle Between Hands of clock
// Leetcode: https://leetcode.com/problems/angle-between-hands-of-a-clock/
// Difficulty : Hard

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double minuteAngle = minutes * 6.0;
        double hourAngle = (hour % 12)* 30.0 +  minutes * 0.5;
         double angle  = abs(hourAngle - minuteAngle);
        return min(angle, 360.0 - angle);
        
    }
};