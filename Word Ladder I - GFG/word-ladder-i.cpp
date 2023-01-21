//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool compare(string s1, string s2) {
        int diff = 0;
        for(int i=0;i<s1.size(); i++){
            if(s1[i] != s2[i]) {
                if(diff > 0) return false;
                diff++;
            }
        }
        return true;
    }
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Step 1: creation of graph from word list
        
        // indexing of words.
        int index = 0;
        int N = wordList.size();
        map<int,string> m;
        int src = -1;
        int dest = -1;
        for(int i=0;i<wordList.size(); i++){
            m[index] = wordList[i];
            if(targetWord == wordList[i])
            dest = i;
            if(startWord == wordList[i])
            src = i;
            index++;
        }
        if(src == -1) {
            m[index] = startWord;
            src = index;
        }
        // cout<<dest<<" \n";
        if(dest == -1) return 0;
        // creating adjacency list 
        vector<vector<int>>adj(m.size());
        for(int i=0 ; i < m.size()-1; i++) {
            for(int j = i+1; j<m.size(); j++) {
                if(compare(m[i], m[j])) {
                    // cout<<m[i] <<" and " << m[j] <<"\n";
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        
        // Now do the shortest path algo using BFS
        queue<int>q;
        vector<int>dist(m.size(), INT_MAX);
        // cout<<dist[dest]<<"\n";
        dist[src] = 1;
        q.push(src);
        
        while(q.size()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(dist[node]!= INT_MAX && dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        // for(int i=0;i<m.size();i++) {
        //     cout<<dist[i]<<" ";
        // }
        // cout<<"\n";
        if(dist[dest] == INT_MAX) return 0;
        
        return dist[dest];
        
        return 1;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends