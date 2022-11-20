class Solution {
public:
    int getMaxLen(vector<int>& a) {
      vector<int>l(a.size(), INT_MAX);
      vector<int>r(a.size(), INT_MAX);
        int n = a.size();
        int lastNegPos = INT_MAX;
        for(int i=0;i<n;i++) {
            l[i] = lastNegPos;
            if(a[i] <0) {
                lastNegPos = i;
            } else if(a[i] == 0) {
                lastNegPos = INT_MAX;
            }
        }
        lastNegPos = INT_MAX;
        for(int i=n-1;i>=0;i--) {
            r[i] = lastNegPos;
            if(a[i] <0) {
                lastNegPos = i;
            } else if(a[i] == 0) {
                lastNegPos = INT_MAX;
            }
        }
        int len = 0;
        int maxlen = 0;
        for(int i=0;i<n;i++) {
            if(a[i] == 0) {
                len = 0;
                continue;
            }
            if(a[i] > 0) {
                len++;
            } 
            else if(r[i] != INT_MAX) {
                    len= len + (r[i] - i) + 1;
                    i = r[i] ;
            } else {
                len = 0;
                continue;
            }
            maxlen = max(maxlen,len);
        }
        len = 0;
        for(int i=n-1;i>=0;i--) {
            if(a[i] == 0) {
                len = 0;
                continue;
            }
            if(a[i] > 0) {
                len++;
            } 
            else if(l[i] != INT_MAX) {
                    len= len + (i-l[i]) + 1;
                    i = l[i] ;
            } else {
                len = 0;
                continue;
            }
            maxlen = max(maxlen,len);
        }
        
        return maxlen;
    }
};