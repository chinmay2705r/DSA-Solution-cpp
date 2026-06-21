// Problem 1833: Maximum Ice Cream bars
//Leetcode : https://leetcode.com/problems/maximum-ice-cream-bars
// difficulty : Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
    
        sort(costs.begin(), costs.end());
        
        int count = 0;
        
       
        for (int i = 0; i < costs.size(); i++) {
            if (coins >= costs[i]) {
                coins -= costs[i]; 
                count++;
            } else {
                
                break;
            }
        }
        
        return count;
    }
};