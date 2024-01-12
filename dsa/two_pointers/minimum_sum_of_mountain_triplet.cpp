// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    int minimumSum(vector<int>& nums) {   
        
        int len = nums.size();
        vector<int> minLeft(len+1, INT_MAX), minRight(len+1, INT_MAX);
        int ans = INT_MAX;

        minLeft[0] = nums[0];
        for(int i = 1; i < len; i++)
            minLeft[i] = min(minLeft[i-1], nums[i]);
        
        minRight[len-1] = nums[len-1];
        for(int i = len-1; i >= 0 ; i--)
            minRight[i] = min(minRight[i+1], nums[i]);
        
        for(int i = 1; i < len-1; i++)
        {
            if(nums[i] > minLeft[i-1] && nums[i] > minRight[i+1])
                ans = min(ans, nums[i] + minLeft[i-1] + minRight[i+1]);
        }
        
        return ans != INT_MAX ? ans : -1; 
    }
};
