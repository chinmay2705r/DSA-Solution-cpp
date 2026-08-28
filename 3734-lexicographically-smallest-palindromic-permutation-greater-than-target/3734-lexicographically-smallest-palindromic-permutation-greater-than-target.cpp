class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int oddCount = 0;
        char midChar = 0;
        for (int c = 0; c < 26; ++c) {
            if (count[c] % 2 != 0) {
                oddCount++;
                midChar = 'a' + c;
            }
        }

        if (oddCount > 1) return "";

        vector<int> halfCount(26, 0);
        for (int c = 0; c < 26; ++c) {
            halfCount[c] = count[c] / 2;
        }

        int m = n / 2;

        auto buildPalindrome = [&](const string& half) {
            string full = half;
            if (n % 2 != 0) full += midChar;
            string rev = half;
            reverse(rev.begin(), rev.end());
            full += rev;
            return full;
        };

        vector<int> exactFreq = halfCount;
        bool canMatch = true;
        string exactHalf = "";
        for (int i = 0; i < m; ++i) {
            int c = target[i] - 'a';
            if (exactFreq[c] > 0) {
                exactFreq[c]--;
                exactHalf += target[i];
            } else {
                canMatch = false;
                break;
            }
        }

        if (canMatch) {
            string candidate = buildPalindrome(exactHalf);
            if (candidate > target) return candidate;
        }

        for (int i = m - 1; i >= 0; --i) {
 
            vector<int> freq = halfCount;
            bool possible = true;
            for (int j = 0; j < i; ++j) {
                int c = target[j] - 'a';
                if (freq[c] > 0) {
                    freq[c]--;
                } else {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;

            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (freq[c] > 0) {
                    string half = target.substr(0, i);
                    half += (char)('a' + c);
                    freq[c]--;

                    for (int r = 0; r < 26; ++r) {
                        while (freq[r] > 0) {
                            half += (char)('a' + r);
                            freq[r]--;
                        }
                    }

                    string candidate = buildPalindrome(half);
                    if (candidate > target) return candidate;
                }
            }
        }

        return "";
    }
};