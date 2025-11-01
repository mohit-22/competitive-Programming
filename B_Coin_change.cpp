// class Solution {
//   public:
//     int minCoins(vector<int> &coins, int sum) {
//         // code here
//         int n = coins.size();
        
//         // vector<vector<intt>>dp(n+1,vector<int>(sum+1,INT_MAX));
//          vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX));
//         for(int i=0 ; i<=n ; i++){
//             dp[i][0]=0;
//         }
//         for(int i=1 ; i<=n ; i++){
//             for(int j=1 ; j<=sum ; j++){
//                 if(coins[i-1]<=j){
//                     if (dp[i][j - coins[i - 1]] != INT_MAX)
//                         dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
//                     else
//                         dp[i][j] = dp[i - 1][j];
//                 }
//                 else dp[i][j] = dp[i-1][j];
//             }
//         }
        
//         if(dp[n][sum]!=INT_MAX) return dp[n][sum];
//         else return -1;
//     }
// };



class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
        
        // vector<vector<intt>>dp(n+1,vector<int>(sum+1,INT_MAX));
         vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX-1));
        for(int i=0 ; i<=n ; i++){
            dp[i][0]=0;
        }
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=sum ; j++){
                if(coins[i-1]<=j){
                    // if (dp[i][j - coins[i - 1]] != INT_MAX)
                        dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                    // else
                    //     dp[i][j] = dp[i - 1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        if(dp[n][sum]!=INT_MAX-1) return dp[n][sum];
        else return -1;
    }
};