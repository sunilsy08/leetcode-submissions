class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int totalLines = height.size();
        int leftLineindex = 0, rightLineIndex = totalLines - 1;

        while( leftLineindex < rightLineIndex){
            int currWater = min(height[leftLineindex], height[rightLineIndex]) 
            *(rightLineIndex - leftLineindex);
            maxWater = max(maxWater, currWater);

            if(height[leftLineindex] < height[rightLineIndex]){
                leftLineindex++;
            } else {
                rightLineIndex--;
            }
        }
        return maxWater;
    }
};