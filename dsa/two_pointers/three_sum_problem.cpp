// Time Complexity - O(n*logn)
// Space Complexity - O(1) - no additional space apart from ans

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int len = nums.size();
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < len; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i+1, k = len-1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    // Handle Duplicates
                    while(j<k && nums[j] == nums[j+1])
                        j++;
                    while(j<k && nums[k] == nums[k-1])
                        k--;

                    // Next Solution
                    j++;
                    k--;
                }
                else if(sum > 0)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};
