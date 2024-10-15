class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>merged;
        int n = intervals.size();

        for(auto interval : intervals){
            int start = interval[0];
            int end = interval[1];

            if(merged.size() != 0 && merged.back()[1] >= start){
                merged.back()[0] = min(merged.back()[0], start);
                merged.back()[1] = max(merged.back()[1], end);
            } else {
                merged.push_back(interval);
            }
        }
        return merged;
    }
};