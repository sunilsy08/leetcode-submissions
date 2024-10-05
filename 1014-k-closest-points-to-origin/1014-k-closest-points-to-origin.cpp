class comp{
public:
    bool operator()(pair<int,int>p1, pair<int,int>p2){
        long long dist1 = p1.first*p1.first + p1.second*p1.second;
        long long dist2 = p2.first*p2.first + p2.second*p2.second;
        return dist1 < dist2;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,
        comp>pq;

        for(auto point: points){
            pq.push({point[0], point[1]});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
    }
};