
class Solution {
public:
    string buildPalindrome(const string &half, char mid) {
        string rev = half;
        reverse(rev.begin(), rev.end());

        string res = half;
        if (mid) res.push_back(mid);
        res += rev;
        return res;
    }

    string smallestGreaterHalf(vector<int> cnt, const string &targetHalf) {
        int m = targetHalf.size();

        vector<vector<int>> rem(m + 1, vector<int>(26));
        vector<bool> feasible(m + 1, false);

        rem[0] = cnt;
        feasible[0] = true;

        for (int i = 0; i < m; i++) {
            if (!feasible[i]) break;

            int c = targetHalf[i] - 'a';
            if (rem[i][c] == 0) break;

            rem[i + 1] = rem[i];
            rem[i + 1][c]--;
            feasible[i + 1] = true;
        }

        for (int i = m - 1; i >= 0; i--) {
            if (!feasible[i]) continue;

            int cur = targetHalf[i] - 'a';

            for (int d = cur + 1; d < 26; d++) {
                if (rem[i][d] == 0) continue;

                string ans = targetHalf.substr(0, i);
                ans.push_back(char('a' + d));

                vector<int> left = rem[i];
                left[d]--;

                for (int ch = 0; ch < 26; ch++) {
                    ans.append(left[ch], char('a' + ch));
                }

                return ans;
            }
        }

        return "";
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int oddCnt = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1) {
                oddCnt++;
                mid = char('a' + i);
            }
        }

        if (oddCnt > 1) return "";

        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++) {
            halfCnt[i] = freq[i] / 2;
        }

        int m = s.size() / 2;
        string targetHalf = target.substr(0, m);

        // Case 1: H == targetHalf
        bool canEqual = true;
        vector<int> tmp = halfCnt;

        for (char c : targetHalf) {
            int id = c - 'a';
            if (tmp[id] == 0) {
                canEqual = false;
                break;
            }
            tmp[id]--;
        }

        if (canEqual) {
            string pal = buildPalindrome(targetHalf, mid);
            if (pal > target) return pal;
        }

        // Case 2: smallest H > targetHalf
        string half = smallestGreaterHalf(halfCnt, targetHalf);
        if (half.empty()) return "";

        return buildPalindrome(half, mid);
    }
};