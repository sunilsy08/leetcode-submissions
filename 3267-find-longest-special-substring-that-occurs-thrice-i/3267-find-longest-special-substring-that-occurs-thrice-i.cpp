class Solution {
public:
    bool isPossible(string s, int mid) {
        unordered_map<char, int>specialSubstringCount;

        for(int i=0; i<s.size(); i++) {
            int count = 0;
            int curr = i;
            while(curr < s.size() && s[curr] == s[i]) {
                count++;
                curr++;
            }
            if(count >= mid) {
                specialSubstringCount[s[i]]++;
                if(specialSubstringCount[s[i]] == 3) return true;
            }
        }
        return false;
    }
    int maximumLength(string s) {
        int low = 1;
        int n = s.size();
        int high = n;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;

            if(isPossible(s, mid)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};