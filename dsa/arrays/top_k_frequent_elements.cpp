// Time Compelexity - O(n)
// Space Complexity - O(n) { Actually - O(2n+n) }

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        unordered_map<int, int> mp;
        int len = nums.size();

        for(auto num: nums)
            mp[num]++;

        // Setting up buckets based on frequency of items
        vector<vector<int>> count(len+1, vector<int> ());
        for(auto element: mp)
            count[element.second].push_back(element.first);

        for(int i=len; i >= 0; i--)
        {
            for(auto num: count[i])
            {
                if(ans.size() == k)
                    break;
                ans.push_back(num);
            }
        }

        return ans;
    }
};
