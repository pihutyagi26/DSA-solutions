class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> s;
        for( string op : operations){
            if(op == "C"){
                s.pop();
            }else if(op == "D"){
                s.push(2*s.top());
            }else if( op == "+"){
                int a = s.top() ; s.pop();
                int b = s.top();
                s.push(a);
                s.push(a+b);
            }else{
                s.push(stoi(op));
            }
        }
        int sum =0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};