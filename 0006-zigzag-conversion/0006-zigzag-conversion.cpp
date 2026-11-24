class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);
        int curr_row = 0;
        bool going_down = false;

        for (char c : s) {
            rows[curr_row] += c;
            if (curr_row == 0 || curr_row == numRows - 1) {
                going_down = !going_down;
            }

            curr_row += going_down ? 1 : -1;
        }

        string ans;
        ans.reserve(s.length());
        for (const string& row : rows) {
            ans += row;
        }

        return ans;
    }
};