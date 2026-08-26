class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;

        string ans = "";
        int bestLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1')
                ones++;

            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            if (ones == k) {
                int tempLeft = left;

                // Remove leading zeros to get the shortest window
                while (tempLeft < right && s[tempLeft] == '0')
                    tempLeft++;

                int len = right - tempLeft + 1;
                string cur = s.substr(tempLeft, len);

                if (len < bestLen) {
                    bestLen = len;
                    ans = cur;
                }
                else if (len == bestLen && cur < ans) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};