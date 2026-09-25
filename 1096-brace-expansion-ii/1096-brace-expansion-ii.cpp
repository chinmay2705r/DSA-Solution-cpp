class Solution {
private:
    unordered_set<string> parse(const string& expr, int& i) {
        vector<unordered_set<string>> groups;
        unordered_set<string> current_concat = {""};

        while (i < expr.length() && expr[i] != '}') {
            if (expr[i] == ',') {
                groups.push_back(current_concat);
                current_concat = {""};
                i++;
            } else if (expr[i] == '{') {
                i++; 
                unordered_set<string> next_set = parse(expr, i);
                i++; 
                unordered_set<string> new_concat;
                for (const string& a : current_concat) {
                    for (const string& b : next_set) {
                        new_concat.insert(a + b);
                    }
                }
                current_concat = move(new_concat);
            } else { 
                string s(1, expr[i]);
                unordered_set<string> new_concat;
                for (const string& a : current_concat) {
                    new_concat.insert(a + s);
                }
                current_concat = move(new_concat);
                i++;
            }
        }

        groups.push_back(current_concat);
        unordered_set<string> result;
        for (const auto& group : groups) {
            result.insert(group.begin(), group.end());
        }

        return result;
    }

public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        unordered_set<string> resultSet = parse(expression, i);

        set<string> sortedSet(resultSet.begin(), resultSet.end());
        return vector<string>(sortedSet.begin(), sortedSet.end());
    }
};