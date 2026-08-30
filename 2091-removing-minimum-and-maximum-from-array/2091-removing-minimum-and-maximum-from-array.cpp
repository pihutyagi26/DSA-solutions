class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = min_element(nums.begin() , nums.end()) - nums.begin();
        int mx = max_element(nums.begin() , nums.end() )- nums.begin();

        if(mn > mx) swap(mn , mx);
        int front = mx+1;
        int back = n - mn;
        int both = (n-mx) + (mn+1);
        return min({front , back, both});
    }
};