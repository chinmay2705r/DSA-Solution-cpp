class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = n; 
        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int absDiff = abs(i - startIndex);
                int circularDist = min(absDiff, n - absDiff);
                minDistance = min(minDistance, circularDist);
            }
        }

        return (minDistance == n) ? -1 : minDistance;
    }
};