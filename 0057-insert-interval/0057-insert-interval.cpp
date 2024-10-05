class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        bool merged = false;
        vector<vector<int>>ans;

        for(auto interval: intervals){
            int start = interval[0];
            int end = interval[1];

            if(newEnd < start){
                if(!merged){
                    ans.push_back({newStart, newEnd});
                    merged = true;
                }
                ans.push_back({start,end});
                merged = true;
            }
            else if(end >= newStart){
                if(!merged){
                    newStart = min(newStart, start);
                    newEnd = max(newEnd, end);
                }else {
                    ans.push_back({start,end});
                }
            } else {
                ans.push_back({start,end});
            }
        }
        if(!merged){
            ans.push_back({newStart, newEnd});
        }
        return ans;
    }
};