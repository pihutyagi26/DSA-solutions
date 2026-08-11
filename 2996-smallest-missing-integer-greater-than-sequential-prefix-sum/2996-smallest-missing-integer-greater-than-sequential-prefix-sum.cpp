
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sum = nums[0];
        int i = 1;

        // Find longest sequential prefix and its sum
        while (i < n && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }

        unordered_set<int> st(nums.begin(), nums.end());

        int x = sum;
        while (st.count(x)) {
            x++;
        }

        return x;
    }
};