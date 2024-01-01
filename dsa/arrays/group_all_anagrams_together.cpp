// Time Complexity - O(n) {Since len(string) <= 100}
// Space Complexity - O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> mp;

        for(string str: strs)
        {
            string original = str;
            sort(str.begin(), str.end());
            mp[str].push_back(original);
        }

        for(auto element: mp)
            answer.push_back(element.second);

        return answer;
    }
};
