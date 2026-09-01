class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    startX = r;
                    startY = c;
                } else if (classroom[r][c] == 'L') {
                    litters.push_back({r, c});
                }
            }
        }

        int numLitter = litters.size();
        int fullMask = (1 << numLitter) - 1;

        if (fullMask == 0) return 0; 

        auto getLitterIndex = [&](int r, int c) {
            for (int i = 0; i < numLitter; ++i) {
                if (litters[i].first == r && litters[i].second == c) return i;
            }
            return -1;
        };

        queue<tuple<int, int, int, int>> q;
        
        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << numLitter, -1)));

        
        int initialMask = 0;
        int initIdx = getLitterIndex(startX, startY);
        if (initIdx != -1) {
            initialMask |= (1 << initIdx);
        }

        q.push({startX, startY, initialMask, energy});
        bestEnergy[startX][startY][initialMask] = energy;

        int moves = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == fullMask) return moves;
                if (e == 0) continue; 

                for (auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                        int nextMask = mask;
                        if (classroom[nr][nc] == 'L') {
                            int idx = getLitterIndex(nr, nc);
                            if (idx != -1) nextMask |= (1 << idx);
                        }

                        int nextEnergy = e - 1;
                        if (classroom[nr][nc] == 'R') {
                            nextEnergy = energy;
                        }

                        if (nextEnergy > bestEnergy[nr][nc][nextMask]) {
                            bestEnergy[nr][nc][nextMask] = nextEnergy;
                            q.push({nr, nc, nextMask, nextEnergy});
                        }
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};