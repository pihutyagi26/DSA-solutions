class Solution {
public:
    long long K;

    long long countWays(vector<int>& cnt, long long limit) {
        int total = 0;
        for (int x : cnt) total += x;

        long long res = 1;

        for (int c : cnt) {
            if (c == 0) continue;

            int r = c;
            for (int i = 1; i <= r; i++) {
                long long num = total - r + i;
                long long den = i;

                long long g = gcd(num, den);
                num /= g;
                den /= g;

                g = gcd(res, den);
                res /= g;
                den /= g;

                if (res > limit / num) return limit + 1;
                res *= num;

                if (den > 1) res /= den;

                if (res > limit) return limit + 1;
            }
            total -= r;
        }

        return res;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        long long total = countWays(half, (long long)k);
        if (total < k) return "";

        int halfLen = 0;
        for (int x : half) halfLen += x;

        string left;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) continue;

                half[ch]--;

                long long ways = countWays(half, (long long)k);

                if (ways >= k) {
                    left.push_back(char('a' + ch));
                    break;
                }

                k -= ways;
                half[ch]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
