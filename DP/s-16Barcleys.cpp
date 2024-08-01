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

int maxi(int a, int b, int c) {
    return max(a, max(b, c));
}
int dp[200005][4];
//https://www.desiqna.in/10567/barclays-sde-coding-oa-questions-and-solutions-set-8-2022-dp
int main() {
    // code here
    ll n;
    cin>>n;
    ll v; 
    cin>>v;
    ll easy[n+1];
    ll hard[n+1];
    easy[0]=0,hard[0]=0;
    for(int i=1;i<=n;i++){
        cin>>easy[i]>>hard[i];
    }
    int e=1,h=2,N=3;
    dp[1][e]=easy[1];
    dp[1][h]=hard[1];
    dp[1][N]=0;
    for(int i=2;i<=n;i++){
        dp[i][e]=easy[i]+maxi(dp[i-1][e],dp[i-1][h],dp[i-1][N]);
        dp[i][h]=hard[i]+dp[i-1][N];
        dp[i][N]=maxi(dp[i-1][e],dp[i-1][h],dp[i-1][N]);
    }
    cout<<maxi(dp[n][e],dp[n][h],dp[n][N]);
    return 0;
}