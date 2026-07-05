class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        vector<vector<int>> dp_score(n, vector<int>(n, 0));
        vector<vector<int>> dp_paths(n, vector<int>(n, 0));
        
        board[0][0] = '0';
        board[n - 1][n - 1] = '0';
        
        dp_paths[n - 1][n - 1] = 1;
        

        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (board[r][c] == 'X' || dp_paths[r][c] == 0) continue;
            
                int next_dirs[3][2] = {{-1, 0}, {0, -1}, {-1, -1}};
                
                for (auto& dir : next_dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    
                    if (nr >= 0 && nc >= 0 && board[nr][nc] != 'X') {
                        int current_cell_score = board[nr][nc] - '0';
                        int potential_score = dp_score[r][c] + current_cell_score;
                        
                        if (potential_score > dp_score[nr][nc]) {
                            
                            dp_score[nr][nc] = potential_score;
                            dp_paths[nr][nc] = dp_paths[r][c];
                        } else if (potential_score == dp_score[nr][nc]) {
                           
                            dp_paths[nr][nc] = (dp_paths[nr][nc] + dp_paths[r][c]) % MOD;
                        }
                    }
                }
            }
        }
        
        return {dp_score[0][0], dp_paths[0][0]};
    }
};