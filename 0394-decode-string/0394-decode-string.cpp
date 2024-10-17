class Solution {
public:
    string decodeString(string s) {
       stack<string>st;

       for(int i=0; i<s.size(); i++){
            string temp= "";
            if(s[i] != ']'){
                temp += s[i];
                st.push(temp);
            } else {
                while(!st.empty() && st.top() != "["){
                    temp = st.top() + temp;
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }

                int factor = 1;
                string strfactor = "";
                while(!st.empty() && st.top()[0] >= '0' && st.top()[0] <='9'){
                    strfactor = st.top() + strfactor;
                    st.pop();
                }
                if(strfactor.size() >= 1){
                    factor = stoi(strfactor);
                }
                string newstr = "";
                while(factor--){
                    newstr  += temp;
                }
                st.push(newstr);
            }
       }
       string ans = "";
       while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
       }
        return ans;
    }
};