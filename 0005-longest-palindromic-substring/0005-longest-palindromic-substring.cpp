class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();

        int maxLen =0;
        int startIndex = 0;

        for(int i=0; i<size; i++){
            int left = i, right = i;
            int currLen = 0;
            while(left >=0 && right < size && s[left] == s[right]){
                currLen = right - left + 1;
                if(currLen > maxLen){
                    maxLen = currLen;
                    startIndex = left;
                }
                left--;
                right++;
            }
        }
        for(int i=0; i<size; i++){
            int left = i, right = i+1;
            int currLen = 0;
            while(left >=0 && right < size && s[left] == s[right]){
                currLen = right - left + 1;
                if(currLen > maxLen){
                    maxLen = currLen;
                    startIndex = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(startIndex, maxLen);
    }
};