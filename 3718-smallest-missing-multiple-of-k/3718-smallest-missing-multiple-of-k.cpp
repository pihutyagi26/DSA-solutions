class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin() , nums.end());
        int i =1;
        while(st.count(i*k)){
            i++;
        }
        return i*k;
    }
};