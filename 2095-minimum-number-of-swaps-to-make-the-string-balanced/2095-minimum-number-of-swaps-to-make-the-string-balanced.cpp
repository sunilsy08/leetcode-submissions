class Solution {
public:
    int minSwaps(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int balance = 0, maxImbalance = 0;
        
        for(char bracket : s) {
            if (bracket == '[') {
                balance++; 
            } else {
                balance--; 
            }
            maxImbalance = min(maxImbalance, balance);
        }
        
        return (-maxImbalance + 1) / 2;
    }
};
