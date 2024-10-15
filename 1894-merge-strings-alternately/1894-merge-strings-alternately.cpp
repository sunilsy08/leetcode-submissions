class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int left = 0 , right = 0;
        string ans = "";

        while(left < word1.size() && right < word2.size()){
            ans += word1[left++];
            ans += word2[right++];
        }
        while(left < word1.size()){
            ans += word1[left++];
        }
        while(right < word2.size()){
            ans += word2[right++];
        }
        return ans;
    }
};