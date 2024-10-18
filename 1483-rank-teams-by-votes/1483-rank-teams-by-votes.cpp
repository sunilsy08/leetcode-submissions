class Solution {
    // static bool comp(pair<char, vector<int>> p1, pair<char, vector<int>>p2){

    //         if(p1.second[i] != p2.second[i]){
    //             return true;
    //         }
    //     return p1.first < p2.first;
    // }
public:

    string rankTeams(vector<string>& votes) {
        int totalVotes = votes.size();
        if(totalVotes == 1) return votes[0];
        int numTeams = votes[0].size();
        unordered_map<char, vector<int>> voteOrder;
        for (char ch : votes[0]) {
            voteOrder[ch] = vector<int>(numTeams, 0);
        }
        for(int i=0; i<totalVotes; i++){
            for(int j=0; j<numTeams; j++){
                char candidate = votes[i][j];
                voteOrder[candidate][j]++;
            }
        }
        vector<char>fin (votes[0].begin(), votes[0].end());
        sort(fin.begin(), fin.end(), [&voteOrder](char a, char b){
            if(voteOrder[a] != voteOrder[b]){
                return voteOrder[a] > voteOrder[b];
            }
            return a < b;
        });
        string ans = "";
        for(auto it : fin){
            ans += it;
        }
        return ans;
    }
};