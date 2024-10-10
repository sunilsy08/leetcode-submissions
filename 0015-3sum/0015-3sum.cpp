class Solution {
public:
    bool binarySearch(vector<int>& nums, int low, int high, int target){

        while(low <=high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return true;

            if(nums[mid] < target){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int sum = nums[i] + nums[j];
                if(binarySearch(nums, j+1, n-1, -sum)){
                    ans.push_back({nums[i], nums[j], -sum});
                }
            }
        }
        return ans;
    }
};