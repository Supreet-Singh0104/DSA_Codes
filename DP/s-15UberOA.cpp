#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
//https://www.desiqna.in/11154/uber-hard-dynamic-programming-coding-questions-solutions
using namespace std;
typedef long long int ll;
ll dp[100000+5][5][5];
ll maxi(ll a,ll b,ll c){
    return max(a,max(b,c));
}
ll maxi(ll a,ll b,ll c,ll d){
    return max(max(a,b),max(c,d));
}
int main() {
    // code here
    ll n; cin>>n;

    ll i=1; ll b[n+1]; ll d[n+1];
    b[0]=0;
    d[0]=0;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        cin>>d[i];
    }

    //best cases
    dp[1][1][1]=b[1];
    dp[1][1][2]=b[1];
    dp[1][2][1]=d[1];
    dp[1][2][2]=d[1];
    for(int i=2;i<=n;i++){
        dp[i][1][1]=b[i]+b[i-1]+max(dp[i-2][2][2],dp[i-2][2][1]);
        dp[i][1][2]=b[i]+d[i-1]+maxi(dp[i-2][1][1],dp[i-2][2][1],dp[i-2][1][2]);
        dp[i][2][1]=d[i]+b[i-1]+maxi(dp[i-2][2][1],dp[i-2][1][2],dp[i-2][2][2]);
        dp[i][2][2]=d[i]+d[i-1]+max(dp[i-2][1][2],dp[i-2][1][1]);
    }
    cout<<maxi(dp[n][1][1],dp[n][1][2],dp[n][2][2],dp[n][2][1]);


    return 0;
}