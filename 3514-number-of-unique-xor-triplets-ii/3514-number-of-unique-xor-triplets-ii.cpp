
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> dp1(MAXX, false);
        vector<bool> dp2(MAXX, false);
        vector<bool> dp3(MAXX, false);

        for (int num : nums)
            dp1[num] = true;

        // XORs of 2 elements
        for (int x = 0; x < MAXX; x++) {
            if (!dp1[x]) continue;

            for (int num : nums) {
                dp2[x ^ num] = true;
            }
        }

        // XORs of 3 elements
        for (int x = 0; x < MAXX; x++) {
            if (!dp2[x]) continue;

            for (int num : nums) {
                dp3[x ^ num] = true;
            }
        }

        int ans = 0;
        for (bool v : dp3)
            if (v) ans++;

        return ans;
    }
};