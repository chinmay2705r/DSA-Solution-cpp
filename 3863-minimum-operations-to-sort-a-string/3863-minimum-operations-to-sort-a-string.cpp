class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        bool mx_only_at_start = (s[0] == mx);
        for (int i = 1; i < n; ++i) {
            if (s[i] == mx) {
                mx_only_at_start = false;
                break;
            }
        }

        bool mn_only_at_end = (s[n - 1] == mn);
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == mn) {
                mn_only_at_end = false;
                break;
            }
        }

        if (mx_only_at_start && mn_only_at_end) {
            return 3;
        }

        return 2;
    }
};