class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> w;
        stack <char> q;
        for(char ch: s){
        if(ch == '#'){
            if(!w.empty())w.pop();
        }else{
            w.push(ch);
        }
    
        }
        for(char ch :t){
            if(ch == '#'){
                if(!q.empty())q.pop();
            }else{
                q.push(ch);
            }
        }
        return w==q;
    }
};