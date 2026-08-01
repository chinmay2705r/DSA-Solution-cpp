class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != 0 && i > 0) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
            vector<int> row = matrix[i];
            sort(row.rbegin(), row.rend());

            for (int k = 0; k < n; ++k) {
                maxArea = max(maxArea, row[k] * (k + 1));
            }
        }

        return maxArea;
    }
};