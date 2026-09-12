class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> posMap;

        for (int i = 0; i < n; ++i) {
            posMap[nums[i]].push_back(i);
        }

        auto getCircularDist = [n](int i, int j) {
            int diff = abs(i - j);
            return min(diff, n - diff);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (int q : queries) {
            int val = nums[q];
            const auto& list = posMap[val];

            if (list.size() <= 1) {
                ans.push_back(-1);
                continue;
            }
            auto it = lower_bound(list.begin(), list.end(), q);
            int idx = distance(list.begin(), it);
            int m = list.size();

            int prevIdx = (idx - 1 + m) % m;
            int nextIdx = (idx + 1) % m;

            int d1 = getCircularDist(q, list[prevIdx]);
            int d2 = getCircularDist(q, list[nextIdx]);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};