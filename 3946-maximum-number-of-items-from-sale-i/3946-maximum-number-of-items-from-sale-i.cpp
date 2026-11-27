
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        const int MAX_F = 1500;

        vector<int> freq(MAX_F + 1, 0);
        int min_price = 1e9;
        for (const auto& item : items) {
            freq[item[0]]++;
            min_price = min(min_price, item[1]);
        }
        vector<int> divisible_count(MAX_F + 1, 0);
        for (int f = 1; f <= MAX_F; ++f) {
            if (freq[f] == 0) continue;
            for (int multiple = f; multiple <= MAX_F; multiple += f) {
                divisible_count[f] += freq[multiple];
            }
        }
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;

        for (const auto& item : items) {
            int f = item[0];
            int p = item[1];
            int first_copy_gain = divisible_count[f];

            for (int c = budget; c >= p; --c) {
                if (dp[c - p] != -1) {
                    dp[c] = max(dp[c], dp[c - p] + first_copy_gain);
                }
            }
        }
        int max_items = 0;
        for (int c = 0; c <= budget; ++c) {
            if (dp[c] != -1) {
                int extra_copies = (budget - c) / min_price;
                max_items = max(max_items, dp[c] + extra_copies);
            }
        }

        return max_items;
    }
};