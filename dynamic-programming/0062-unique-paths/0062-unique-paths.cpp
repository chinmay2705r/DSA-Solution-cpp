class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 1D DP table to track row path counts
        vector<int> row(n, 1);
        
        // Loop through the rest of the rows
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                // The new value is the sum of the left cell (row[c-1]) 
                // and the top cell (previous row[c])
                row[c] += row[c - 1];
            }
        }
        
        return row[n - 1];
    }
};