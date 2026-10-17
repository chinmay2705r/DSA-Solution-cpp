class Solution {
private:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sum_sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;

    void push(int node, int start, int end) {
        if (tree[node].lazy == 0) return;

        long long lz = tree[node].lazy;
        int mid = start + (end - start) / 2;

        int left = 2 * node, right = 2 * node + 1;
        long long len_l = mid - start + 1;
        tree[left].sum_sq = (tree[left].sum_sq + 2 * lz % MOD * tree[left].sum % MOD + lz * lz % MOD * len_l % MOD) % MOD;
        tree[left].sum = (tree[left].sum + lz * len_l) % MOD;
        tree[left].lazy = (tree[left].lazy + lz) % MOD;
        long long len_r = end - mid;
        tree[right].sum_sq = (tree[right].sum_sq + 2 * lz % MOD * tree[right].sum % MOD + lz * lz % MOD * len_r % MOD) % MOD;
        tree[right].sum = (tree[right].sum + lz * len_r) % MOD;
        tree[right].lazy = (tree[right].lazy + lz) % MOD;

        tree[node].lazy = 0;
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;

        if (l <= start && end <= r) {
            long long len = end - start + 1;
            tree[node].sum_sq = (tree[node].sum_sq + 2 * val % MOD * tree[node].sum % MOD + val * val % MOD * len % MOD) % MOD;
            tree[node].sum = (tree[node].sum + val * len) % MOD;
            tree[node].lazy = (tree[node].lazy + val) % MOD;
            return;
        }

        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;
        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n, Node());
        unordered_map<int, int> last_pos;

        long long total_sum = 0;

        for (int i = 0; i < n; ++i) {
            int prev = last_pos.count(nums[i]) ? last_pos[nums[i]] : -1;
            
            update(1, 0, n - 1, prev + 1, i, 1);
            
            total_sum = (total_sum + tree[1].sum_sq) % MOD;

            last_pos[nums[i]] = i;
        }

        return total_sum;
    }
};