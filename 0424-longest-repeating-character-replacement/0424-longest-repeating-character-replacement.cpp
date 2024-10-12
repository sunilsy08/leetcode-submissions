class Solution {
public:
    int getMaxOccuringCharFreq(unordered_map<char, int>& windowFreq) {
        int ans = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            ans = max(ans, windowFreq[ch]);
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            ans = max(ans, windowFreq[ch]);
        }
        return ans;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> windowFreq;
        int n = s.size();
        int left = 0, right = 0;
        int ans = 0;
        int maxFrequency = 0;
        while (right < n) {
            windowFreq[s[right]]++;
            maxFrequency = max(maxFrequency, windowFreq[s[right]]);

            int totalChars = right - left + 1;
            // int maxOccuringCharFreq = getMaxOccuringCharFreq(windowFreq);
            if (totalChars - maxFrequency <= k) {
                ans = max(ans, totalChars);
                right++;
            } else {
                windowFreq[s[left]]--;
                left++;
                right++;
            }
        }
        return ans;
    }
};