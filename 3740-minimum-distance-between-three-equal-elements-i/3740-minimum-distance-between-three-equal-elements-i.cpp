class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].push_back(i);
        }

        int min_dist = INT_MAX;

        for (const auto& [num, indices] : pos) {
            if (indices.size() >= 3) {
                for (int p = 0; p + 2 < indices.size(); ++p) {
                    int dist = 2 * (indices[p + 2] - indices[p]);
                    min_dist = min(min_dist, dist);
                }
            }
        }

        return (min_dist == INT_MAX) ? -1 : min_dist;
    }
};