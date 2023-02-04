//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string startWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> wl (wordList.begin(), wordList.end());
        
        queue<vector<string>>q;
        q.push({startWord});
        
        unordered_set<string>usedwords;
        usedwords.insert(startWord);
        
        int level = 0;
        vector<vector<string>>ans;
        while(!q.empty()) {
            vector<string>seq = q.front();
            q.pop();
            
            string word = seq.back();
            
            if(seq.size() > level) {
                level++;
                for(auto it: usedwords) {
                    wl.erase(it);
                }
                usedwords.clear();
            }
            if(ans.size() > 0. && ans[0].size() < level) {
                break;
            }
            
            if(word == endWord) {
                if(ans.size() == 0) {
                    ans.push_back(seq);
                } else if(ans[0].size()== seq.size()) {
                    ans.push_back(seq);
                }
                continue;
            }
            
            for(int i=0;i<word.size();i++) {
                char original = word[i];
                for(char ch = 'a' ; ch<='z'; ch++) {
                    word[i] = ch;
                    if(wl.find(word) != wl.end()) {
                        seq.push_back(word);
                        q.push(seq);
                        seq.pop_back();
                        usedwords.insert(word);
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends