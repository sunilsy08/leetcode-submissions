class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        if(intervals.size() == 0) return count;

        // SORT ON THE BASIS OF ENDING
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int lastEnd = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if(currStart < lastEnd){
                count++;
            } else {
                lastEnd = currEnd;
            }
        }
        return count;
    }
};