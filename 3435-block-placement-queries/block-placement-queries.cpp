class Solution {
public:

    class SegmentTree {
    public:
        vector<int> seg;
        int n;

        SegmentTree(int n) {
            this->n = n;
            seg.resize(4 * n + 1, 0);
        }

        void update(int idx, int low, int high, int pos, int val) {
            if (low == high) {
                seg[idx] = val;
                return;
            }

            int mid = (low + high) / 2;

            if (pos <= mid)
                update(2 * idx, low, mid, pos, val);
            else
                update(2 * idx + 1, mid + 1, high, pos, val);

            seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
        }

        int query(int idx, int low, int high, int l, int r) {
            if (r < low || high < l) return 0;

            if (l <= low && high <= r)
                return seg[idx];

            int mid = (low + high) / 2;

            int left = query(2 * idx, low, mid, l, r);
            int right = query(2 * idx + 1, mid + 1, high, l, r);

            return max(left, right);
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {

        int LIMIT = 50000;

        SegmentTree st(LIMIT + 2);

        set<int> obstacles;
        obstacles.insert(0);

        vector<bool> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {

                int x = q[1];

                auto it = obstacles.lower_bound(x);

                int right = LIMIT;
                if (it != obstacles.end()) right = *it;

                int left = *prev(it);

                st.update(1, 0, LIMIT, x, x - left);
                st.update(1, 0, LIMIT, right, right - x);

                obstacles.insert(x);
            }
            else {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int leftObstacle = *prev(it);

                int best = st.query(1, 0, LIMIT, 0, leftObstacle);

                best = max(best, x - leftObstacle);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};