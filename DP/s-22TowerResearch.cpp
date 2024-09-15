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
//https://docs.google.com/document/d/1OOC2Xko8f2ALqwrLF7UqM6U90jer26q5LErBgsIefxA/edit

int countNoWays(int b[],int n){
    vector<vector<int> > dp(n+1,vector<int>(2,0)); //equivalent to int dp[n+1][2]={{0}}

    //in 2-D Dp
    //0 for no backward jump
    //1 for 1 backward jump
    dp[1][0]=1; //no of ways to reach index 1 with 0 backward
    dp[2][0]=1;

    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][0];// single step jump with no backward jump

        if(b[i-2] == 2){
            dp[i][0]+=dp[i-2][0];// double step jump with no backward jump
        }

        dp[i][1]+=dp[i-1][1];//single step jump with 1 backward jump done already

        if(b[i-2]==2){
            dp[i][1]+=dp[i-2][1];//double step jump with 1 backward jump done already
        }

        if(b[i-3]==2 and b[i-2]==2){
            dp[i][1]+=dp[i-3][0];// reached at index i by just taking the backward jump 
        }
    }
    return dp[n][0] + dp[n][1];
}

int main() {
    // code here
    int n=5;
    int b[]={1,2,1,1,2};

    cout<<countNoWays(b,n);
    return 0;
}