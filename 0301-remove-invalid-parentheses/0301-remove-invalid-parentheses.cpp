class Solution {
private:
    unordered_set<string> valid_strings;

    void dfs(int index, int open_count, int close_count, int rem_open, int rem_close, string& current, const string& s) {
        if (index == s.length()) {
            if (rem_open == 0 && rem_close == 0 && open_count == close_count) {
                valid_strings.insert(current);
            }
            return;
        }

        char c = s[index];
        if (c == '(' && rem_open > 0) {
            dfs(index + 1, open_count, close_count, rem_open - 1, rem_close, current, s);
        } else if (c == ')' && rem_close > 0) {
            dfs(index + 1, open_count, close_count, rem_open, rem_close - 1, current, s);
        }

        current.push_back(c);
        if (c != '(' && c != ')') {
            dfs(index + 1, open_count, close_count, rem_open, rem_close, current, s);
        } else if (c == '(') {
            dfs(index + 1, open_count + 1, close_count, rem_open, rem_close, current, s);
        } else if (c == ')' && open_count > close_count) {
            dfs(index + 1, open_count, close_count + 1, rem_open, rem_close, current, s);
        }
        current.pop_back();
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int rem_open = 0, rem_close = 0;

        for (char c : s) {
            if (c == '(') {
                rem_open++;
            } else if (c == ')') {
                if (rem_open > 0) rem_open--;
                else rem_close++;
            }
        }

        string current = "";
        dfs(0, 0, 0, rem_open, rem_close, current, s);

        return vector<string>(valid_strings.begin(), valid_strings.end());
    }
};