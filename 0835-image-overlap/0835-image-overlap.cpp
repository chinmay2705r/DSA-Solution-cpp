class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.push_back({r, c});
                if (img2[r][c] == 1) ones2.push_back({r, c});
            }
        }
        unordered_map<int, int> shiftCounts;
        int maxOverlap = 0;

        for (auto& [r1, c1] : ones1) {
            for (auto& [r2, c2] : ones2) {
                int dx = r2 - r1;
                int dy = c2 - c1;
                int key = (dx + 100) * 1000 + (dy + 100);
                
                maxOverlap = max(maxOverlap, ++shiftCounts[key]);
            }
        }

        return maxOverlap;
    }
};