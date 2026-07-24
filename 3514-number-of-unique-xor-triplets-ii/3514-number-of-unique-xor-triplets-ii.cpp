class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> unique_nums(nums.begin(),nums.end());
        unordered_set<int> cur = {0};

        for(int i = 0; i < 3; ++i){
            unordered_set<int> next_set;
            for(int x : unique_nums){
                for(int val : cur){
                    next_set.insert(val ^ x);
                }    
            }
            cur = move(next_set);   
        }
        return cur.size();
    }
    
};