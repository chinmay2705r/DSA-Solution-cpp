class Solution {
private:
    long long dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 0;
        }

        long long sum = grid[r][c];
        grid[r][c] = 0;

        sum += dfs(grid, r + 1, c, rows, cols);
        sum += dfs(grid, r - 1, c, rows, cols);
        sum += dfs(grid, r, c + 1, rows, cols);
        sum += dfs(grid, r, c - 1, rows, cols);

        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int divisible_islands_count = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] > 0) {
                    long long island_sum = dfs(grid, r, c, rows, cols);
                    if (island_sum % k == 0) {
                        divisible_islands_count++;
                    }
                }
            }
        }

        return divisible_islands_count;
    }
};