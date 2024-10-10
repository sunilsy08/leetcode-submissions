class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>windowFreq;

       int left =0, right = 0;
        int maxlen = 0;
       while(right < s.size()){
            windowFreq[s[right]]++;
            while(windowFreq[s[right]] > 1){
                windowFreq[s[left]]--;
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
            right++;
       }
       return maxlen;
    }
};