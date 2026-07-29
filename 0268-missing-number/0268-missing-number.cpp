class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int sum =0;
        int ans= 0;
        for(int i=0 ;i<n ;i++){
            sum += nums[i];
        }
        ans = n*(n+1)/2 - sum;
        return ans;
    }
};