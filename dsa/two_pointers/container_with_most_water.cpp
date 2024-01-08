class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int ans = 0;
        int len = height.size();
        int start = 0, end = len-1;
        
        while(start < end)
        {
            if(height[start] < height[end])
            {
                ans = max(ans, height[start] * (end-start));
                start++;
            }
            else
            {
                ans = max(ans, height[end] * (end-start));
                end--;
            }
        }
        return ans;
    }
};
