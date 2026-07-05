class Solution {
private:
    void backtrack(int i, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (i >= candidates.size() || target < 0) {
            return;
        }

        current.push_back(candidates[i]);
        backtrack(i, target - candidates[i], candidates, current, result);
        current.pop_back(); 
        backtrack(i + 1, target, candidates, current, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        
        backtrack(0, target, candidates, current, result);
        return result;
    }
};