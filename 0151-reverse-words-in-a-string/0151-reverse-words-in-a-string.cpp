class Solution {
public:
    string reverse(string& s, int l, int r){
        while(l<=r){
            swap(s[l++], s[r--]);
        }
        return s;
    }
    string reverseWords(string s) {
        int l =0, r =0;

        stringstream iss(s);
        string word;
        string ans = "";
        vector<string>words;
        while(iss>>word){
            words.push_back(reverse(word, 0, word.size()-1));
        }
        for(int i=0; i<words.size(); i++){
            ans += words[i];
            ans += " ";
        }
        ans.pop_back();
        ans = reverse(ans, 0, ans.size()-1);
        return ans;
    }
};