class Solution {
public:

    int ans = 0;
    void merge(vector<int>& nums, int low, int mid, int high) {
        int left = low, right = mid+1;
        vector<int>temp;
        while(right<=high && left <=mid) {
            if(nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }

        while(left<=mid) temp.push_back(nums[left++]);
        while(right<=high) temp.push_back(nums[right++]);

        for(int i=0;i<temp.size(); i++) {
            nums[low+i] = temp[i];
        }
    }

    void countPairs(vector<int>& nums, int low, int mid, int high) {
        int left = low, right = mid+1;

        for(int i=low; i<=mid; i++) {
            while(right<=high && (long)nums[i] >(long)2*nums[right])
            right++;
            ans += right - (mid+1);
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if(low>=high) return;

        int mid = (low+high)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        countPairs(nums, low, mid, high);
        merge(nums,low, mid, high);
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return ans;
    }
};