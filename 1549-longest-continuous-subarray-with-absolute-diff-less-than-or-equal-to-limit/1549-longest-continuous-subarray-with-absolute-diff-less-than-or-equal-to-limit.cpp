class Solution {
public:
    // Helper function to check if the window is valid
    bool isWindowValid(deque<int>& mind, deque<int>& maxd, vector<int>& nums, int limit) {
        if (mind.empty() || maxd.empty()) return true;
        return (nums[maxd.front()] - nums[mind.front()]) <= limit;
    }

    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int maxLength = 0;
        
        deque<int> mind, maxd;  // Deques to store indices of min and max elements

        while (right < n) {
            // Maintain minDeque in increasing order (for minimum values)
            while (!mind.empty() && nums[mind.back()] > nums[right]) {
                mind.pop_back();
            }
            mind.push_back(right);

            // Maintain maxDeque in decreasing order (for maximum values)
            while (!maxd.empty() && nums[maxd.back()] < nums[right]) {
                maxd.pop_back();
            }
            maxd.push_back(right);

            // Shrink the window if it's not valid
            while (!isWindowValid(mind, maxd, nums, limit)) {
                // If leftmost element is out of window, remove it from the deques
                if (mind.front() == left) mind.pop_front();
                if (maxd.front() == left) maxd.pop_front();
                left++;  // Move left pointer to shrink the window
            }

            // Update the maximum length of the valid window
            maxLength = max(maxLength, right - left + 1);
            
            // Move the right pointer to expand the window
            right++;
        }

        return maxLength;
    }
};
