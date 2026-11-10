
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        using BusyServer = pair<long long, int>;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busy;

        vector<int> count(k, 0);
        int n = arrival.size();

        for (int i = 0; i < n; ++i) {
            long long time = arrival[i];

            while (!busy.empty() && busy.top().first <= time) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) continue;

            int target = i % k;
            auto it = available.lower_bound(target);
            if (it == available.end()) {
                it = available.begin();
            }

            int server_id = *it;
            count[server_id]++;
            busy.push({time + load[i], server_id});
            available.erase(it);
        }

        int max_req = *max_element(count.begin(), count.end());
        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            if (count[i] == max_req) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};