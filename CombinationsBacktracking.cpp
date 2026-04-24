class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, int n, int k, vector<int>& temp) {
        // Base case
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }

        // Loop through remaining numbers
        for (int i = start; i <= n; i++) {
            temp.push_back(i);              // choose
            backtrack(i + 1, n, k, temp);  // explore
            temp.pop_back();               // backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrack(1, n, k, temp);
        return result;
    }
};
