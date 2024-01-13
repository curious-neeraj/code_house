// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        vector<int> dict(256, -1);
        int start = -1;
        int ans = 0;
        int len = s.size();
        
        for(int i=0; i<len; i++)
        {
            if(dict[s[i]] > start)
                start = dict[s[i]];
            
            dict[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};
