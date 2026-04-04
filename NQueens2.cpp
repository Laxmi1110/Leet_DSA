class Solution {
public:
    int count = 0;

    void solve(int row, int n,
               vector<int>& col,
               vector<int>& diag1,
               vector<int>& diag2) {

        // Base case → found one valid solution
        if (row == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;

            /
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 1;

           
            solve(row + 1, n, col, diag1, diag2);

           
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 0;
        }
    }

    int totalNQueens(int n) {
        vector<int> col(n, 0), diag1(2*n, 0), diag2(2*n, 0);
        solve(0, n, col, diag1, diag2);
        return count;
    }
};
