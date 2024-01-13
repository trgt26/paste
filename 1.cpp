class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows+1, vector<int>(numRows+1, 0));
        vector<vector<int>> ans(numRows);
        
        for(int i=1; i <= numRows; i++) {
            for(int j=1; j<=i; j++) {
             if(j==1 or == numRows ) dp[i][j] = 1;
             else {
                 dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
             }   
             ans[i-1].push_back(dp[i][j]);
            }
        }
        return ans;
    }
};
