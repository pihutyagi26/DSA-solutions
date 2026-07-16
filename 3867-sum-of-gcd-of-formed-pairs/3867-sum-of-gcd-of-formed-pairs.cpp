class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=0;
        
         vector<int>prefixGcd;

        for(int i=0; i<nums.size(); i++){
            mx= max(mx, nums[i]);
            prefixGcd.push_back(__gcd(nums[i], mx));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int n= prefixGcd.size();
        int left =0;
          int right= n-1;
          long long ans=0;
        while(left < right){
             ans += __gcd(prefixGcd[left], prefixGcd[right]);
            left ++;
            right--;
        }
        return ans;
    }
};