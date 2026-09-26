#include <string>
#include <vector>
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> kv_map;
        for (const auto& pair : knowledge) {
            kv_map[pair[0]] = pair[1];
        }

        string result = "";
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                string key = "";
                i++; 
                while (i < n && s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if (kv_map.count(key)) {
                    result += kv_map[key];
                } else {
                    result += '?';
                }
            } else {
                result += s[i];
            }
        }

        return result;
    }
};