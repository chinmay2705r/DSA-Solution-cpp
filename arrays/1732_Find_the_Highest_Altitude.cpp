// Promblem 1732 : Find the Highest Altitude
//Leetcode : https://leetcode.com/problems/find-the-highest-altitude
// Difficulty : Medium 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int highestAltitude = 0;

        for (int i = 0; i < gain.size(); i++) {
            int netchange = gain[i];
            
            currentAltitude = currentAltitude + netchange;
            if (currentAltitude > highestAltitude) {
                highestAltitude = currentAltitude;
            }
        }
        return highestAltitude;
    }
};

int main() {
    Solution s;
    int n;

    cout << "Enter the number of altitude changes (size of array): ";
    cin >> n;

    vector<int> userGain(n);
    cout << "Enter the " << n << " altitude changes separated by spaces: ";
    for (int i = 0; i < n; i++) {
        cin >> userGain[i];
    }

    int result = s.largestAltitude(userGain);
    
    cout << "The highest altitude reached is: " << result << endl;

    return 0;
}
