#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
//Q)https://docs.google.com/document/d/1sdC79EQT1WJindKKfyaHEB6plr-PePeC9lz23Xav6lk/edit
using namespace std;
// little difficulty is faced while understanding, good Q if needed to be revised from the video
int main() {
    // code here
    int n; cin>>n;
    int b[n+1]; 
    for(int i=1;i<=n;i++) cin>>b[i];
    int dp[n+1][5];
    for(auto it : dp) it=0;
    int forw=2;
    int back=1;
    dp[1][2] = b[1] ; 
    dp[1][1] = 100000000 ; 
    dp[2][2] = 100000000 ; 
    dp[2][1] = dp[1][2] + b[2] + b[3] ;
 
    for(int i=3;i<=n;i++){
        dp[i][forw]=b[i] + min(dp[i-2][forw],dp[i-2][back]);
        dp[i][back]=b[i] + b[i+1] +dp[i-1][forw];
    }
    cout<<min(dp[n][forw],min(dp[n-1][forw],dp[n-1][back]));
    return 0;
}