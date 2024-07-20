#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
// this is the soln for the follow up part
using namespace std;
//Q)https://docs.google.com/document/d/1diIi3RmKJiL8BypYXLR3Tp9m4PiK_FRNX0Uoy2loLW0/edit
int main() {
    // code here
    int n=5;

    int dp[n+1]; for(auto it : dp) it=0;

    dp[1]=0;

    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[i]=1+dp[i/2];
        }else{
            dp[i]=min(1+dp[i-1],2+dp[(i+1)/2]);
        }
    }
    cout<<dp[n];
    return 0;
}