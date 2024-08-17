#include <iostream>
#include <vector>
using namespace std;
//https://docs.google.com/document/d/1cM6ykw9dvoXVawGSINq_OezgivdO0kKfsWA27XoMLIo/edit
// as of know the main q which will be solved by 3D(https://ideone.com/bXq1M7) DP is not solved , only the sub part which is solved by 2d DP
int main() {
    int n;
    cin >> n;

    // Handle edge cases where n is very small
    if (n == 0) {
        cout << 1 << endl; // dp[0][0] = 1, dp[0][1] = 0, dp[0][2] = 0
        return 0;
    }

    // Initialize the dp array with size (n+1) x 3
    vector<vector<long long > > dp(n+1, vector<long long>(3, 0));
    
    // Base cases
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        if (i-1 >= 0) dp[i][0] += dp[i-1][0];
        if (i-2 >= 0) dp[i][0] += dp[i-2][0];
        if (i-6 >= 0) dp[i][0] += dp[i-6][0];
        
        if (i-1 >= 0) dp[i][1] += dp[i-1][1];
        if (i-2 >= 0) dp[i][1] += dp[i-2][1];
        if (i-4 >= 0) dp[i][1] += dp[i-4][0];
        if (i-6 >= 0) dp[i][1] += dp[i-6][1];
        
        if (i-1 >= 0) dp[i][2] += dp[i-1][2];
        if (i-2 >= 0) dp[i][2] += dp[i-2][2];
        if (i-4 >= 0) dp[i][2] += dp[i-4][1];
        if (i-6 >= 0) dp[i][2] += dp[i-6][2];
    }

    // The final answer
    long long result = dp[n][0] + dp[n][1] + dp[n][2];
    cout << result << endl;

    return 0;
}
