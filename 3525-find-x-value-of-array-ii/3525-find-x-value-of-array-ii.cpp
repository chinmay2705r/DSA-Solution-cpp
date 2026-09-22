class Solution {
    struct Node {
        int prod = 1;
        vector<int> cnt;
        Node(int k) : cnt(k, 0) {}
    };

    int k_val;
    vector<Node> tree;

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % k_val;
            tree[node].prod = rem;
            fill(tree[node].cnt.begin(), tree[node].cnt.end(), 0);
            tree[node].cnt[rem] = 1;
            return;
        }

        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }

        Node& left = tree[2 * node];
        Node& right = tree[2 * node + 1];

        tree[node].prod = (left.prod * right.prod) % k_val;
        for (int r = 0; r < k_val; ++r) {
            tree[node].cnt[r] = left.cnt[r];
        }
        for (int r = 0; r < k_val; ++r) {
            int new_rem = (left.prod * r) % k_val;
            tree[node].cnt[new_rem] += right.cnt[r];
        }
    }

    Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;
        if (r <= mid) {
            return query(2 * node, start, mid, l, r);
        }
        if (l > mid) {
            return query(2 * node + 1, mid + 1, end, l, r);
        }

        Node left = query(2 * node, start, mid, l, r);
        Node right = query(2 * node + 1, mid + 1, end, l, r);

        Node res(k_val);
        res.prod = (left.prod * right.prod) % k_val;
        for (int i = 0; i < k_val; ++i) {
            res.cnt[i] = left.cnt[i];
        }
        for (int i = 0; i < k_val; ++i) {
            int new_rem = (left.prod * i) % k_val;
            res.cnt[new_rem] += right.cnt[i];
        }
        return res;
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        k_val = k;
        tree.assign(4 * n, Node(k));

        for (int i = 0; i < n; ++i) {
            update(1, 0, n - 1, i, nums[i]);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int target_x = q[3];

            update(1, 0, n - 1, idx, val);
            Node res = query(1, 0, n - 1, start, n - 1);
            ans.push_back(res.cnt[target_x]);
        }

        return ans;
    }
};