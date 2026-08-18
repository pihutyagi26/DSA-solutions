
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int i = 0; i + k <= n; i++) {
            unordered_set<int> seen;
            
            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            for (int x : seen) {
                freq[x]++;
            }
        }

        int ans = -1;
        for (auto &[x, cnt] : freq) {
            if (cnt == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};