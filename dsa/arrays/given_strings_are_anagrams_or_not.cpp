// Time Complexity - O(n)
// Space Complextiy - O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        int counts[27] = {0};
        int length = s.length();

        for(int i = 0; i < length; i++)
        {
            counts[s[i]-'a']++;
            counts[t[i]-'a']--;
        }

        for(int i = 0; i < 26; i++)
        {
            if(counts[i] != 0)
                return false;
        }

        return true;
    }
};
