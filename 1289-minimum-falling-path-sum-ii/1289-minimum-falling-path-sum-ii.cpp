class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
       
        int min1 = 0, min1_col = -1, min2 = 0;
        
        for (int r = 0; r < n; ++r) {
            int next_min1 = INT_MAX, next_min1_col = -1, next_min2 = INT_MAX;
            
            for (int c = 0; c < n; ++c) {
                
                int prev_min = (c == min1_col) ? min2 : min1;
                int current_sum = grid[r][c] + prev_min;
                
               
                if (current_sum < next_min1) {
                    next_min2 = next_min1;
                    next_min1 = current_sum;
                    next_min1_col = c;
                } else if (current_sum < next_min2) {
                    next_min2 = current_sum;
                }
            }
            
            
            min1 = next_min1;
            min1_col = next_min1_col;
            min2 = next_min2;
        }
        
        return min1;
    }
};