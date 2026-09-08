class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long> last(26, 0);
        long long MOD = 1e9 + 7;

        for (char ch : s) {
            int idx = ch - 'a';
            
            long long total_so_far = 0;
            for (int count : last) {
                total_so_far = (total_so_far + count) % MOD;
            }

            last[idx] = (total_so_far + 1) % MOD;
        }

        long long total_distinct = 0;
        for (int count : last) {
            total_distinct = (total_distinct + count) % MOD;
        }

        return total_distinct;
    }
};