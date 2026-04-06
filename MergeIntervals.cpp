class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Step 1: Sort intervals
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        // Step 2: Traverse
        for (auto it : intervals) {
            
            // If answer is empty OR no overlap
            if (ans.empty() || ans.back()[1] < it[0]) {
                ans.push_back(it);
            } 
            else {
                // Overlap → merge
                ans.back()[1] = max(ans.back()[1], it[1]);
            }
        }
        
        return ans;
    }
};
