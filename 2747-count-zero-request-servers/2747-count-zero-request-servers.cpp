#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        
        vector<pair<int, int>> sorted_queries(m);
        for (int i = 0; i < m; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        
        sort(sorted_queries.begin(), sorted_queries.end());
        
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> ans(m);
        vector<int> server_cnt(n + 1, 0);
        int active_servers = 0;
        int left = 0, right = 0;
        int log_cnt = logs.size();

        for (const auto& [q_time, q_idx] : sorted_queries) {
            int win_start = q_time - x;

            while (right < log_cnt && logs[right][1] <= q_time) {
                int server = logs[right][0];
                if (server_cnt[server] == 0) {
                    active_servers++;
                }
                server_cnt[server]++;
                right++;
            }
            while (left < log_cnt && logs[left][1] < win_start) {
                int server = logs[left][0];
                server_cnt[server]--;
                if (server_cnt[server] == 0) {
                    active_servers--;
                }
                left++;
            }
            ans[q_idx] = n - active_servers;
        }

        return ans;
    }
};