class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        int r = m - 1;
        int total = m + n - 2;

        // Calculate nCr
        for (int i = 1; i <= r; i++) {
            res = res * (total - r + i) / i;
        }

        return (int)res;
    }
};
