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
        deque<string>vals;
        // stack<string>ops;
        // int ans;
        for(int i=0; i<tokens.size(); i++){
            string curr = tokens[i];
            if(isOperation(curr)){
                int val2 = getValue(vals.back());
                vals.pop_back();
                int val1 = getValue(vals.back());
                vals.pop_back();
                int ans = performOperation(curr, val1, val2);
                vals.push_back(to_string(ans));
            } else {
                vals.push_back(curr);
            }
        }
        return getValue(vals.front());
    }
};