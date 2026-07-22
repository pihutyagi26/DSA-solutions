class Solution {
    struct Group {
        int start;
        int length;
    };

    class SparseTable {
    public:
        int n;
        vector<vector<int>> st;

        SparseTable(const vector<int>& nums) {
            n = nums.size();
            if (n == 0) return;

            int LOG = 32 - __builtin_clz(n);
            st.assign(LOG, vector<int>(n));

            for (int i = 0; i < n; i++)
                st[0][i] = nums[i];

            for (int k = 1; k < LOG; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    st[k][i] =
                        max(st[k - 1][i],
                            st[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        int query(int l, int r) const {
            int len = r - l + 1;
            int k = 31 - __builtin_clz(len);
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        }
    };

    pair<vector<Group>, vector<int>> getZeroGroups(const string& s) {
        vector<Group> groups;
        vector<int> idx(s.size());

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0')
                    groups.back().length++;
                else
                    groups.push_back({i, 1});
            }
            idx[i] = (int)groups.size() - 1;
        }

        return {groups, idx};
    }

    vector<int> getMergeLengths(const vector<Group>& groups) {
        vector<int> res;

        for (int i = 0; i + 1 < (int)groups.size(); i++)
            res.push_back(groups[i].length + groups[i + 1].length);

        return res;
    }

public:
    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries) {

        int ones = count(s.begin(), s.end(), '1');

        auto [zeroGroups, zeroGroupIndex] = getZeroGroups(s);

        if (zeroGroups.empty())
            return vector<int>(queries.size(), ones);

        vector<int> mergeLengths = getMergeLengths(zeroGroups);

        SparseTable st(mergeLengths);

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int left =
                (zeroGroupIndex[l] == -1)
                    ? -1
                    : zeroGroups[zeroGroupIndex[l]].length -
                          (l - zeroGroups[zeroGroupIndex[l]].start);

            int right =
                (zeroGroupIndex[r] == -1)
                    ? -1
                    : r - zeroGroups[zeroGroupIndex[r]].start + 1;

            int startAdj = zeroGroupIndex[l] + 1;
            int endAdj =
                (s[r] == '1')
                    ? zeroGroupIndex[r]
                    : zeroGroupIndex[r] - 1;

            int best = ones;

            if (s[l] == '0' &&
                s[r] == '0' &&
                zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {

                best = max(best, ones + left + right);
            }
            else if (!mergeLengths.empty() &&
                     startAdj <= endAdj - 1) {

                best = max(
                    best,
                    ones + st.query(startAdj, endAdj - 1));
            }

            if (s[l] == '0' &&
                zeroGroupIndex[l] + 1 <= endAdj) {

                best = max(
                    best,
                    ones + left +
                        zeroGroups[zeroGroupIndex[l] + 1].length);
            }

            if (s[r] == '0' &&
                zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {

                best = max(
                    best,
                    ones + right +
                        zeroGroups[zeroGroupIndex[r] - 1].length);
            }

            ans.push_back(best);
        }

        return ans;
    }
};