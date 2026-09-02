class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        auto encode = [](int x, int y) -> long long {
            return ((long long)x << 32) | (unsigned int)y;
        };

        unordered_set<long long> obstacleSet;
        obstacleSet.reserve(obstacles.size());
        for (const auto& obs : obstacles) {
            obstacleSet.insert(encode(obs[0], obs[1]));
        }

        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        
        int dir = 0;
        int x = 0, y = 0;
        int maxDistSq = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
              
                dir = (dir + 1) & 3;
            } else if (cmd == -2) {
                
                dir = (dir + 3) & 3;
            } else {

                for (int step = 0; step < cmd; ++step) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (obstacleSet.count(encode(nx, ny))) {
                        break; 
                    }

                    x = nx;
                    y = ny;
                    maxDistSq = max(maxDistSq, x * x + y * y);
                }
            }
        }

        return maxDistSq;
    }
};