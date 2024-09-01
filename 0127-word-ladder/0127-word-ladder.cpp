class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wl(wordList.begin(), wordList.end());

        queue<pair<string, int>>q;
        q.push({beginWord,1});
        wl.erase(beginWord);

        while(!q.empty()) {
            string currword = q.front().first;
            int currlen = q.front().second;
            q.pop();
            if(currword == endWord) return currlen;

            for(int i=0; i<currword.length(); i++){
                char original = currword[i];
                for(char ch = 'a' ; ch <='z'; ch++) {
                    currword[i] = ch;
                    if(wl.find(currword) != wl.end()){
                        wl.erase(currword);
                        q.push({currword, currlen+1});
                    }
                }
                currword[i] = original;
            }
        }
        return 0;
    }
};