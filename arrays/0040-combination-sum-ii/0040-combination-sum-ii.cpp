class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        
        sort(candidates.begin(), candidates.end());
        
        
        auto backtrack = [&](auto& self, int index, int remaining_target) -> void {
            
            if (remaining_target == 0) {
                result.push_back(current);
                return;
            }
            
            for (int i = index; i < candidates.size(); ++i) {
               
                if (candidates[i] > remaining_target) {
                    break;
                }
             
                if (i > index && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                
                current.push_back(candidates[i]);               // Choose
                self(self, i + 1, remaining_target - candidates[i]); 
                current.pop_back();                             
            }
        };
        
       
        backtrack(backtrack, 0, target);
        
        return result;
    }
};