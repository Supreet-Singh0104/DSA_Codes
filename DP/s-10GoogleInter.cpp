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

int main() {
    // code here
    int x,z,b,y;
    int n; cin>>n;
    cin>>y>>x>>z>>b;
    int dp[n+1];
    for(auto it : dp) it=0;
    
for(int i=2;i<=n;i++)
{
    int v1=dp[i-1]+y;
    int v2=1e8;
    int v3=1e8;
    int v4=1e8;
    if(i%3==0) v2=dp[i/3]+z;
    if(i%7==0) v3=dp[i/7]+x;
    if(i%5==0) v4=dp[i/5]+b;

    dp[i]=min(v1,min(v2,min(v3,v4)));
}
    cout<<dp[n];
    return 0;
}