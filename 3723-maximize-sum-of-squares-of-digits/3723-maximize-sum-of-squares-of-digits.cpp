class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num){ 
            return "";
        }

        int count_9 = sum / 9;
        int rem = sum % 9;
        int count_0 = num - count_9 - (rem > 0 ? 1 : 0);

        if (count_0 < 0){ 
            return "";
        }

        string result = "";
        result.append(count_9, '9');
        if (rem > 0) {
            result.push_back('0' + rem);
        }
        result.append(count_0, '0');

        return result;
    }
};