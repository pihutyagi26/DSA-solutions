
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        long long minEven = LLONG_MAX;
        long long minOdd = LLONG_MAX;

        for (int x : nums1) {
            if (x & 1)
                minOdd = min(minOdd, (long long)x);
            else
                minEven = min(minEven, (long long)x);
        }

        // All even
        if (minOdd == LLONG_MAX) return true;

        // Smallest element is odd
        if (minOdd < minEven) return true;

        return false;
    }
};