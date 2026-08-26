class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> pos;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }

        if (pos.size() < k) return "";

        string ans = "";
        int minLen = s.length() + 1;

        for (int i = 0; i <= (int)pos.size() - k; ++i) {
            int left = pos[i];
            int right = pos[i + k - 1];
            int currentLen = right - left + 1;

            string candidate = s.substr(left, currentLen);

            if (currentLen < minLen) {
                minLen = currentLen;
                ans = candidate;
            } else if (currentLen == minLen) {
                if (candidate < ans) {
                    ans = candidate;
                }
            }
        }

        return ans;
    }
};