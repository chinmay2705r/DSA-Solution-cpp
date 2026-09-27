class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> st;

        for (char c : s) {
            if (c == ')') {
                string temp = "";
                while (!st.empty() && st.back() != '(') {
                    temp += st.back();
                    st.pop_back();
                }
                if (!st.empty()) st.pop_back();

                for (char ch : temp) {
                    st.push_back(ch);
                }
            } else {
                st.push_back(c);
            }
        }

        return string(st.begin(), st.end());
    }
};