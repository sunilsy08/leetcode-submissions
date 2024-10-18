class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int>openbracketIndex;
        vector<int>bracketpair(n);

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                openbracketIndex.push(i);
            } else if(s[i] == ')'){
                int j = openbracketIndex.top();
                openbracketIndex.pop();
                bracketpair[i] = j;
                bracketpair[j] = i;
            }
        }
        string res = "";
        for(int currIndex = 0, direction =1; currIndex < n; currIndex +=direction){
            if(s[currIndex] == '(' || s[currIndex] == ')'){
                currIndex = bracketpair[currIndex];
                direction = -direction;
            } else {
                res += s[currIndex];
            }
        }
        return res;
    }
    // string reverseParentheses(string s) {
    //     stack<string>st;

    //     for(char ch : s){
    //         string temp;
    //         temp += ch;
    //         if(ch == '('){
    //             st.push("(");
    //         } else if(ch >='a' && ch <='z'){
    //             st.push(temp);
    //         } else {
    //             string rem = "";
    //             while(st.top() != "("){
    //                 rem += st.top();
    //                 st.pop();
    //             }
    //             if(!st.empty() && st.top() == "(")
    //             st.pop();
    //             // if(!st.empty()){
    //                 reverse(rem.begin(), rem.end());
    //                 st.push(rem);
    //             // } else {
    //             //    return rem;
    //             // }
    //         }
    //     }

    //     string rem = "";
    //     while(!st.empty()){
    //         rem += st.top();
    //         st.pop();
    //     }
    //     reverse(rem.begin(), rem.end());
    //     return rem;
    // }
};