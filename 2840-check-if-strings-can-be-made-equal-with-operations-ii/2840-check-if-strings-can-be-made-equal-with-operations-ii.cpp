class Solution {
public:
    bool checkStrings(string s1, string s2) {
        
        vector<vector<int>> count(2, vector<int>(26, 0));

        int n = s1.length();

        for (int i = 0; i < n; ++i) {
            int parity = i % 2;
            count[parity][s1[i] - 'a']++;
            count[parity][s2[i] - 'a']--;
        }

        for (int parity = 0; parity < 2; ++parity) {
            for (int ch = 0; ch < 26; ++ch) {
                if (count[parity][ch] != 0) {
                    return false;
                }
            }
        }

        return true;
    }
};