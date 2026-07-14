

class Solution {
public:
    static const int MOD = 1e9 + 7;
    int memo[201][201][201];
    vector<int> nums;
    int n;

    int solve(int idx, int g1, int g2) {
        if (idx == n) {
            return (g1 == g2 && g1 != 0);
        }

        if (memo[idx][g1][g2] != -1)
            return memo[idx][g1][g2];

        long long ans = 0;

        // Option 1: Ignore current element
        ans += solve(idx + 1, g1, g2);

        // Option 2: Put into first subsequence
        int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        ans += solve(idx + 1, ng1, g2);

        // Option 3: Put into second subsequence
        int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        ans += solve(idx + 1, g1, ng2);

        return memo[idx][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& arr) {
        nums = arr;
        n = nums.size();

        memset(memo, -1, sizeof(memo));

        return solve(0, 0, 0);
    }
};