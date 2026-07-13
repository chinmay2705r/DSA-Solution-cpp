class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;
        
        // 1. Precompute powers of 10 modulo MOD
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        // 2. Extract non-zero digits and build prefix structures
        vector<int> digits;
        vector<long long> prefix_sum = {0};
        vector<long long> prefix_val = {0};
        
        long long current_val = 0;
        long long current_sum = 0;
        
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                int d = s[i] - '0';
                digits.push_back(d);
                
                current_sum += d;
                prefix_sum.push_back(current_sum);
                
                current_val = (current_val * 10 + d) % MOD;
                prefix_val.push_back(current_val);
            }
        }
        
        int num_nonzero = digits.size();
        
        vector<int> next_nonzero(m, num_nonzero);
        vector<int> prev_nonzero(m, -1);
        
        int last_idx = -1;
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') last_idx++;
            prev_nonzero[i] = last_idx;
        }
        
        int next_idx = num_nonzero;
        for (int i = m - 1; i >= 0; --i) {
            if (s[i] != '0') next_idx--;
            next_nonzero[i] = next_idx;
        }

        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            
            int L = next_nonzero[l];
            int R = prev_nonzero[r];
          
            if (L > R) {
                answer.push_back(0);
                continue;
            }
            
            long long digit_sum = prefix_sum[R + 1] - prefix_sum[L];
         
            long long len = R - L + 1;
            long long x = (prefix_val[R + 1] - (prefix_val[L] * pow10[len]) % MOD + MOD) % MOD;
            
            long long query_ans = (x * digit_sum) % MOD;
            answer.push_back(query_ans);
        }
        
        return answer;
    }
};