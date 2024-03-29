// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,bool> mp;
        
        for(auto num : nums)
        {
            if(mp.find(num) == mp.end())
                mp[num] = true;
            else
                return true;
        }

        return false;
    }
};
