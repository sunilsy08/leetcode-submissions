class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num: nums){
            freq[num] ++;
        }

        vector<pair<int,int>>sortedArray;
        for(int num : nums){
            sortedArray.push_back({num, freq[num]});
        }

        sort(sortedArray.begin(), sortedArray.end(), [&freq](pair<int,int>p1, pair<int,int>p2){
            if(p1.second != p2.second){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        });
        int ind = 0;
        for(auto it : sortedArray){
            nums[ind++] = it.first;
        }
        return nums;
    }
};