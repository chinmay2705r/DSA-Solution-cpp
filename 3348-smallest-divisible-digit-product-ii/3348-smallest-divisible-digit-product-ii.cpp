class Solution {
public:
    array<array<int,4>,10> digitExp;

    int A, B, C, D;
    int a_, b_, c_, d_;
    vector<int> minLen;   
    static const int INF = INT32_MAX / 2;

    inline int idx(int i, int j, int k, int l) const {
        return ((i * B + j) * C + k) * D + l;
    }

    string smallestNumber(string num, long long t) {
        digitExp[1] = {0,0,0,0};
        digitExp[2] = {1,0,0,0};
        digitExp[3] = {0,1,0,0};
        digitExp[4] = {2,0,0,0};
        digitExp[5] = {0,0,1,0};
        digitExp[6] = {1,1,0,0};
        digitExp[7] = {0,0,0,1};
        digitExp[8] = {3,0,0,0};
        digitExp[9] = {0,2,0,0};

        long long tt = t;
        int a = 0, b = 0, c = 0, d = 0;
        while (tt % 2 == 0) { tt /= 2; a++; }
        while (tt % 3 == 0) { tt /= 3; b++; }
        while (tt % 5 == 0) { tt /= 5; c++; }
        while (tt % 7 == 0) { tt /= 7; d++; }
        if (tt != 1) return "-1";

        a_ = a; b_ = b; c_ = c; d_ = d;
        A = a + 1; B = b + 1; C = c + 1; D = d + 1;
        long long sizeL = (long long)A * B * C * D;
        minLen.assign((size_t)sizeL, INF);

        int maxSum = a + b + c + d;
        vector<vector<array<int,4>>> buckets(maxSum + 1);
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                for (int k = 0; k < C; k++)
                    for (int l = 0; l < D; l++)
                        buckets[i + j + k + l].push_back({i, j, k, l});

        minLen[idx(0,0,0,0)] = 0;
        for (int s = 0; s <= maxSum; s++) {
            for (auto &st : buckets[s]) {
                int i = st[0], j = st[1], k = st[2], l = st[3];
                if (i == 0 && j == 0 && k == 0 && l == 0) continue;
                int best = INF;
                for (int v = 1; v <= 9; v++) {
                    auto &e = digitExp[v];
                    int ni = max(i - e[0], 0);
                    int nj = max(j - e[1], 0);
                    int nk = max(k - e[2], 0);
                    int nl = max(l - e[3], 0);
                    if (ni == i && nj == j && nk == k && nl == l) continue; 
                    int cand = minLen[idx(ni, nj, nk, nl)] + 1;
                    if (cand < best) best = cand;
                }
                minLen[idx(i, j, k, l)] = best;
            }
        }

        int n = (int)num.size();
        vector<int> digits(n);
        for (int i = 0; i < n; i++) digits[i] = num[i] - '0';

        int k = n;
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) { k = i; break; }
        }
        vector<array<int,4>> PE(k + 1, {0,0,0,0});
        array<int,4> cur = {0,0,0,0};
        for (int i = 0; i < k; i++) {
            auto &e = digitExp[digits[i]];
            cur[0] = min(cur[0] + e[0], a);
            cur[1] = min(cur[1] + e[1], b);
            cur[2] = min(cur[2] + e[2], c);
            cur[3] = min(cur[3] + e[3], d);
            PE[i + 1] = cur;
        }

        if (k == n) {
            array<int,4> req = {a - PE[n][0], b - PE[n][1], c - PE[n][2], d - PE[n][3]};
            if (req[0] == 0 && req[1] == 0 && req[2] == 0 && req[3] == 0) {
                return num;
            }
        }

        int hi = (k < n) ? k : n - 1;
        for (int i = hi; i >= 0; i--) {
            int low = digits[i] + 1;
            if (low > 9) continue;
            auto &prefixState = PE[i];
            int L = n - 1 - i;
            for (int v = low; v <= 9; v++) {
                auto &e = digitExp[v];
                int c0 = min(prefixState[0] + e[0], a);
                int c1 = min(prefixState[1] + e[1], b);
                int c2 = min(prefixState[2] + e[2], c);
                int c3 = min(prefixState[3] + e[3], d);
                array<int,4> req = {a - c0, b - c1, c - c2, d - c3};
                if (minLen[idx(req[0], req[1], req[2], req[3])] <= L) {
                    vector<int> suffix = buildSuffix(req, L);
                    string res;
                    res.reserve(n);
                    for (int p = 0; p < i; p++) res += char('0' + digits[p]);
                    res += char('0' + v);
                    for (int x : suffix) res += char('0' + x);
                    return res;
                }
            }
        }

        int minFull = minLen[idx(a, b, c, d)];
        int L = max(n + 1, minFull);
        array<int,4> fullReq = {a, b, c, d};
        vector<int> full = buildSuffix(fullReq, L);
        string res;
        res.reserve(L);
        for (int x : full) res += char('0' + x);
        return res;
    }

private:
    vector<int> buildSuffix(array<int,4> req, int L) {
        vector<int> res;
        res.reserve(L);
        array<int,4> state = req;
        int remaining = L;
        for (int p = 0; p < L; p++) {
            for (int v = 1; v <= 9; v++) {
                auto &e = digitExp[v];
                int ni = max(state[0] - e[0], 0);
                int nj = max(state[1] - e[1], 0);
                int nk = max(state[2] - e[2], 0);
                int nl = max(state[3] - e[3], 0);
                if (minLen[idx(ni, nj, nk, nl)] <= remaining - 1) {
                    res.push_back(v);
                    state = {ni, nj, nk, nl};
                    remaining--;
                    break;
                }
            }
        }
        return res;
    }
};

const int Solution::INF;

