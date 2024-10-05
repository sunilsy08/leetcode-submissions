class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        stack<vector<int>>st;

        int curr = 0;

        while(curr<intervals.size()){
            if(st.empty()){
                st.push({intervals[curr][0], intervals[curr][1]});
                curr++;
            } else {
                if(st.top()[1] >= intervals[curr][0]){
                    st.top()[1]= max(st.top()[1], intervals[curr][1]);
                    curr++;
                } else {
                    st.push({intervals[curr][0], intervals[curr][1]});
                    curr++;
                }
            }
        }
        vector<vector<int>>ans;
        while(!st.empty()){
            ans.push_back({st.top()[0], st.top()[1]});
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};