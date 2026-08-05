class Solution {
private:
    int rows, cols;
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(int r, int c, int parentR, int parentC, char charVal,
             vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[r][c] = true;

        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == charVal) {

                if (nr == parentR && nc == parentC) {
                    continue;
                }

                if (visited[nr][nc]) {
                    return true;
                }

                if (dfs(nr, nc, r, c, charVal, grid, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (!visited[r][c]) {
                    if (dfs(r, c, -1, -1, grid[r][c], grid, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};