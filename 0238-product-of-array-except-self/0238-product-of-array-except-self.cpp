class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>preproduct(n);
        vector<int>postproduct(n);
        int product = 1;
        for(int i=0; i<n; i++) {
            preproduct[i] = product;
            product*= nums[i];
        }
        product = 1;
        for(int i=n-1; i>=0; i--) {
            postproduct[i] = product;
            product *= nums[i];
        }

        vector<int>ans;
        for(int i=0; i<n; i++) {
            ans.push_back(postproduct[i] * preproduct[i]);
        }
        return ans;
    }
};