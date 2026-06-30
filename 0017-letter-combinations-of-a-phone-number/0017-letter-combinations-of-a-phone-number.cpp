class Solution {
private:
    // Mapping of digits to telephone letters
    const vector<string> PHONE_MAP = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(int index, const string& digits, string& current, vector<string>& result) {
        // Base case: If the combination is complete
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the letters corresponding to the current digit
        string letters = PHONE_MAP[digits[index] - '0'];
        
        for (char letter : letters) {
            current.push_back(letter);             // Choose
            backtrack(index + 1, digits, current, result); // Explore
            current.pop_back();                    // Unchoose (Backtrack)
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        
        string current = "";
        backtrack(0, digits, current, result);
        return result;
    }
};