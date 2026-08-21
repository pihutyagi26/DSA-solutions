class Solution {
public:
    long long gcdll(long long a, long long b) {
        return b == 0 ? a : gcdll(b, a % b);
    }

    long long lcmll(long long a, long long b) {
        return a / gcdll(a, b) * b;
    }

    bool check(long long x, vector<int>& coins, long long k) {
        int n = coins.size();
        long long cnt = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    l = lcmll(l, coins[i]);
                    if (l > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            if (__builtin_popcount(mask) & 1)
                cnt += x / l;
            else
                cnt -= x / l;
        }

        return cnt >= k;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long left = 1, right = 1e11;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (check(mid, coins, k))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};