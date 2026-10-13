class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);

        for (int i = 0; i < n; ++i) {
            squares[i] = 1LL * nums[i] * nums[i];
        }

        sort(squares.begin(), squares.end());

        long long total_score = 0;
        int neg_count = n / 2; 
        for (int i = 0; i < neg_count; ++i) {
            total_score -= squares[i];
        }
        for (int i = neg_count; i < n; ++i) {
            total_score += squares[i];
        }

        return total_score;
    }
};