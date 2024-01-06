class Solution {
public:

    bool isPalindrome(string word)
    {
        int len = word.size();
        int start = 0, end = len-1;
        while(start < end)
        {
            if(word[start] != word[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        
        string ans = "";
        for(string word: words)
        {
            if(isPalindrome(word))
                return word;
        }
        return ans;
    }
};
