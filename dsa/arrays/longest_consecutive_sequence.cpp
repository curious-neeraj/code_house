// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int ans = 0;
        int temp = 0;

        unordered_map<int, bool> mp;
        for(int num: nums)        
            mp[num] = true;

        for(int num: nums)
        {
            // Core logic
            if(!mp[num-1])
            {
                temp = 0;
                while(mp[num])
                {
                    num++;
                    temp++;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
