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
int dp[100005][3];
int main() {
    // code here
    int n;
    cin>>n;
    int a[n+1];
    
    for(auto it : a) it=0;
     for(int i=1;i<=n+1;i++){
        cin>>a[i];
    }

    // taking 1 for odd 
    // taking 2 for even 

    if(a[1]%2==0){
        // sum is even till 1 st position
        dp[1][2]=1;
    }else{
        dp[1][1]=1;
    }

    for(int i=2;i<=n;i++){
        if(a[i]%2==0){
            dp[i][2]=dp[i-1][2]+dp[i-2][2];
            dp[i][1]=dp[i-1][1]+dp[i-2][1];
        }else{
            dp[i][2]=dp[i-1][1]+dp[i-2][1];
            dp[i][1]=dp[i-1][2]+dp[i-2][2];
        }
    }

    cout<<dp[n][1]<<" "<<dp[n][2];
    return 0;
}