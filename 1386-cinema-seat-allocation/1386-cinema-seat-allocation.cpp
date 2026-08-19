class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedBitmask;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                reservedBitmask[row] |= (1 << (col - 2));
            }
        }

        int totalGroups = (n - reservedBitmask.size()) * 2;

        for (const auto& [row, mask] : reservedBitmask) {
            bool leftFree   = (mask & 15) == 0;
            bool middleFree = (mask & 60) == 0; 
            bool rightFree  = (mask & 240) == 0;

            if (leftFree && rightFree) {
                totalGroups += 2;
            } else if (leftFree || rightFree || middleFree) {
                totalGroups += 1;
            }
        }

        return totalGroups;
    }
};