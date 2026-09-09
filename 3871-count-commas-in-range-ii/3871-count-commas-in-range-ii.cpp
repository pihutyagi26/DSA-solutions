
class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        
        for (__int128 p = 1000; p <= n; p *= 1000) {
            ans += n - (long long)p + 1;
        }
        
        return ans;
    }
};