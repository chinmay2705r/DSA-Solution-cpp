class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; ++i) {
            int charIdx = s[i] - 'a';
            if (first[charIdx] == -1) first[charIdx] = i;
            last[charIdx] = i;
        }

        vector<pair<int, int>> valid_intervals;
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            int l = first[i];
            int r = last[i];
            bool valid = true;

            for (int j = l; j <= r; ++j) {
                int charIdx = s[j] - 'a';
                if (first[charIdx] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[charIdx]);
            }

            if (valid) {
                valid_intervals.push_back({r, l});
            }
        }

        sort(valid_intervals.begin(), valid_intervals.end());

        vector<string> result;
        int prev_end = -1;

        for (const auto& [end, start] : valid_intervals) {
            if (start > prev_end) {
                result.push_back(s.substr(start, end - start + 1));
                prev_end = end;
            }
        }

        return result;
    }
};