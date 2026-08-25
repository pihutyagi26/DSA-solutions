class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        stack<int> s;
        vector<int > right(n,0);
        vector<int > left(n,0);

        for(int i=n-1 ; i>=0 ; i--){
            while(!s.empty() && ht[s.top()]>= ht[i]){
                s.pop();
            }
             right[i] = s.empty() ?n : s.top();
              s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        for(int i = 0 ; i< n ; i++){
            while(s.size() >0 && ht[s.top()] >=ht[i]){
                s.pop();
            }
            left[i] = s.empty() ? -1: s.top();
            s.push(i);
        }
       
       int  ans = 0;
       for(int i =0 ; i<n ;i++){
        int width = right[i] - left[i] -1;
        int currArea = ht[i] * width;
        ans = max(ans , currArea);

       }
       return ans;
    }
};