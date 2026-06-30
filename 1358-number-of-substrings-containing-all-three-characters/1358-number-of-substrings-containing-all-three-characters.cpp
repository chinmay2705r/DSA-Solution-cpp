class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0);
        int left = 0;
        int result = 0;
        int n = s.length();
        
        for (int right = 0; right < n; ++right) {
            // Include the current character in the window
            count[s[right] - 'a']++;
            
            // While the window contains at least one 'a', 'b', and 'c'
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                // All substrings from 'right' to the end of the string are valid
                result += n - right;
                
                // Remove the left character and shrink the window
                count[s[left] - 'a']--;
                left++;
            }
        }
        
        return result;
    }
};