class Solution{
public:
    bool isGood(vector<int>& nums) {
        int n = 0;
        for(int num : nums){
            n = max(n, num);
        }   
    
        if(nums.size() != n +1){
            return false;
        }
        sort(nums.begin(), nums.end());

        for(int i = 0; i<n -1; ++i){
            if(nums[i] != i+1){
                return false;
            }    
        }
        return nums[n-1] == n && nums[n] == n;
    }
};