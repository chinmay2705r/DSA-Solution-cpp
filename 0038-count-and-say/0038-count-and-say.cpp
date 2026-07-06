class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        // Generate the sequence iteratively up to n
        for (int i = 2; i <= n; ++i) {
            string next_str = "";
            int count = 1;
            
            for (int j = 0; j < result.length(); ++j) {
                
                if (j + 1 < result.length() && result[j] == result[j + 1]) {
                    count++;
                } else {
                  
                    next_str += to_string(count) + result[j];
                    count = 1;
                }
            }
            result = next_str;
        }
        
        return result;
    }
};