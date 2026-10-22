class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int pos0 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                pos0 = i;
                break;
            }
        }
        bool is_type0 = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(pos0 + i) % n] != i) {
                is_type0 = false;
                break;
            }
        }
        bool is_type1 = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(pos0 - i + n) % n] != i) {
                is_type1 = false;
                break;
            }
        }

        if (!is_type0 && !is_type1) {
            return -1;
        }
        int start_type = is_type0 ? 0 : 1;
        int start_shift = pos0;

        vector<vector<int>> dist(2, vector<int>(n, -1));
        queue<pair<int, int>> q;

        q.push({start_type, start_shift});
        dist[start_type][start_shift] = 0;

        while (!q.empty()) {
            auto [t, s] = q.front();
            q.pop();

            if (t == 0 && s == 0) {
                return dist[t][s];
            }

            int next_s = (s - 1 + n) % n;
            if (dist[t][next_s] == -1) {
                dist[t][next_s] = dist[t][s] + 1;
                q.push({t, next_s});
            }

            int rev_t = 1 - t;
            int rev_s = (n - 1 - s) % n;
            if (dist[rev_t][rev_s] == -1) {
                dist[rev_t][rev_s] = dist[t][s] + 1;
                q.push({rev_t, rev_s});
            }
        }

        return -1;
    }
};