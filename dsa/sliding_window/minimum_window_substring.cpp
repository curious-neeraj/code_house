// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> map(128,0);
        for (char c : t) 
            map[c]++;

        int t_size = t.size(), s_size = s.size(), begin = 0, end = 0;
        int window = INT_MAX, head = 0;
        while (end < s_size)
        {
            if (map[s[end++]]-- > 0)
                t_size--;
            
            while (t_size == 0) 
            {
                if (end - begin < window) 
                {
                    head = begin;
                    window = end - head;
                }
                if (map[s[begin++]]++ == 0)
                    t_size++;
            }
        }
        return window == INT_MAX ? "" : s.substr(head, window);
    }
};
