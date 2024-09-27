class Solution {
public:
    bool isOperation(string str){
        return str == "+" || str == "-" || str == "/" || str == "*";
    }

    int getValue(string str){
        return stoi(str);
    }
    int performOperation(string operation, int a, int b){
        cout<<a<< operation <<b<<"\n";
        if(operation == "+"){
            return a+b;
        } else if(operation == "-"){
            return a - b;
        } else if (operation == "*"){
            return a*b;
        } else {
            return a/b;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<string>vals;
        // stack<string>ops;
        // int ans;
        for(int i=0; i<tokens.size(); i++){
            string curr = tokens[i];
            if(isOperation(curr)){
                int val2 = getValue(vals.top());
                vals.pop();
                int val1 = getValue(vals.top());
                vals.pop();
                int ans = performOperation(curr, val1, val2);
                vals.push(to_string(ans));
            } else {
                vals.push(curr);
            }
        }
        return getValue(vals.top());
    }
};