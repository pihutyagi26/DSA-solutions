
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        // cnt[r] = number of subarrays ending at previous index
        // whose product % k == r
        vector<long long> cnt(k, 0);

        for (int x : nums) {
            vector<long long> newCnt(k, 0);

            // Start a new subarray [x]
            newCnt[x % k]++;

            // Extend all previous subarrays
            for (int rem = 0; rem < k; rem++) {
                if (cnt[rem] == 0) continue;

                int newRem = (1LL * rem * (x % k)) % k;
                newCnt[newRem] += cnt[rem];
            }

            // Add all subarrays ending at current index
            for (int rem = 0; rem < k; rem++) {
                ans[rem] += newCnt[rem];
            }

            cnt = newCnt;
        }

        return ans;
    }
};