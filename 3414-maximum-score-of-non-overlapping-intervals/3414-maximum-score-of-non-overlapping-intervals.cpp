class Solution {
    struct Interval {
        int left, right, weight, original_idx;
    };

    struct State {
        long long score = 0;
        vector<int> indices;
        bool operator<(const State& other) const {
            if (score != other.score) return score < other.score;
            return indices > other.indices; 
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> A(n);
        
        for (int i = 0; i < n; ++i) {
            A[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(A.begin(), A.end(), [](const Interval& a, const Interval& b) {
            if (a.left != b.left) return a.left < b.left;
            return a.original_idx < b.original_idx;
        });

        vector<int> start_times(n);
        for (int i = 0; i < n; ++i) {
            start_times[i] = A[i].left;
        }

        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = n - 1; i >= 0; --i) {
            int next_idx = upper_bound(start_times.begin() + i + 1, start_times.end(), A[i].right) - start_times.begin();

            for (int k = 1; k <= 4; ++k) {
                State best = dp[i + 1][k];

                State take;
                take.score = A[i].weight + dp[next_idx][k - 1].score;
                take.indices = {A[i].original_idx};
                take.indices.insert(take.indices.end(), 
                                    dp[next_idx][k - 1].indices.begin(), 
                                    dp[next_idx][k - 1].indices.end());
                
                sort(take.indices.begin(), take.indices.end());

                if (best < take) {
                    best = take;
                }

                dp[i][k] = best;
            }
        }

        return dp[0][4].indices;
    }
};