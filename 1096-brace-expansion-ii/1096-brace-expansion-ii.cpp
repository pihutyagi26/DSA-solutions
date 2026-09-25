
class Solution {
public:
    int i = 0;

    set<string> concat(set<string>& A, set<string>& B) {
        set<string> res;

        if (A.empty()) return B;
        if (B.empty()) return A;

        for (auto &a : A) {
            for (auto &b : B) {
                res.insert(a + b);
            }
        }
        return res;
    }

    set<string> parseExpr(string &s) {
        set<string> res = parseTerm(s);

        while (i < s.size() && s[i] == ',') {
            i++; // skip comma
            set<string> right = parseTerm(s);
            res.insert(right.begin(), right.end());
        }

        return res;
    }

    set<string> parseTerm(string &s) {
        set<string> res;
        res.insert("");

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur = parseFactor(s);
            res = concat(res, cur);
        }

        return res;
    }

    set<string> parseFactor(string &s) {
        set<string> res;

        if (islower(s[i])) {
            res.insert(string(1, s[i]));
            i++;
        } else { // '{'
            i++; // skip '{'
            res = parseExpr(s);
            i++; // skip '}'
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        i = 0;
        set<string> ans = parseExpr(expression);
        return vector<string>(ans.begin(), ans.end());
    }
};