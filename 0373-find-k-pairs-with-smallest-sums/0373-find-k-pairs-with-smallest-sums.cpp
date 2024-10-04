class comp{
    public:
    bool operator()(pair<int,pair<int,int>>p1,pair<int,pair<int,int>>p2 ){
        return p1.first < p2.first ? false:true;
    }
};
class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,pair<int,int>>>pq;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        comp>pq;
        // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>>ans;

        for(int i=0; i<nums2.size(); i++){
            pq.push({nums1[0]+nums2[i], {0,i}});
            // if(pq.size() >k){
            //     pq.pop();
            // }
        }

        while(!pq.empty() && k>0){
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            ans.push_back({nums1[i], nums2[j]});
            pq.pop();
            k--;
            if(i+1 < nums1.size()){
                pq.push({nums1[i+1] + nums2[j], {i+1,j}});
            }
        }
        return ans;
    }
};