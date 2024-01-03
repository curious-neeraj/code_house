// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int len = nums.size();

        for(int i = 0; i < len; i++)
        {
            if(mp.find(nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
            {
                if(abs(mp[nums[i]] - i) <= k)
                    return true;
                mp[nums[i]] = i; 
            }
        }
        return false;
    }
};
