class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergedIntervals;
        int n = intervals.size();
        if(n<=1) return intervals;
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>&v1, const vector<int>&v2){
                return v1[0] < v2[0];
            }
        );
        mergedIntervals.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            
            if(mergedIntervals.back()[1] >= currStart ){
                mergedIntervals.back()[0] = min(mergedIntervals.back()[0], currStart);
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], currEnd);
            } else {
                mergedIntervals.push_back(intervals[i]);
            }
        }
        return mergedIntervals;
    }
};