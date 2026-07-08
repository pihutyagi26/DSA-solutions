class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos, digit;

        // Store non-zero digits and their positions
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // Prefix sum of digits
        vector<long long> prefixSum(m + 1, 0);

        // Prefix concatenated number
        vector<long long> prefixNum(m + 1, 0);

        // Powers of 10
        vector<long long> pow10(m + 1, 1);

        for (int i = 0; i < m; i++) {
            prefixSum[i + 1] = prefixSum[i] + digit[i];
            prefixNum[i + 1] = (prefixNum[i] * 10 + digit[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefixSum[R + 1] - prefixSum[L];

            int len = R - L + 1;

            long long x = (prefixNum[R + 1] -
                           prefixNum[L] * pow10[len] % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};

