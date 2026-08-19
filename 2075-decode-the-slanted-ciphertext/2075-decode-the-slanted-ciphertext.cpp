class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.length();
        int cols = n / rows;
        string result = "";

        for (int c0 = 0; c0 < cols; ++c0) {
            int r = 0, c = c0;

            while (r < rows && c < cols) {
                result += encodedText[r * cols + c];
                r++;
                c++;
            }
        }
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};