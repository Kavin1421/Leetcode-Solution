constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int checkRecord(int n) {
        using ll = long long;
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(3)));

        // base case
        dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = 1;

        for (int i = 1; i < n; ++i) {
            // A
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            // L
            dp[i][0][1] = dp[i - 1][0][0];
            dp[i][0][2] = dp[i - 1][0][1];
            dp[i][1][1] = dp[i - 1][1][0];
            dp[i][1][2] = dp[i - 1][1][1];
            // P
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            dp[i][1][0] = (dp[i][1][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
        }

        ll ans = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                ans = (ans + dp[n - 1][j][k]) % MOD;
            }
        }
        return ans;
    }
};