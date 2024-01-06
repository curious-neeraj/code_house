// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:

    bool isPalindrome(string s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    // Check if given string is a valid palindrome after removing at max 1 character
    bool validPalindrome(string s) 
    {    
        int start = 0;
        int end = s.size() - 1;

        while(start < end)
        {
            if(s[start] != s[end])
                return (isPalindrome(s, start+1, end) || isPalindrome(s, start, end-1));

            start++;
            end--;
        }
        return true;
    }
};
