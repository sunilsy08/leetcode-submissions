class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        stack<vector<int>>st;
        int count =0;
        for(auto interval : intervals){
            if(st.empty()){
                st.push(interval);
                continue;
            }
            int lastStart = st.top()[0];
            int lastEnd = st.top()[1];
            int currStart = interval[0];
            int currEnd = interval[1];

            if(currStart < lastEnd){
                count++;
                if (currEnd < lastEnd) {
                    // Replace the top of the stack with the current interval as it has a smaller end
                    st.pop();
                    st.push(interval);
                }
            } else {
                st.push(interval);
            }
            
        }
        return count;
    }
};