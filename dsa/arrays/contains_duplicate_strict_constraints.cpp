class Solution {
public:
    
    // Time Complexity - O(nlogn)
    // Space Complexity - O(n)
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        vector<pair<int,int>> vec;
        int len = nums.size();

        // Logic - Make Pairs (value and index) and sort the resultant vector
        for(int i = 0 ; i < len; i++)
            vec.push_back(make_pair(nums[i], i));
        
        sort(vec.begin(), vec.end());

        for(int i = 0; i < len; i++)
        {
            for(int j = i+1; 
                    j < len && abs(vec[i].first - vec[j].first) <= valueDiff; 
                    j++)
            {
                if(abs(vec[i].second - vec[j].second) <= indexDiff)
                    return true;
            }
        }
        return false;
    }
};
