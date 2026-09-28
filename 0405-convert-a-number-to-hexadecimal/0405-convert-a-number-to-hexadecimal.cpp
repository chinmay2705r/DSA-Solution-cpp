#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int n = num;
        string hexChars = "0123456789abcdef";
        string result = "";

        while (n > 0) {
            result += hexChars[n & 0xF]; 
            n >>= 4;                     
        }

        reverse(result.begin(), result.end());
        return result;
    }
};