
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<vector<bool>>> visited(
            rows, vector<vector<bool>>(cols, vector<bool>(1024, false))
        );

        queue<tuple<int, int, int>> q;

        int start_val = grid[0][0];
        visited[0][0][start_val] = true;
        q.push({0, 0, start_val});

        while (!q.empty()) {
            auto [r, c, curr_xor] = q.front();
            q.pop();

            if (r + 1 < rows) {
                int next_xor = curr_xor ^ grid[r + 1][c];
                if (!visited[r + 1][c][next_xor]) {
                    visited[r + 1][c][next_xor] = true;
                    q.push({r + 1, c, next_xor});
                }
            }

            if (c + 1 < cols) {
                int next_xor = curr_xor ^ grid[r][c + 1];
                if (!visited[r][c + 1][next_xor]) {
                    visited[r][c + 1][next_xor] = true;
                    q.push({r, c + 1, next_xor});
                }
            }
        }

        for (int x = 0; x < 1024; ++x) {
            if (visited[rows - 1][cols - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};