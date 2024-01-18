// Time Complexity - O(n^3)
// Space Complexity - O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int len = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < len; i++)
        {
            long new_target = target - nums[i];
            for(int j = i+1; j < len; j++)
            {
                long two_target = new_target - nums[j];
                int k = j+1;
                int l = len-1;
                
                while(k < l)
                {
                    int sum = nums[k] + nums[l];
                    if(sum > two_target)
                        l--;
                    else if(sum < two_target)
                        k++;
                    else
                    {
                        ans.push_back(vector<int> {nums[i], nums[j], nums[k], nums[l]});
                        
                        // Handle Duplicates
                        while(k < l && nums[k] == nums[k+1])
                            k++;
                        while(k < l && nums[l] == nums[l-1])
                            l--;
                        k++;
                        l--;
                    }
                }
                
                while(j < len-1 && nums[j] == nums[j+1])
                    j++;
            }
            while(i < len-1 && nums[i] == nums[i+1])
                i++;
        }
        return ans;    
    }
};
