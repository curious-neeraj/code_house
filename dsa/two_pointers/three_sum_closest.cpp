class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int ans = nums[0] + nums[1] + nums[2];
        int len = nums.size();
        int sum = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < len; i++)
        {
            int start = i+1;
            int end = len-1;
            while(start < end)
            {
                sum = nums[i] + nums[start] + nums[end];
                if(sum == target)
                    return sum;
                if(sum < target)
                    start++;
                else
                    end--;
                
                if(abs(sum - target) < abs(ans - target))
                    ans = sum;
            }
        }
        return ans;
    }
};
