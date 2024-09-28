class Solution {
public:
    class comp{
        public:
        bool operator()(pair<int,pair<int,int>>&p1, pair<int,pair<int,int>>&p2){
            int sum1 = p1.first;
            int sum2 = p2.first;
            return (sum1 > sum2);
        }
    };
    // class comp {
    // public:
    //     bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
    //         int sum1 = p1.first + p1.second;
    //         int sum2 = p2.first + p2.second;
    //         // Return true if p1 has a greater sum than p2 (min-heap behavior)
    //         return sum1 > sum2;
    //     }
    // };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, comp> pq;
        // priority_queue<pair<int,int>,comp>pq;
          vector<vector<int>> ans;

          for(int i=0; i<nums1.size(); i++){
            pq.push({nums1[i] + nums2[0], {i,0}});
          }

          while(!pq.empty() && k>0){
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            k--;
            vector<int>curr = {nums1[i],nums2[j]};
            ans.push_back(curr);
            if(j+1<nums2.size()){
                pq.push({nums1[i] + nums2[j+1], {i,j+1}});
            }
          }
          return ans;
    }
};