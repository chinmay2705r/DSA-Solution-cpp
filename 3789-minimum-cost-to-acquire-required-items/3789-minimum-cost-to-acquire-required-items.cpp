
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;

        long long shared = min(n1, n2);
        long long rem1 = n1 - shared;
        long long rem2 = n2 - shared;
        long long option1 = shared * cb + rem1 * min(c1, cb) + rem2 * min(c2, cb);

        long long option2 = n1 * min(c1, cb) + n2 * min(c2, cb);

        long long option3 = max(n1, n2) * cb;

        return min({option1, option2, option3});
    }
};