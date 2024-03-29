// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;
        vector<int> s_hash(26), p_hash(26);
        int s_len = s.size(), p_len = p.size();
        int left = 0, right = 0;

        for(auto character: p)
            p_hash[character - 'a']++;
        
        while(right < s_len)
        {
            s_hash[s[right] - 'a']++;
            
            if(right - left + 1 == p_len)
            {
                if(s_hash == p_hash)
                    ans.push_back(left);
                s_hash[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        return ans;
    }
};
