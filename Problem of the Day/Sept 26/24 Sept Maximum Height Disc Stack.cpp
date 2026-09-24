class Solution {
public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n=r.size();
        vector<pair<int,int>>a(n);
        vector<int>vals;

        for (int i = 0; i < n; i++) {
            a[i] = {r[i], h[i]};
            vals.push_back(h[i]);
        }

        // Sort by radius
        sort(a.begin(), a.end());

        // Coordinate compression of heights
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        // Fenwick tree for maximum DP value
        vector<int> bit(m + 1, 0);

        auto query = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res = max(res, bit[idx]);
                idx -= idx & -idx;
            }
            return res;
        };

        auto update = [&](int idx, int val) {
            while (idx <= m) {
                bit[idx] = max(bit[idx], val);
                idx += idx & -idx;
            }
        };

        int ans = 0;

        for (int i = 0; i < n; ) {
            int j = i;

            // All discs having the same radius
            while (j < n && a[j].first == a[i].first)
                j++;

            vector<pair<int,int>> pending;

            // Query first, update later.
            // This prevents discs with the same radius from
            // being stacked on each other.
            for (int k = i; k < j; k++) {
                int height = a[k].second;

                // We need previous height strictly smaller
                int pos = lower_bound(vals.begin(), vals.end(), height)
                          - vals.begin();

                int best = query(pos);

                int cur = best + height;
                pending.push_back({pos + 1, cur});

                ans = max(ans, cur);
            }

            // Now make these discs available for larger radii
            for (auto &[pos, value] : pending) {
                update(pos, value);
            }

            i = j;
        }

        return ans;
    }
};
