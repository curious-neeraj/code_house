// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int len = numbers.size();
        int start = 0, end = len - 1;
        int sum = 0;

        while(start < end)
        {
            sum = numbers[start] + numbers[end];
            if(sum == target)
                return {start+1, end+1};
            
            if(sum < target)
                start++;
            else 
                end--;
        }
        return {0, 0};
    }
};
