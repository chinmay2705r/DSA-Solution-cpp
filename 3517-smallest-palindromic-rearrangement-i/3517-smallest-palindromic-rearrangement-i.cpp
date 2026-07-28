class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int half = n/2;

        string left = s.substr(0, half);
        sort(left.begin(),left.end());

        string right = left;
        reverse(right.begin(), right.end());

        if(n % 2 == 1){
            return left + s[half] + right ;
        }
        return left + right;
    }
};