class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        
        auto dfs = [&](auto& self, int r, int c, int index) -> bool {
            
            if (index == word.length()) {
                return true;
            }
            
           
            if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[index]) {
                return false;
            }
            
            char temp = board[r][c];
            board[r][c] = '#';
            
           
            bool found = self(self, r + 1, c, index + 1) || // Down
                         self(self, r - 1, c, index + 1) || // Up
                         self(self, r, c + 1, index + 1) || // Right
                         self(self, r, c - 1, index + 1);   // Left
            
            board[r][c] = temp;
            
            return found;
        };
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == word[0] && dfs(dfs, r, c, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};