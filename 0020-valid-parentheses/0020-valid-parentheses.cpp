class Solution {
public:
    bool isValid(string s) {
        stack<char>openBrackets;

        for( char bracket : s){
            if(bracket == '(' || bracket == '[' || bracket == '{' ){
                openBrackets.push(bracket);
            } else if (openBrackets.empty()) {
                return false;
            } else if (bracket == ')'){
                if(openBrackets.top() != '(') return false;
                openBrackets.pop();
            } else if (bracket == ']'){
                if(openBrackets.top() != '[') return false;
                openBrackets.pop();
            }
            else if (bracket == '}'){
                if(openBrackets.top() != '{') return false;
                openBrackets.pop();
            }
        }
        return openBrackets.empty();
    }
};