class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int length = 0;
        bool has_odd = false;

        for (auto& [ch, count] : freq) {
            if (count % 2 == 0) {
                length += count;
            } else {
                length += count - 1;
                has_odd = true; 
            }
        }

        if (has_odd) {
            length += 1;
        }

        return length;
    }
};