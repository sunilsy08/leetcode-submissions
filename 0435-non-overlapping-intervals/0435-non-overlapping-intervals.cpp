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
    /*
Why Not Sort by Start Time (interval[0]):
If you sort by the start time, you might end up selecting intervals that overlap later on. For example:

Consider these intervals: [(1, 3), (2, 4), (3, 5)]
If you sort by start time, the order would be the same: [(1, 3), (2, 4), (3, 5)]
You would select (1, 3) first, and then you'd realize that (2, 4) overlaps, so you'd have to remove one.
If you remove (2, 4), you end up with another overlap with (3, 5).
On the other hand, if you sort by end time: [(1, 3), (3, 5), (2, 4)], you'll first select (1, 3), and then (3, 5) fits perfectly without overlap, skipping (2, 4) altogether.
Thus, sorting by the end time gives you the greedy approach to selecting non-overlapping intervals, which leads to the correct and efficient solution.

Key Intuition:
By sorting intervals by their end times, you ensure that each interval you select leaves the maximum possible room for future intervals, minimizing the need for removals.
This approach is greedy and ensures that we minimize the number of overlapping intervals by always choosing the earliest possible finishing interval.
This is why sorting by interval[1] is the optimal strategy for this problem.
    */
};