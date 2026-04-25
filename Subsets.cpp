class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, vector<int>& nums, vector<int>& temp) {
        result.push_back(temp);  // store current subset

        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);           // include
            backtrack(i + 1, nums, temp);      // explore
            temp.pop_back();                   // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(0, nums, temp);
        return result;
    }
};
