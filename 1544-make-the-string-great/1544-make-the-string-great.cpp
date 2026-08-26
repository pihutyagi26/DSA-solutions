class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char ch : s){
            int current = ch;
            if(!st.empty() && abs(current - st.top()) == 32){
                st.pop();
            }else
            st.push(ch);
            ch++;
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();

        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};