// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> answer;
        unordered_map<long,int> mp;

        int len = nums.size();
        for(int i=0; i < len; i++)
        {
            long required = target - nums[i];

            if(mp.find(required) == mp.end())
                mp.insert({nums[i], i});
            else
            {
                answer = {mp[required], i};
                break;
            }
        }

        return answer;
    }
};
