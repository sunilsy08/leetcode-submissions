class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool merged = false;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        vector<vector<int>> ans;
        for(auto interval : intervals){

            int currStart = interval[0];
            int currEnd = interval[1];

            if(!merged && newEnd < currStart){
                ans.push_back({newStart, newEnd});
                merged = true;
                ans.push_back({currStart, currEnd});
            } else if(!merged && currEnd >= newStart){
                newStart = min(currStart, newStart);
                newEnd = max(currEnd, newEnd);
            } else {
                ans.push_back({currStart, currEnd});
            }
        }
        if(!merged){
            ans.push_back({newStart, newEnd});
        }
        return ans;
    }
};