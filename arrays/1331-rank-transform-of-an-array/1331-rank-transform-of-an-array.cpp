class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        
        unordered_map<int, int> ranks;
        int current_rank = 1;
        
        for (int num : sorted_arr) {
            if (ranks.find(num) == ranks.end()) {
                ranks[num] = current_rank;
                current_rank++;
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = ranks[arr[i]];
        }
        
        return arr;
    }
};