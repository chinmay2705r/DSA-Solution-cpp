class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // max_health[r][c] will store the maximum remaining health when reaching (r, c)
        vector<vector<int>> max_health(m, vector<int>(n, -1));
        
        // Priority Queue storing: {remaining_health, {r, c}}
        priority_queue<pair<int, pair<int, int>>> pq;
        
        // Starting cell cost calculation
        int start_health = health - grid[0][0];
        if (start_health <= 0) return false;
        
        pq.push({start_health, {0, 0}});
        max_health[0][0] = start_health;
        
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int curr_health = top.first;
            int r = top.second.first;
            int c = top.second.second;
            
            // If we reached the destination with positive health
            if (r == m - 1 && c == n - 1) {
                return true;
            }
            
            // Skip outdated states
            if (curr_health < max_health[r][c]) continue;
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_health = curr_health - grid[nr][nc];
                    
                    // Proceed only if we have health left and found a better path
                    if (next_health > 0 && next_health > max_health[nr][nc]) {
                        max_health[nr][nc] = next_health;
                        pq.push({next_health, {nr, nc}});
                    }
                }
            }
        }
        
        return false;
    }
};