#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>

using namespace std;
typedef long long int ll;

//Memoization
int countNoWays(int n,vector<int> &dp){

    if(n==1 || n==0){
        return 1;
    }

    if(dp[n]!=-1){
        return dp[n];
    }


    dp[n] = countNoWays(n-1,dp)+countNoWays(n-2,dp);

    return dp[n];
}

//tabulation
int countNoWaysTab(int n){

    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}

// vriation , 3 jumo also allowed
int countNoWaysTab_Variation(int n){

    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }

    return dp[n];
}


int main() {
    // code here
    int n=5;
    vector<int> dp(n+1,-1);
    //cout<<countNoWays(n,dp);
    cout<<countNoWaysTab_Variation(n);
    return 0;
}