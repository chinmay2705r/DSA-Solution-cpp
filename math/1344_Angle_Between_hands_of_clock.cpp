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

int main(){
    Solution sol;
    int hour, minutes;

    cout << "Enter Hours(1-12):";
    cin>> hour;
    cout <<"Eneter Minutes(0-59):";
    cin >> minutes;

    double Result = sol.angleClock(hour, minutes);
    cout <<" The angle between the clock is "<< Result<< endl;

    return 0;

}