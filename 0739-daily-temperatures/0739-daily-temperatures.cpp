class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n = temp.size();
        vector<int> ans(n, 0);
        for(int i= n-1 ; i>=0 ; i--){
           
            while(!st.empty() && temp[st.top()] <= temp[i]) {
             st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top() - i;
            }
            else{
                ans[i] = 0;
            }
            st.push(i);
        }
        return ans;
    }
};