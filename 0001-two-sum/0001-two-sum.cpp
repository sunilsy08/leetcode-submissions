class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        for(int i=0; i<nums.size(); i++){
            int curr = nums[i];
            int req = target - curr;
            if(m.find(req) != m.end()){
                vector<int>ans;
                ans.push_back(i);
                ans.push_back(m[req]);
                return ans;
            }
            m[curr] = i;
        }
        return {};
    }
};