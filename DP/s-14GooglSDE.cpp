#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
//https://docs.google.com/document/d/1yykv6-Ox3lxOhWIdDi9lrSeWK7wpbI9avVQbCFkVTE4/edit
using namespace std;
typedef long long int ll;
ll dp[100005][2];
int main() {
    // code here
    ll n; cin>>n;
    ll aa[n+1];
    ll bb[n+1];
    for(int i=1;i<=n;i++){
        cin>>aa[i];
    }
    for(int i=1;i<=n;i++){
        cin>>bb[i];
    }
    int a=0;
    int b=1;
    dp[1][a]=aa[1];
    dp[1][b]=bb[1];


    for(int i=2;i<=n;i++){
        dp[i][a]=max(dp[i-1][a]+aa[i],dp[i-2][b]+aa[i]);
        dp[i][b]=max(dp[i-1][b]+bb[i],dp[i-2][a]+bb[i]);
    }
    cout<<dp[n][0]<<" "<<dp[n][1];
    return 0;
}