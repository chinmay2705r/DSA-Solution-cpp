class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort: ascending by start point; if tied, descending by end point
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int covered_count = 0;
        int max_end = 0;
        
        for (const auto& interval : intervals) {
            // If the current interval's end fits within the max_end seen so far, it's covered
            if (interval[1] <= max_end) {
                covered_count++;
            } else {
                // Update the boundary for tracking subsequent intervals
                max_end = interval[1];
            }
        }
        
        return intervals.size() - covered_count;
    }
};