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
//Q) https://docs.google.com/document/d/1pWZ0d0npCSZg6qzn5AZzQ8-DW00UoLVV4gRSoy154G8/edit
int main() {
    // code here
    int n; cin>>n;

    // 1 based indexing 
    int arr[n+1];
    int dp[n+1];
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        dp[i]=0;
    }  
    dp[1]=arr[1];
    dp[2]= dp[1]+arr[2];
    dp[3]= dp[2]+arr[3];
    dp[4]=max(dp[1]+arr[4],dp[3]+arr[4]);
    dp[5]=max(dp[2]+arr[5],dp[4]+arr[5]);

    for(int i=6;i<=n;i++){
        dp[i]=max(dp[i-1]+arr[i],max(dp[i-3]+arr[i],dp[i-5]+arr[i])); // checking for jump from position behind 1,3,5
    }

    cout<<dp[n];

    return 0;
}