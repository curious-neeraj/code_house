// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {

        int ans = 0;
        int len = nums.size();
        unordered_map<int, bool> mp;

        for(auto num: nums)
            mp[num] = true;

        for(int i = 0; i < len; i++)
        {
            if(mp[nums[i]-diff] && mp[nums[i]+diff])
                ans++;
        } 
        return ans;
    }
};
