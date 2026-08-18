class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> stones(n);

        for (int i = 0; i < n; ++i) {
            stones[i] = {aliceValues[i] + bobValues[i], i};
        }
        sort(stones.rbegin(), stones.rend());

        int aliceScore = 0;
        int bobScore = 0;

        for (int i = 0; i < n; ++i) {
            int idx = stones[i].second;
            if (i % 2 == 0) {
                aliceScore += aliceValues[idx];
            } else {
                bobScore += bobValues[idx];
            }
        }

        if (aliceScore > bobScore) return 1;
        if (bobScore > aliceScore) return -1;
        return 0;
    }
};