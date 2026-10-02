class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        auto backtrack = [&](auto& self, string current, int open, int close) -> void {
            if (current.length() == 2 * n) {
                result.push_back(current);
                return;
            }

            if (open < n) {
                self(self, current + "(", open + 1, close);
            }
            if (close < open) {
                self(self, current + ")", open, close + 1);
            }
        };

        backtrack(backtrack, "", 0, 0);
        return result;
    }
};