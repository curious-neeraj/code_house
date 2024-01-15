// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int len = s1.size();
        int t_len = s2.size();
        vector<int> source(26), target(26);
        
        for(auto c: s1)
            source[c-'a']++;
        
        int left = 0, right = 0;
        while(right < t_len)
        {   
            target[s2[right]-'a']++;
            right++;
            if(right-left == len)
            {
                // Equate the vectors and check
                if(source == target)
                    return true;
                else
                {
                    target[s2[left]-'a']--;
                    left++;
                }
            }
        }
        return false;
    }
};
