class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); ++i) {
            int rev_alphabet_val = 'z' - s[i] + 1;
            int string_idx = i + 1;
            total += rev_alphabet_val * string_idx;
        }
        return total;
    }
};