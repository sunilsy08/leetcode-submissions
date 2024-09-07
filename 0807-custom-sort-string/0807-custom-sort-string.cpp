class Solution {
public:
    string customSortString(string order, string s) {
        int seqOrder[26] = {0};  // To store the order of characters
        
        // Assign order for each character based on 'order' string
        for (int i = 0; i < order.size(); ++i) {
            seqOrder[order[i] - 'a'] = i + 1;
        }

        // Sort the string 's' based on the custom order using a lambda function
        sort(s.begin(), s.end(), [&seqOrder](char ch1, char ch2) {
            return seqOrder[ch1 - 'a'] < seqOrder[ch2 - 'a'];
        });

        return s;
    }
};
