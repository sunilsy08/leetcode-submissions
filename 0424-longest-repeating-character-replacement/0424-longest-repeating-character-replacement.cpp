#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMaxOccuringCharFreq(unordered_map<char, int>& windowFreq) {
        int ans = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            ans = max(ans, windowFreq[ch]);
        }
        return ans;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> windowFreq;
        int n = s.size();
        int left = 0, right = 0;
        int ans = 0;
        while (right < n) {
            windowFreq[s[right]]++;

            int totalChars = right - left + 1;
            int maxOccuringCharFreq = getMaxOccuringCharFreq(windowFreq);
            if (totalChars - maxOccuringCharFreq <= k) {
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