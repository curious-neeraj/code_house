// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        
        int water = 0;
        int len = height.size();
        
        int left = 0, right = len-1;
        int leftMax = height[0], rightMax = height[len-1];
        
        while(left < right)
        {
            if(height[left] < height[right])
            {
                leftMax = max(leftMax, height[left]);           
                water += leftMax - height[left];
                left++;
            }
            else
            {
                rightMax = max(rightMax, height[right]); 
                water += rightMax - height[right];
                right--;
            }
        }
        
        return water;
    }
};
