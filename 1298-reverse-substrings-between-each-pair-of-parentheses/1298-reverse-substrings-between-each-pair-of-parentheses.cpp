class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;

        for(char ch : s){
            string temp;
            temp += ch;
            if(ch == '('){
                st.push("(");
            } else if(ch >='a' && ch <='z'){
                st.push(temp);
            } else {
                string rem = "";
                while(st.top() != "("){
                    rem += st.top();
                    st.pop();
                }
                if(!st.empty() && st.top() == "(")
                st.pop();
                // if(!st.empty()){
                    reverse(rem.begin(), rem.end());
                    st.push(rem);
                // } else {
                //    return rem;
                // }
            }
        }

        string rem = "";
        while(!st.empty()){
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        return rem;
    }
};