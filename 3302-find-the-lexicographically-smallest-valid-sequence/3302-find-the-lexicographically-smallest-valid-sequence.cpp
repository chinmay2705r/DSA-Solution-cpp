class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last(m + 1, -1);
        last[m] = n;

        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; --i) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        vector<int> ans;
        bool changed = false;
        j = 0;

        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!changed && last[j + 1] > i) {
                ans.push_back(i);
                changed = true;
                j++;
            }
        }

        return (ans.size() == m) ? ans : vector<int>();
    }
};