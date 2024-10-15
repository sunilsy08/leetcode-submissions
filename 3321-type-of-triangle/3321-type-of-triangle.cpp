class Solution {
public:
    bool isValidTriangle(int a, int b, int c){
        if(a+b > c && a+c > b && c+b > a) return true;
        return false;
    }
    string triangleType(vector<int>& nums) {
        if(!isValidTriangle(nums[0], nums[1], nums[2])){
            return "none";
        }
        if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
        if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) return "isosceles";
        return "scalene";
    }
};