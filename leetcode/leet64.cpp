class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int dp[200][200];
            fill(&dp[0][0], &dp[0][0]+200*200, 1e9);
            // 00, 01 10, 02 11 20, 21 12, 22 
            dp[0][0] = grid[0][0];
            int m = grid.size();
            int n = grid[0].size();
            for(int i = 1; i <= m + n - 2; i++) {
                for(int j = 0; j <= i; j++) {
                    int row = j;
                    int col = i - j;
                    if(row >= m || col >= n) continue;
                    
                    if(col-1 >= 0)
                        dp[row][col] = min(dp[row][col], dp[row][col-1] + grid[row][col]);
                    if(row-1 >= 0)
                        dp[row][col] = min(dp[row][col], dp[row-1][col] + grid[row][col]);
                }
            }
            return dp[m-1][n-1];
        }
    };