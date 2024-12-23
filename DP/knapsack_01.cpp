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
//g++ -std=c++11 knapasack_01.cpp && ./a.out

int knapsackRec(vector<int> val,vector<int> wt,int W,int n,vector<vector<int>> dp){//O(n*W)
    if((n==0) || (W==0)){
        return 0;
    } 

    if(dp[n][W] != -1){
        return dp[n][W];
    }   
    int itemWt=wt[n-1];
    int itemval=val[n-1];

    if(itemWt<=W){// valid wt
    //include
    int ans1= knapsackRec(val,wt,W-itemWt,n-1,dp)+itemval;

    int ans2= knapsackRec(val,wt,W,n-1,dp);

    dp[n][W]= max(ans1,ans2);
    }else{
        dp[n][W]= knapsackRec(val,wt,W,n-1,dp);
    }
    return dp[n][W]; 
}
int main() {
    // code here
    vector<int> val={15,14,10,45,30};
    vector<int> wt={2,5,1,3,4};
    int W=7;
    int n=5;

    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
    cout<<knapsackRec(val,wt,W,n,dp)<<endl;
    return 0;
}