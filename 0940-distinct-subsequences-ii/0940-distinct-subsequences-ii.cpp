
class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> last(26, 0);

        long long total = 0;

        for (char ch : s) {
            long long newTotal = (2 * total + 1 - last[ch - 'a']) % MOD;
            if (newTotal < 0) newTotal += MOD;

            last[ch - 'a'] = (total + 1) % MOD;
            total = newTotal;
        }

        return (int)total;
    }
};