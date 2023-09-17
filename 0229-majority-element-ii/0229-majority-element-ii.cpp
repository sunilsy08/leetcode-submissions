class Solution {
public:
    vector<int> helper(vector<int>& nums) {
        int el1 = INT_MIN,el2= INT_MIN;
        int count1 = 0, count2 = 0;

        for(int i=0; i<nums.size(); i++){
            if(count1 == 0 && nums[i] != el2){
                el1 = nums[i];
                count1 = 1;
            } else if(count2 == 0 && nums[i] != el1){
                el2 = nums[i];
                count2 = 1;
            } 
            else if(nums[i] == el1) count1++;
            else if (nums[i] == el2) count2++;
            else {
                count1--;
                count2--;
            }
        }
        vector<int>ans;

        int asum = 0, bsum = 0;
        for(int i=0;i<nums.size(); i++) {
            if(nums[i] == el1) asum++;
            else if(nums[i] == el2) bsum ++;
        }
        if(asum > nums.size()/3) ans.push_back(el1);
        if(bsum > nums.size()/3 && el1!= el2) ans.push_back(el2);
        return ans;

    }
    vector<int> majorityElement(vector<int>& nums) {
        return helper(nums);
    }
};