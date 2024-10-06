class Solution {
public:
    vector<string> findRepeatedDnaSequences(string ss) {
        unordered_set<string>s;
        unordered_set<string>ans;
        vector<string>finalAns;
        int n = ss.size();
        if(n<10){
            return {};
        }
        int l=0, r = 9;

        while(l <= n-10){
            string curr = ss.substr(l,10);
            if(s.find(curr) != s.end()){
                ans.insert(curr);
            } else {
                s.insert(curr);
            }
            l++;
        }
       for(string it:ans){
            finalAns.push_back(it);
       }
        return finalAns;
    }
};