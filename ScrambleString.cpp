class Solution {
public:
    unordered_map<string, bool> dp;

    bool solve(string s1, string s2) {
        if (s1 == s2) return true;

        string key = s1 + " " + s2;
        if (dp.find(key) != dp.end()) return dp[key];

        int n = s1.length();

        // Check frequency
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        for (int f : freq) {
            if (f != 0) return dp[key] = false;
        }

        // Try all splits
        for (int i = 1; i < n; i++) {
            // No swap
            if (solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i))) {
                return dp[key] = true;
            }

            // Swap
            if (solve(s1.substr(0, i), s2.substr(n - i)) &&
                solve(s1.substr(i), s2.substr(0, n - i))) {
                return dp[key] = true;
            }
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        return solve(s1, s2);
    }
};
