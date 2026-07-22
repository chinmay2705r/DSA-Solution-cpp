class Solution {
    struct SegTree {
        int n;
        vector<int> t;
        SegTree(int size) : n(size), t(4 * size, 0) {}

        void build(const vector<int>& a, int p, int l, int r) {
            if (l == r) { t[p] = a[l]; return; }
            int m = (l + r) / 2;
            build(a, 2 * p, l, m);
            build(a, 2 * p + 1, m + 1, r);
            t[p] = max(t[2 * p], t[2 * p + 1]);
        }

        int query(int p, int l, int r, int ql, int qr) {
            if (qr < l || r < ql || ql > qr) return 0;
            if (ql <= l && r <= qr) return t[p];
            int m = (l + r) / 2;
            return max(query(2 * p, l, m, ql, qr), query(2 * p + 1, m + 1, r, ql, qr));
        }
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> pref(n + 1, 0), segIdx(n);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + (s[i] == '1');

        struct Block { char ch; int l, r, len; };
        vector<Block> blocks;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            blocks.push_back({s[i], i, j - 1, j - i});
            for (int k = i; k < j; ++k) segIdx[k] = blocks.size() - 1;
            i = j;
        }

        int m = blocks.size();
        vector<int> gain(m, 0);
        for (int i = 1; i < m - 1; ++i) {
            if (blocks[i].ch == '1') gain[i] = blocks[i - 1].len + blocks[i + 1].len;
        }

        SegTree st(m);
        if (m > 0) st.build(gain, 1, 0, m - 1);

        vector<int> res;
        int totalOnes = pref[n]; // Count all '1's in the entire string

        for (auto& q : queries) {
            int ql = q[0], qr = q[1];
            int lB = segIdx[ql], rB = segIdx[qr];
            int maxG = 0;

            int f1 = lB + (blocks[lB].ch == '1' ? 1 : 0) + 1;
            int l1 = rB - (blocks[rB].ch == '1' ? 1 : 0) - 1;
            int sL = max(f1, lB + (blocks[lB].l < ql ? 1 : 0) + 1);
            int sR = min(l1, rB - (blocks[rB].r > qr ? 1 : 0) - 1);

            if (sL <= sR) maxG = max(maxG, st.query(1, 0, m - 1, sL, sR));

            int leftZero = (blocks[lB].ch == '0') ? blocks[lB].r - ql + 1 : 0;
            int rightZero = (blocks[rB].ch == '0') ? qr - blocks[rB].l + 1 : 0;

            if (lB + 2 <= rB && blocks[lB + 1].ch == '1' && blocks[lB + 2].ch == '0') {
                int z2 = (lB + 2 == rB) ? rightZero : blocks[lB + 2].len;
                if (leftZero) maxG = max(maxG, leftZero + z2);
            }
            if (rB - 2 >= lB && blocks[rB - 1].ch == '1' && blocks[rB - 2].ch == '0') {
                int z1 = (rB - 2 == lB) ? leftZero : blocks[rB - 2].len;
                if (rightZero) maxG = max(maxG, z1 + rightZero);
            }

            res.push_back(totalOnes + maxG);
        }
        return res;
    }
};