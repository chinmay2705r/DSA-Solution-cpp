class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;
        
        // Split the string by '/'
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(token);
            }
        }
        
        // Reconstruct the canonical path
        string result = "";
        for (const string& dir : st) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};