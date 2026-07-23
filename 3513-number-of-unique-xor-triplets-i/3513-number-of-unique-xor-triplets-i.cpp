class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 1;
        if(n == 2) return 2;

        int pot = 1;
        while(pot <= n){
            pot <<=1;
        }   
        return pot;
    }
};