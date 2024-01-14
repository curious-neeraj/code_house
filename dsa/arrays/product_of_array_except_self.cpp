// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
//         vector<int> ans;
//         int len = nums.size();
        
//         int prod = 1;
//         int num_zeroes = 0;
        
//         for(auto& num: nums)
//         {
//             if(num != 0)
//                 prod *= num;
//             if(num == 0)
//                 num_zeroes++;
//         }
        
//         if(num_zeroes == 1)
//         {
//             for(int num: nums)
//                 if(num != 0)
//                     ans.push_back(0);
//                 else
//                     ans.push_back(prod);
//         }
//         else if(num_zeroes >= 2)
//             for(int num: nums)
//                 ans.push_back(0);
//         else
//             for(int num: nums)
//                 ans.push_back(prod * pow(num,-1));
        
//         return ans;
        
        int pre = 1, suf = 1;
        int len = nums.size();
        
        vector<int> ans(len,1);
        
        // One pass solution!
        for(int i=0; i<len; i++)
        {
            ans[i] *= pre;
            pre *= nums[i];
            
            ans[len-1-i] *= suf;
            suf *= nums[len-1-i];
        }
        
        return ans;
    }
};
