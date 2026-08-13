
class Solution {
public:
    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char leftChar;
        char rightChar;

        Node() : len(0), pref(0), suff(0), best(0),
                 leftChar('#'), rightChar('#') {}
    };

    vector<Node> seg;
    string s;

    Node merge(Node &L, Node &R) {
        if (L.len == 0) return R;
        if (R.len == 0) return L;

        Node res;

        res.len = L.len + R.len;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        // Prefix
        res.pref = L.pref;
        if (L.pref == L.len && L.rightChar == R.leftChar) {
            res.pref = L.len + R.pref;
        }

        // Suffix
        res.suff = R.suff;
        if (R.suff == R.len && L.rightChar == R.leftChar) {
            res.suff = R.len + L.suff;
        }

        // Best
        res.best = max(L.best, R.best);

        if (L.rightChar == R.leftChar) {
            res.best = max(res.best, L.suff + R.pref);
        }

        return res;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx].len = 1;
            seg[idx].pref = 1;
            seg[idx].suff = 1;
            seg[idx].best = 1;
            seg[idx].leftChar = s[l];
            seg[idx].rightChar = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {
        if (l == r) {
            seg[idx].leftChar = ch;
            seg[idx].rightChar = ch;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, ch);
        else
            update(2 * idx + 1, mid + 1, r, pos, ch);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(string s_,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        s = s_;
        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, pos, ch);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};