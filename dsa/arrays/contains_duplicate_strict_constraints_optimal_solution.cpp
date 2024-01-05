class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        // Bucket Based Solution
        // Time Complexity - O(n)
        // Space Compexity - O(n)
        unordered_map<int, int> mp;
        int len = nums.size();

        if(len <= 1 || indexDiff <= 0 || valueDiff < 0)
            return false; 

        for(int i = 0; i < len; i++)
        {
            int bucket = nums[i] / (valueDiff + 1);
            
            // Maintain lower bound in case of negative values
            if(nums[i] < 0)
                bucket--;

            // If a value exists in same bucket
            if(mp.find(bucket) != mp.end())
                return true;
            else
            {
                mp[bucket] = nums[i];
                if(mp.find(bucket - 1) != mp.end() 
                    && abs(mp[bucket-1] - nums[i]) <= valueDiff)
                    return true;
                
                if(mp.find(bucket + 1) != mp.end() 
                    && abs(mp[bucket+1] - nums[i]) <= valueDiff)
                    return true;

                if(mp.size() > indexDiff)
                {
                    int out_bound = nums[i-indexDiff];
                    int remove_bucket = out_bound / (valueDiff + 1);
                    
                    // Maintain lower bound in case of negative values
                    if(out_bound < 0)
                        remove_bucket--;

                    mp.erase(remove_bucket);
                }    
            }
        }

        return false;
    }
};
